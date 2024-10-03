/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:05:46 by echevali          #+#    #+#             */
/*   Updated: 2024/09/25 14:20:42 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 0;
	if (nb < 0)
		return (0);
	else if (nb == 0)
	{
		result = 1;
		return (result);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

// int main(void)
// {
// 	printf("%d", ft_recursive_factorial(-8));
// 	return (0);
// }