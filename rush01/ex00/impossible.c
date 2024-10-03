/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impossible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmichel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:27:22 by thmichel          #+#    #+#             */
/*   Updated: 2024/09/22 23:27:24 by thmichel         ###   ########.fr       */
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
			if (ft_conditions_4_1(col_row, j, x) == 0)
				return (0);
			if (ft_mult_4_1(col_row, one, four, j, x) == 0)
				return (0);
			j++;
			}
			x += 2;
		}
	return (1);
}

