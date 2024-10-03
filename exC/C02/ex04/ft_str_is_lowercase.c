/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:18:47 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 18:05:35 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 97 || str[i] > 122))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
//     char	src1[] = "coucou";
// 	char	src2[] = "coucoU";
// 	char	src3[] = "coucou";

// 	printf("%d", ft_str_is_lowercase(src1));
// 	printf("%d", ft_str_is_lowercase(src2));
// 	printf("%d", ft_str_is_lowercase(src3));
// 	return (0);
// }