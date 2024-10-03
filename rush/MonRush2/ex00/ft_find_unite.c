/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_unite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:35:29 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 15:31:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*ft_find_unite(char *str, char *buf)
{
	char	*unite;
	int		i;

	i = 0;
	unite = NULL;
	while (buf[i])
	{
		if (str[0] == buf[i])
		{
			i++;
			while (buf[i] == ' ' || buf[i] == ':')
				i++;
			unite = ft_take_until_newline(&buf[i]);
			return (unite);
		}
		i++;
	}
	return (unite);
}
