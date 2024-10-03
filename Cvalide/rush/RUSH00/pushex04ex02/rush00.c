/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:18:57 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/09/16 12:52:55 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
				ft_putchar('o');
			else if ((x == x_limit && y == 1) || (x == 1 && y == 1))
				ft_putchar('o');
			else if (y == y_limit || y == 1)
				ft_putchar('-');
			else if (x == x_limit || x == 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			x--;
		}
		ft_putchar('\n');
		x = x_limit;
		y--;
	}
}
