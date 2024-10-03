/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_possible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmichel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:25:15 by thmichel          #+#    #+#             */
/*   Updated: 2024/09/22 23:25:17 by thmichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	diff_zero(int *fothtwon, int i)
{
	if (fothtwon[i] != 0)
		fothtwon[i] = 1;
}

/*======================================================================*/

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

/*======================================================================*/

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

/*======================================================================*/

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

/*======================================================================*/

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

