/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:12:45 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 15:22:06 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

int	ft_errors_handling(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if ((argc == 2 && ft_atoi(argv[1]) < 0)
		|| (argc == 3 && ft_atoi(argv[2]) < 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}