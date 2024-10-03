/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:02:02 by echevali          #+#    #+#             */
/*   Updated: 2024/10/01 00:25:13 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
// int	main()
// {
// 	int	tab[100] = {3, 2, 4, 5, 4, 8, 4, 6, 7, 1, 0, 2};
// 	int	i;

// 	i = 0;
// 	ft_sort_int_tab(tab, 20);
// 	while (i < 20)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }