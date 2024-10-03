/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:54:43 by echevali          #+#    #+#             */
/*   Updated: 2024/10/01 12:12:05 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aff_comb(char str[4])
{
	write(1, &str[0], 2);
	write(1, " ", 1);
	write(1, &str[2], 2);
}

void	comb(char str[4])
{
	int	i;
	int	j;

	i = (str[0] - 48) * 10 + (str[1] - 48);
	j = (str[2] - 48) * 10 + (str[3] - 48);
	if (i == 98 && j == 99)
		aff_comb(str);
	else if (i < j)
	{
		aff_comb(str);
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int		tmp;
	int		i;
	char	str[4];
	int		combi;

	combi = 0;
	while (combi <= 9899)
	{
		i = 3;
		tmp = combi;
		while (i >= 0)
		{
			str[i] = (tmp % 10) + 48;
			tmp /= 10;
			i--;
		}
		comb(str);
		combi++;
	}
}

// int main()
// {
// 	ft_print_comb2();
// 	return (0);
// }