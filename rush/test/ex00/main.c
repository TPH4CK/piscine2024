/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:10:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 19:12:39 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

int	main(int argc, char **argv)
{
	if (!ft_errors_handling(argc, argv))
		return (0);
	ft_rush02(argc, argv);
	return (0);
}
