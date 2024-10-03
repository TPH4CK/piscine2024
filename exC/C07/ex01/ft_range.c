/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:18:43 by echevali          #+#    #+#             */
/*   Updated: 2024/10/01 01:42:50 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	i = 0;
	if (min >= max)
		return (NULL);
	ptr = malloc(sizeof(int) * (max - min + 1));
	if (ptr == NULL)
		return (NULL);
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int *tab;
// 	int i;

// 	min = -5;
// 	max = 15;
// 	tab = ft_range(min, max);
// 	i = 0;
// 	while (i < 20)
// 	{	printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	free (tab);
// 	return (0);
// }
