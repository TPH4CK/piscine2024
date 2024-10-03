/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:05 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 18:05:38 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
//     char	src1[] = "hello";
//     char	src2[] = "cO1";
//     char	src3[] = "154234";

//     printf("%d", ft_str_is_alpha(src1));
//     printf("%d", ft_str_is_alpha(src2));
//     printf("%d", ft_str_is_alpha(src3));
// 	return (0);
// }