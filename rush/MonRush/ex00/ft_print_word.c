/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:10:49 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 19:31:51 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*ft_create_decade(char *str)
{
	char	*decade;

	decade = (char *)malloc((2 + 1) * sizeof(char));
	decade[0] = str[0];
	decade[1] = '0';
	decade[2] = '\0';
	return (decade);
}

void	ft_print_decade(char *str, char *buf, int str_len, int z)
{
	if (str_len % 3 == 1)
	{
		if (str[0 + z] == '1' && str[1 + z] >= '1' && str[1 + z] <= '9')
		{
			ft_putstr(ft_find_first_decade(str, buf), 0);
			write(1, "\n", 1);
		}
		else
		{
			ft_putstr(ft_find_decade(ft_create_decade(str), buf), 1);
			if (str[1 + z] >= '1' && str[1 + z] <= '9')
				ft_putstr(ft_find_unite(&str[1 + z], buf), 0);
			write(1, "\n", 1);
		}
	}
}

void	ft_print_word(char *str, char *buf)
{
	int		str_len;
	int		z;

	z = 0;
	str_len = ft_strlen(str) - 1;
	if (str_len % 3 == 0)
	{
		ft_putstr(ft_find_unite(str, buf), 0);
		write(1, "\n", 1);
	}
	ft_print_decade(str, buf, str_len, z);
	if (str_len % 3 == 2)
	{
		ft_putstr(ft_find_unite(&str[0], buf), 1);
		ft_putstr(ft_find_decade("100", buf), 1);
		if (str[1] != '0')
			ft_putstr(ft_find_decade(ft_create_decade(&str[1]), buf), 1);
		if (str[2 + z] >= '1' && str[2 + z] <= '9')
			ft_putstr(ft_find_unite(&str[2 + z], buf), 0);
		write(1, "\b\b", 2);
		write(1, "\n", 1);
	}
}
