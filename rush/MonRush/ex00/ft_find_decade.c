/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_decade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:34:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 20:43:28 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*ft_find_decade(char *str, char *buf)
{
	char	*decade;
	int		i;
	int		j;
	int		save;

	i = 0;
	decade = NULL;
	while (buf[i])
	{
		if (str[0] == buf[i])
		{
			j = 0;
			save = i;
			while (str[j] == buf[i])
			{
				j++;
				i++;
			}
			if (str[j] == '\0')
			{
				while (buf[i] == ' ' || buf[i] == ':')
					i++;
				decade = ft_take_until_newline(&buf[i]);
				return (decade);
			}
			i = save;
		}
		i++;
	}
	return (decade);
}
