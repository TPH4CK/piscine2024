/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:19:48 by echevali          #+#    #+#             */
/*   Updated: 2024/09/19 11:30:27 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97 - 32 && str[i] <= 122 - 32))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

// int	main(void)
// {
//     char	src1[] = "COUCOU ";
// 	char	src2[] = "LOL ";
// 	char	src3[] = "LOOOOOL";

// 	printf("%s", ft_strlowcase(src1));
// 	printf("%s", ft_strlowcase(src2));
// 	printf("%s", ft_strlowcase(src3));
// 	return (0);
// }