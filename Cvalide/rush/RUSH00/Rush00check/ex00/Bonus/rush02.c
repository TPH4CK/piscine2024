/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:32:51 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 13:55:09 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	rush(int x, int y)
{
	int	x_limit;
	int	y_limit;

	x_limit = x;
	y_limit = y;
	while (y > 0)
	{
		while (x > 0)
		{
			if ((x == x_limit && y == y_limit) || (x == 1 && y == y_limit))
				ft_putchar('A');
			else if ((x == x_limit && y == 1) || (x == 1 && y == 1))
				ft_putchar('C');
			else if (y == y_limit || y == 1)
				ft_putchar('B');
			else if (x == x_limit || x == 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			x--;
		}
		ft_putchar('\n');
		x = x_limit;
		y--;
	}
}

void	rush(int x, int y);

int	main(void)
{
	rush(1, 4);
	return (0);
}