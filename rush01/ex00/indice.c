/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchateau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:27:29 by pchateau          #+#    #+#             */
/*   Updated: 2024/09/22 13:22:25 by pchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ajouter des conditions pour ne pas mettre 1 a un 0*/
void	indice_one(int position, int *fothtwon)
{
	if (position == 0)
	{	
		fothtwon[0] = 1;
		fothtwon[1] = 0;
		fothtwon[2] = 0;
		fothtwon[3] = 0;
	}	
	else if (position == 1 || position == 2 || position == 3)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 1;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
}

void	indice_two(int position, int *fothtwon)
{
	if (position == 0)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 1;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
	else if (position == 1)
	{
		fothtwon[0] = 1;
		fothtwon[1] = 0;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
	else if (position == 2 || position == 3)
	{
		fothtwon[0] = 1;
		fothtwon[1] = 1;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
}

void	indice_three(int position, int *fothtwon)
{
	if (position == 0)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 0;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
	else if (position == 1)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 1;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
	else if (position == 2 || position == 3)
	{
		fothtwon[0] = 1;
		fothtwon[1] = 1;
		fothtwon[2] = 1;
		fothtwon[3] = 1;
	}
}

void	indice_four(int position, int *fothtwon)
{
	if (position == 0)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 0;
		fothtwon[2] = 0;
		fothtwon[3] = 1;
	}
	else if (position == 1)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 0;
		fothtwon[2] = 1;
		fothtwon[3] = 0;
	}
	else if (position == 2)
	{
		fothtwon[0] = 0;
		fothtwon[1] = 1;
		fothtwon[2] = 0;
		fothtwon[3] = 0;
	}
	else if (position == 3)
	{
		fothtwon[0] = 1;
		fothtwon[1] = 0;
		fothtwon[2] = 0;
		fothtwon[3] = 0;
	}
}

int possible(char indice, int position, int *fothtwon)
{
	//implementer les fothtwon
	if (indice == '1')
		indice_one(position, fothtwon);
	else if (indice == '2')
		indice_two(position, fothtwon);
	else if (indice == '3')
		indice_three(position, fothtwon);
	else if (indice == '4')
		indice_four(position, fothtwon);
}

//check possibilite dans la case
int *fothtwon;

x = 0;
while (x < 4)
{
	j = 0;
	fothtwon[0] = 2;
	fothtwon[1] = 2;
	fothtwon[2] = 2;
	fothtwon[3] = 2;
	while (j < 4)
	{
		indice_up = col_row[0][x];
		possible(indice_up, x, fothtwon);
		indice_down = col_row[1][x];
		possible(indice_down, x, fothtwon);
		indice_left = col_row[2][j];
		possible(indice_left, j, fothtwon);
		indice_right = col_row[3][j];
		possible(indice_right, j, fothtwon);
		j++;
	}
	x++;
}
