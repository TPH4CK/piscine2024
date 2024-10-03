/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:56:19 by echevali          #+#    #+#             */
/*   Updated: 2024/10/01 14:29:05 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count_sign;
	int	result;

	i = 0;
	count_sign = 0;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			count_sign++;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (count_sign % 2 == 0)
		return (result);
	return (result *= -1);
}

// int	main(void)
// {
// 	char str[] = "\n \t +--+1234567";
// 	printf("%d", ft_atoi(str));
// 	return(0);
// }