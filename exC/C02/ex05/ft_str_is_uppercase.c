/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:24:20 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 18:05:34 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 97 - 32 || str[i] > 122 - 32))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
//     char	src1[] = "COUCOU";
// 	char	src2[] = "COUCOU";
// 	char	src3[] = "1555";

// 	printf("%d", ft_str_is_uppercase(src1));
// 	printf("%d", ft_str_is_uppercase(src2));
// 	printf("%d", ft_str_is_uppercase(src3));
// 	return (0);
// }