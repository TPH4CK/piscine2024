/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:27:38 by echevali          #+#    #+#             */
/*   Updated: 2024/10/01 11:24:58 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_lenght;
	unsigned int	src_lenght;
	unsigned int	i;
	unsigned int	j;

	dest_lenght = 0;
	src_lenght = 0;
	while (dest[dest_lenght])
		dest_lenght++;
	while (src[src_lenght])
		src_lenght++;
	i = 0;
	j = dest_lenght;
	if (size <= dest_lenght)
		return (src_lenght + size);
	while (src[i] && i < size - dest_lenght - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_lenght + src_lenght);
}

// int	main(void)
// {
// 	char	dest[50] = "On ne se baigne jamais";
// 	char	src[] = " deux fois dans le même fleuve !";
// 	unsigned int	size = 512;
// 	unsigned int	result;

// 	printf("Avant ft_strlcat:\n");
// 	printf("dest = \"%s\"\n", dest);
// 	printf("src = \"%s\"\n", src);

// 	result = ft_strlcat(dest, src, size);

// 	printf("\nAprès ft_strlcat:\n");
// 	printf("dest = \"%s\"\n", dest);
// 	printf("Longueur totale retournée = %u\n", result);

// 	return 0;
// }