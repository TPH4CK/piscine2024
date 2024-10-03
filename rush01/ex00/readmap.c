/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmichel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:17:13 by thmichel          #+#    #+#             */
/*   Updated: 2024/09/22 23:17:15 by thmichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*======================================================================*/

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

/*======================================================================*/

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

/*======================================================================*/

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
