/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointOfView.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:37:16 by echevali          #+#    #+#             */
/*   Updated: 2024/09/22 23:06:39 by pchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_num(char c);
void	fill_ind_matrix(char *argv[], char ind_matrix[4][4]);
void	ft_left_to_right(char col_row[4][4], char grille[4][4], int j);
void	ft_up_to_down(char col_row[4][4], char grille[4][4], int j);
void	ft_right_to_left(char col_row[4][4], char grille[4][4], int j);
void ft_down_to_up(char col_row[4][4], char grille [4][4], int j);
void	ft_aff_grille(char grille[4][4]);
int	ft_mult_4_1(char col_row[4][4], int one, int four, int j, int x);
int ft_conditions_4_1(char col_row[4][4], int j, int x);
int	check_sup_five_equal_two(char c_row1, char c_row2);
int	check_corner_one(char ind_matrix[4][4]);
void	diff_zero(int *fothtwon, int i);
void	indice_one(int position, int *fothtwon);
void	indice_two(int position, int *fothtwon);
void	indice_three(int position, int *fothtwon);
void	indice_four(int position, int *fothtwon);
int ft_impossibilites(char col_row[4][4]);

/*======================================================================*/

/*======================================================================*/

/*======================================================================*/

/*======================================================================*/

void possible(char indice, int position, int *fothtwon)
{
	if (indice == '1')
		indice_one(position, fothtwon);
	else if (indice == '2')
		indice_two(position, fothtwon);
	else if (indice == '3')
		indice_three(position, fothtwon);
	else if (indice == '4')
		indice_four(position, fothtwon);
}

/*======================================================================*/

void ft_possibilities_in_case(char col_row[4][4], int possible_matrix[4][4][4])
{
	int		fothtwon[4];
	int		j;
	int		x;

	x = 0;
	while (x < 4)
	{
		j = 0;
		while (j < 4)
		{
			fothtwon[0] = 2;
			fothtwon[1] = 2;
			fothtwon[2] = 2;
			fothtwon[3] = 2;
			possible(col_row[0][x], j, fothtwon);
			possible(col_row[1][x], 4 - j - 1, fothtwon);
			possible(col_row[2][j], x, fothtwon);
			possible(col_row[3][j], 4 - x - 1, fothtwon);
			possible_matrix[x][j][0] = fothtwon[0];
			possible_matrix[x][j][1] = fothtwon[1];
			possible_matrix[x][j][2] = fothtwon[2];
			possible_matrix[x][j][3] = fothtwon[3];
			j++;
		}
		x++;
	}
}

/*======================================================================*/

int		count_and_check_arg(char *argv[])
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
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

/*======================================================================*/

int		ft_init_map(char *argv[], char col_row[4][4])
{
	//compte et verifie les indices
	if (count_and_check_arg(argv) == 0)
		return (0);
	//remplie la matrice d'indice
	fill_ind_matrix(argv, col_row);
	//conditions d'impossibilite
	if (ft_impossibilites(col_row) == 0)
		return (0);
	return (1);
}

/*======================================================================*/

void	fill_max_possible(int possible_matrix[4][4][4], char grille[4][4])
{
	int	flag;
	int	x;
	int	j;

	x = 0;
	while (x < 4)
	{
		j = 0;
		while (j < 4)
		{
			flag = 3;
			while (flag >= 0)
			{
				if (possible_matrix[x][j][flag] == 1)
					grille[x][j] = 4 - flag + 48;
				flag--;
			}
			j++;
		}
		x++;
	}
}
// if (check_corner_one(col_row) == 0)
// 			return (0);
// 		x = 0;
// 		while (x < 4)
// 		{
// 			j = 0;
// 			one = 0;
// 			four = 0;
// 			while (j < 4)
// 			{
// 				//indices d'une meme ligne/colonne ne peut pas etre superieur a 5 ou egal a 2
// 				if (check_sup_five_equal_two(col_row[x][j], col_row[x + 1][j]) == 0)
// 					return (0);
// 				//cas special de 4 et 1
// 				ft_conditions_4_1(col_row, j, x);
// 				ft_mult_4_1(col_row, one, four, j, x);
// 				j++;
// 			}
// 			x += 2;
// 		}
// //gauche a droite 4
// 		if (col_row[2][j] == '4')
// 		{
// 			grille[0][j] = '1';
// 			grille[1][j] = '2';
// 			grille[2][j] = '3';
// 			grille[3][j] = '4';
// 		}
// 		//1
// 		else if (col_row[2][j] == '1')
// 			grille[0][j] = '4';
// 		//haut en bas 4
// 		if (col_row[0][j] == '4')
// 		{
// 			grille[j][0] = '1';
// 			grille[j][1] = '2';
// 			grille[j][2] = '3';
// 			grille[j][3] = '4';
// 		}
// 		//1
// 		else if (col_row[0][j] == '1')
// 			grille[j][0] = '4';
// 		//droite a gauche 4
// 		if (col_row[3][j] == '4')
// 		{
// 			grille[0][j] = '4';
// 			grille[1][j] = '3';
// 			grille[2][j] = '2';
// 			grille[3][j] = '1';
// 		}
// 		//1
// 		else if (col_row[3][j] == '1')
// 			grille[3][j] = '4';
// 		//bas en haut 4
// 		if (col_row[1][j] == '4')
// 		{
// 			grille[j][0] = '4';
// 			grille[j][1] = '3';
// 			grille[j][2] = '2';
// 			grille[j][3] = '1';
// 		}
// 		//1
// 		else if (col_row[1][j] == '1')
// 			grille[j][3] = '4';
