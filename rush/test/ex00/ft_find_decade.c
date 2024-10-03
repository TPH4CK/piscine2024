/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_decade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:34:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 21:15:35 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*test(int i, char *str, char *buf)
{
	int		j;
	char	*decade;

	if (str[0] == buf[i])
	{
		j = 0;
		while (str[j] == buf[i++])
			j++;
		if (str[j] == '\0')
		{
			while (buf[i] == ' ' || buf[i] == ':')
				i++;
			decade = ft_take_until_newline(&buf[i]);
			return (decade);
		}
	}
	return (NULL);
}

char	*ft_find_decade(char *str, char *buf)
{
	char	*decade;
	int		i;

	i = 0;
	decade = NULL;
	while (buf[i])
	{
		decade = test(i, str, buf);
		i++;
	}
	return (decade);
}
