/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmichel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:20:54 by thmichel          #+#    #+#             */
/*   Updated: 2024/09/22 23:20:55 by thmichel         ###   ########.fr       */
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

void	ft_aff_grille(char grille[4][4])
{
	int	j;
	int	x;

	j = 0;
	while (j < 4)
	{
		x = 0;
		while (x < 4)
		{
			write(1, &grille[x][j], 1);
			if (x < 3)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		j++;
	}
}

/*======================================================================*/

int	ft_mult_4_1(char col_row[4][4], int one, int four, int j, int x)
{
	if (col_row[x][j] == '1')
		one++;
	if (one > 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (col_row[x][j] == '4')
		four++;
	if (four > 1)
	{
		write(2, "Error\n", 6);
		return(0);
	}
	return(1);
}

/*======================================================================*/

int ft_conditions_4_1(char col_row[4][4], int j, int x)
{
	if ((col_row[x + 1][j] - 48 == 4 && col_row[x][j] - 48 != 1)
		|| (col_row[x][j] - 48 == 4 && col_row[x + 1][j] - 48 != 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

/*======================================================================*/

int	check_sup_five_equal_two(char c_row1, char c_row2)
{
	if (((c_row1 - 48 + c_row2)- 48 > 5) 
		|| ((c_row1 - 48 + c_row2 - 48) == 2))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

/*======================================================================*/

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
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
