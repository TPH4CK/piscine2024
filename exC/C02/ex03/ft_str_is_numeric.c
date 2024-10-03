/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:01:30 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 18:05:37 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
//     char	src1[] = "1";
//     char	src2[] = "abcdefghijklmnop";
//     char	src3[] = "15424";

//     printf("%d", ft_str_is_numeric(src1));
//     printf("%d", ft_str_is_numeric(src2));
//     printf("%d", ft_str_is_numeric(src3));
// 	return (0);
// }