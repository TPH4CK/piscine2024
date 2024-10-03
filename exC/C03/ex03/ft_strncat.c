/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:43:51 by echevali          #+#    #+#             */
/*   Updated: 2024/09/23 11:19:47 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	while ((src[i] != '\0') && (i < nb))
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
// 	printf("dest + src : %s", ft_strncat(dest, src, 13));
// 	return (0);
// }