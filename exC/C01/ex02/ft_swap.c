/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:16:37 by echevali          #+#    #+#             */
/*   Updated: 2024/09/14 01:27:39 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temps;

	temps = *a;
	*a = *b;
	*b = temps;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 42;
// 	b = -42;
// 	ft_swap(&a, &b);
// 	printf("%d ", a);
// 	printf("%d", b);
// 	return (0);
// }