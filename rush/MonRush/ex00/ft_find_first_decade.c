/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first_decade.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:34:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 19:28:15 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*ft_find_first_decade(char *str, char *buf)
{
	char	*first_decade;
	int		i;
	int		j;
	int		save;

	i = 0;
	first_decade = NULL;
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
				first_decade = ft_take_until_newline(&buf[i]);
				return (first_decade);
			}
			i = save;
		}
		i++;
	}
	return (first_decade);
}
