/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:04:10 by echevali          #+#    #+#             */
/*   Updated: 2024/09/15 14:57:08 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	x_limit;
	int	y_limit;

	y_limit = y;
	x_limit = x;
	while (y > 0)
	{
		while (x > 0)
		{
			if ((x == x_limit && y == y_limit) || (x == 1 && y == 1))
				ft_putchar('A');
			else if ((x == 1 && y == y_limit) || (x == x_limit && y == 1))
				ft_putchar('C');
			else if ((y == y_limit) || (y == 1) || (x == x_limit) || (x == 1))
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

int	main(void)
{
	rush(5, 5);
	return (0);
}
