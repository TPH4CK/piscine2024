/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:46:38 by tle-pape          #+#    #+#             */
/*   Updated: 2024/09/15 16:55:37 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
/*{
	write(1, &c, 1);
}*/

void	check(int x, int y, int count_x, int count_y)
{
	if (count_x == 1 && (y == count_y || count_y == 1))
		ft_putchar('A');
	else if (x == count_x && (y == count_y || count_y == 1))
		ft_putchar('C');
	else if (y == count_y || count_y == 1 || x == count_x || count_x == 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	count_x;
	int	count_y;

	count_x = 1;
	count_y = 1;
	if (x != 0 && y != 0)
	{
		while (count_y <= y)
		{
			count_x = 1;
			while (count_x <= x)
			{
				check(x, y, count_x, count_y);
				count_x++;
			}
			write(1, "\n", 1);
			count_y++;
		}
	}
}

/*int	main(void)
{
	int	c;
	int	l;

	c = 5;
	l = 1;

	rush(c, l);
}*/
