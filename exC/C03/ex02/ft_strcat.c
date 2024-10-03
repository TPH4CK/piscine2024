/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 06:42:20 by echevali          #+#    #+#             */
/*   Updated: 2024/09/19 13:45:27 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char dest[50] = "GG ";
// 	char src[] = "gros nooblard";

// 	printf("dest : %s\n\n", dest);
// 	printf("src : %s\n\n", src);
// 	printf("dest + src : %s", ft_strcat(dest, src));
// 	return (0);
// }