/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchateau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:06:08 by pchateau          #+#    #+#             */
/*   Updated: 2024/09/22 11:23:04 by pchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_num(char c);

int	count_and_check_arg(char *argv[])
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	//compte les indices sur les cotes
	while (argv[1][i])
	{
		if (is_num(argv[1][i]))
			count++;
		i++;
	}
	printf("%d\n", count);
	//check si la grille est valide
	if (count % 4 != 0)
	{
		write(2, "Error indices", 13);
		return (0);
	}
	return (1);
}

void	fill_ind_matrix(char *argv[], char ind_matrix[4][4])
{
	int	argv_i;
	int	row_i;
	int	row;

	//ajoute les indices dans une matrice
	argv_i = 0;
	row_i = 0;
	row = 0;
	while (argv[1][argv_i])
	{
		if (row_i >= 4)
		{
			row_i = 0;
			row++;
		}
		if (is_num(argv[1][argv_i]))
			ind_matrix[row][row_i++] = argv[1][argv_i];
		argv_i++;
	}
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_corner_one(char ind_matrix[4][4])
{
	if ((ind_matrix[0][0] == '1' && ind_matrix[2][0] != '1') //coin superieur gauche
		|| (ind_matrix[2][0] == '1' && ind_matrix[0][0] != '1')
		|| (ind_matrix[0][3] == '1' && ind_matrix[3][0] != '1') //coin superieur droit
		|| (ind_matrix[3][0] == '1' && ind_matrix[0][3] != '1')
		|| (ind_matrix[1][0] == '1' && ind_matrix[2][3] != '1') //coin inferieur gauche
		|| (ind_matrix[2][3] == '1' && ind_matrix[1][0] != '1')
		|| (ind_matrix[1][3] == '1' && ind_matrix[3][3] != '1') //coin inferieur droit
		|| (ind_matrix[3][3] == '1' && ind_matrix[1][3] != '1'))
	{
		write(2, "Error: corner 1:1", 17);
		return (0);
	}
	return (1);
}

int	check_sup_five_equal_two(char c_row1, char c_row2)
{
	if (((c_row1 - 48 + c_row2)- 48 > 5) 
		|| ((c_row1 - 48 + c_row2 - 48) == 2))
	{
		write(2, "Error: impossible sup5egal2", 27);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		j;
	int		x;
	char	col_row[4][4];
	int		one;
	int		four;

	if (argc == 2)
	{
		//compte et verifie les indices
		if (count_and_check_arg(argv) == 0)
			return (0);
		//remplie la matrice d'indice
		fill_ind_matrix(argv, col_row);
		//conditions d'impossibilite
		if (check_corner_one(col_row) == 0)
			return (0);
		x = 0;
		while (x < 4)
		{
			j = 0;
			one = 0;
			four = 0;
			while (j < 4)
			{
				//indices d'une meme ligne/colonne ne peut pas etre superieur a 5 ou egal a 2
				if (check_sup_five_equal_two(col_row[x][j], col_row[x + 1][j]) == 0)
					return (0);
				//cas special de 4 et 1
				else if ((col_row[x + 1][j] - 48 == 4 && col_row[x][j] - 48 != 1)
						|| (col_row[x][j] - 48 == 4 && col_row[x + 1][j] - 48 != 1))
				{
					write(2, "Error: impossible 4et1", 22);
					return (0);
				}
				//plusieurs 1
				if (col_row[x][j] == '1')
					one++;
				if (one > 1)
				{
					write(2, "Error: one", 10);
					return (0);
				}
				//plusieurs 4
				if (col_row[x][j] == '4')
					four++;
				if (four > 1)
				{
					write(2, "Error: four", 11);
					return(0);
				}
				j++;
			}
			x += 2;
		}
		//print col_row
		x = 0;
		while (x < 4)
		{
			j = 0;
			while (j < 4)
			{
				printf("col[%d][%d] = %c\n", x, j, col_row[x][j]);
				j++;
			}
			x++;
		}
	}
	//creation de la grille de jeu(matrice)
	int	grille[4][4];
	//preremplissage des indices 1 et 4
	j = 0;
	while (j < 4)
	{
		//gauche a droite 4
		if (col_row[2][j] == '4')
		{
			grille[0][j] = '1';
			grille[1][j] = '2';
			grille[2][j] = '3';
			grille[3][j] = '4';
		}
		//1
		else if (col_row[2][j] == '1')
			grille[0][j] = '4';
		//haut en bas 4
		if (col_row[0][j] == '4')
		{
			grille[j][0] = '1';
			grille[j][1] = '2';
			grille[j][2] = '3';
			grille[j][3] = '4';
		}
		//1
		else if (col_row[0][j] == '1')
			grille[j][0] = '4';
		//droite a gauche 4
		if (col_row[3][j] == '4')
		{
			grille[0][j] = '4';
			grille[1][j] = '3';
			grille[2][j] = '2';
			grille[3][j] = '1';
		}
		//1
		else if (col_row[3][j] == '1')
			grille[3][j] = '4';
		//bas en haut 4
		if (col_row[1][j] == '4')
		{
			grille[j][0] = '4';
			grille[j][1] = '3';
			grille[j][2] = '2';
			grille[j][3] = '1';
		}
		//1
		else if (col_row[1][j] == '1')
			grille[j][3] = '4';
		j++;
	}
	//affichage grille
	j = 0;
	while (j < 4)
	{
		x = 0;
		while (x < 4)
		{
			write(1, &grille[x][j], 1);
			if (x < 3)
				write(1, "|", 1);
			x++;
		}
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
