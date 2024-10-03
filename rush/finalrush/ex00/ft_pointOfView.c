/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointOfView.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:37:16 by echevali          #+#    #+#             */
/*   Updated: 2024/09/28 14:29:42 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_num(char c);
void	fill_ind_matrix(char *argv[], char ind_matrix[4][4]);

void	ft_left_to_right(char col_row[4][4], char grille[4][4], int j)
{
	if (col_row[2][j] == '4')
	{
		grille[0][j] = '1';
		grille[1][j] = '2';
		grille[2][j] = '3';
		grille[3][j] = '4';
	}
	else if (col_row[2][j] == '1')
	{
		grille[0][j] = '4';
	}
}

void	ft_up_to_down(char col_row[4][4], char grille[4][4], int j)
{
	if (col_row[0][j] == '4')
	{
		grille[j][0] = '1';
		grille[j][1] = '2';
		grille[j][2] = '3';
		grille[j][3] = '4';
	}
	else if (col_row[0][j] == '1')
	{
		grille[j][0] = '4';
	}
}

void	ft_right_to_left(char col_row[4][4], char grille[4][4], int j)
{
	if (col_row[1][j] == '4')
	{
		grille[j][0] = '4';
		grille[j][1] = '3';
		grille[j][2] = '2';
		grille[j][3] = '1';
	}
	else if (col_row[1][j] == '1')
	{
		grille[j][3] = '4';
	}
}

void ft_down_to_up(char col_row[4][4], char grille [4][4], int j)
{
	if (col_row[1][j] == '4')
	{
		grille[j][0] = '4';
		grille[j][1] = '3';
		grille[j][2] = '2';
		grille[j][3] = '1';
	}
	else if (col_row[1][j] == '1')
	{
		grille[j][3] = '4';
	}
}

void	ft_aff_grille(char grille[4][4], int j, int x)
{
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
}

int	ft_mult_4_1(char col_row[4][4], int one, int four, int j, int x)
{
	if (col_row[x][j] == '1')
		one++;
	if (one > 1)
	{
		write(2, "Error: one", 10);
		return (0);
	}
	if (col_row[x][j] == '4')
		four++;
	if (four > 1)
	{
		write(2, "Error: four", 11);
		return(0);
	}
	return(0);
}

int ft_conditions_4_1(char col_row[4][4], int j, int x)
{
	if ((col_row[x + 1][j] - 48 == 4 && col_row[x][j] - 48 != 1)
		|| (col_row[x][j] - 48 == 4 && col_row[x + 1][j] - 48 != 1))
	{
		write(2, "Error: impossible 4et1", 22);
		return (0);
	}
	return (0);
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

int	check_corner_one(char ind_matrix[4][4])
{
	if ((ind_matrix[0][0] == '1' && ind_matrix[2][0] != '1')
		|| (ind_matrix[2][0] == '1' && ind_matrix[0][0] != '1')
		|| (ind_matrix[0][3] == '1' && ind_matrix[3][0] != '1')
		|| (ind_matrix[3][0] == '1' && ind_matrix[0][3] != '1')
		|| (ind_matrix[1][0] == '1' && ind_matrix[2][3] != '1')
		|| (ind_matrix[2][3] == '1' && ind_matrix[1][0] != '1')
		|| (ind_matrix[1][3] == '1' && ind_matrix[3][3] != '1')
		|| (ind_matrix[3][3] == '1' && ind_matrix[1][3] != '1'))
	{
		write(2, "Error: corner 1:1", 17);
		return (0);
	}
	return (1);
}

/*fonction principale a mettre dans le dossier principal
		check_corner_one/check_sup_five_equal_two/ft_conditions_4_1/ft_mult_4_1*/
int ft_impossibilites(char col_row[4][4])
{
	int j;
	int x;
	int one;
	int four;
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
			ft_conditions_4_1(col_row, j, x);
			ft_mult_4_1(col_row, one, four, j, x);
			j++;
			}
			x += 2;
		}
	return (0);
}


/*fonction tertiaire a mettre dans le dossier tertiaire*/
void	diff_zero(int *fothtwon, int i)
{
	if (fothtwon[i] != 0)
		fothtwon[i] = 1;
}

/*fonction secondaire a mettre dans le dossier secondaire.
		diff_zero*/
void	indice_one(int position, int *fothtwon)
{
	if (position == 0)
	{
		diff_zero(fothtwon, 0);
		fothtwon[1] = 0;
		fothtwon[2] = 0;
		fothtwon[3] = 0;
	}
	else if (position == 1 || position == 2 || position == 3)
	{
		fothtwon[0] = 0;
		diff_zero(fothtwon, 1);
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
}

/*fonction secondaire a mettre dans le dossier secondaire.
		diff_zero*/
void	indice_two(int position, int *fothtwon)
{
	if (position == 0)
	{
		fothtwon[0] = 0;
		diff_zero(fothtwon, 1);
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
	else if (position == 1)
	{
		diff_zero(fothtwon, 0);
		fothtwon[1] = 0;
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
	else if (position == 2 || position == 3)
	{
		diff_zero(fothtwon, 0);
		diff_zero(fothtwon, 1);
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
}


/*fonction secondaire a mettre dans le dossier secondaire.
		diff_zero*/
void	indice_three(int position, int *fothtwon)
{
	if (position == 0)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 0;
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
	else if (position == 1)
	{
		fothtwon[0] = 0;
		diff_zero(fothtwon, 1);
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
	else if (position == 2 || position == 3)
	{
		diff_zero(fothtwon, 0);
		diff_zero(fothtwon, 1);
		diff_zero(fothtwon, 2);
		diff_zero(fothtwon, 3);
	}
}

/*fonction secondaire a mettre dans le dossier secondaire.
		diff_zero*/
void	indice_four(int position, int *fothtwon)
{
	if (position == 0)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 0;
		fothtwon[2] = 0;
		diff_zero(fothtwon, 3);
	}
	else if (position == 1)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 0;
		diff_zero(fothtwon, 2);
		fothtwon[3] = 0;
	}
	else if (position == 2)
	{
		fothtwon[0] = 0;
		diff_zero(fothtwon, 1);
		fothtwon[2] = 0;
		fothtwon[3] = 0;
	}
	else if (position == 3)
	{
		diff_zero(fothtwon, 0);
		fothtwon[1] = 0;
		fothtwon[2] = 0;
		fothtwon[3] = 0;
	}
}

/*fonction principale a mettre en dossier principal.
		indice_one/two/three/four*/
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


void ft_possibilities_in_case(char col_row[4][4], int j, int x)
{
	int		fothtwon[4];
	char	indice_up;
	char	indice_down;
	char	indice_left;
	char	indice_right;

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
			indice_up = col_row[0][x];
			possible(indice_up, j, fothtwon);
			indice_down = col_row[1][x];
			possible(indice_down, 4 - j - 1, fothtwon);
			indice_left = col_row[2][j];
			possible(indice_left, x, fothtwon);
			indice_right = col_row[3][j];
			possible(indice_right, 4 - x - 1, fothtwon);
			j++;
		}
		x++;
	}
}

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
		write(2, "Error indices", 13);
		return (0);
	}
	return (1);
}

int		ft_init_map(char *argv[], char col_row[4][4])
{
	//compte et verifie les indices
	if (count_and_check_arg(argv) == 0)
		return (0);
	//remplie la matrice d'indice
	fill_ind_matrix(argv, col_row);
	//conditions d'impossibilite
	ft_impossibilites(col_row);
	return (0);
}
