/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:10:46 by echevali          #+#    #+#             */
/*   Updated: 2024/09/18 18:05:33 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32 || str[i] > 127))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
//     char	src1[] = "\n";
// 	char	src2[] = "\n";
// 	char	src3[] = "";

// 	printf("%d", ft_str_is_printable(src1));
// 	printf("%d", ft_str_is_printable(src2));
// 	printf("%d", ft_str_is_printable(src3));
// 	return (0);
// }