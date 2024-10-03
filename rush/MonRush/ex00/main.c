/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:10:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 19:23:44 by echevali         ###   ########.fr       */
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
