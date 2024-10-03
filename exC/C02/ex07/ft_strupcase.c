/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:23:44 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 18:05:29 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

// int	main(void)
// {
//     char	src1[] = "coucou ";
// 	char	src2[] = "lol ";
// 	char	src3[] = "looooooool";

// 	printf("%s", ft_strupcase(src1));
// 	printf("%s", ft_strupcase(src2));
// 	printf("%s", ft_strupcase(src3));
// 	return (0);
// }