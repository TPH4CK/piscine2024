/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01_Erwan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:06:08 by pchateau          #+#    #+#             */
/*   Updated: 2024/09/22 23:09:02 by pchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		is_num(char c);
int		is_num(char c);
void	ft_left_to_right(char col_row[4][4], char grille[4][4], int j);
void	ft_up_to_down(char col_row[4][4], char grille[4][4], int j);
void	ft_right_to_left(char col_row[4][4], char grille[4][4], int j);
void	ft_down_to_up(char col_row[4][4], char grille[4][4], int j);
void	ft_aff_grille(char grille[4][4]);
int		ft_mult_4_1(char col_row[4][4], int one, int four, int j, int x);
int		ft_conditions_4_1(char col_row[4][4], int j, int x);
int		ft_impossibilites(char col_row[4][4]);
int		check_corner_one(char ind_matrix[4][4]);
int		check_sup_five_equal_two(char c_row1, char c_row2);
void	diff_zero(int *fothtwon, int i);
void	indice_one(int position, int *fothtwon);
void	indice_two(int position, int *fothtwon);
void	indice_three(int position, int *fothtwon);
void	indice_four(int position, int *fothtwon);
void	possible(char indice, int position, int *fothtwon);
void	ft_possibilities_in_case(char col_row[4][4], int possible_matrix[4][4][4]);
int		count_and_check_arg(char *argv[]);
int		ft_init_map(char *argv[], char col_row[4][4]);
void    fill_max_possible(int possible_matrix[4][4][4], char grille[4][4]);

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

int	main(int argc, char *argv[])
{
	int		j;
	char	col_row[4][4];
	char	grille[4][4];
	int		possible_matrix[4][4][4];

	if (argc == 2)
	{
		j = 0;
		if (ft_init_map(argv, col_row) == 0)
			return(0);
		j = 0;
		while (j < 4)
		{
			ft_left_to_right(col_row, grille, j);
			ft_up_to_down(col_row, grille, j);
			ft_right_to_left(col_row, grille, j);
			ft_down_to_up(col_row, grille, j);
			j++;
		}
		ft_possibilities_in_case(col_row, possible_matrix);
		fill_max_possible(possible_matrix, grille);
		ft_aff_grille(grille);
	}
	return (0);
}
