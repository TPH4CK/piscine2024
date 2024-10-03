/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first_decade.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:34:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 21:25:09 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*test2(int i, char *str, char *buf)
{
	char	*first_decade;
	int		j;

	if (str[0] == buf[i])
	{
		j = 0;
		while (str[j] == buf[i++])
			j++;
		if (str[j] == '\0')
		{
			while (buf[i] == ' ' || buf[i] == ':')
				i++;
			first_decade = ft_take_until_newline(&buf[i]);
			return (first_decade);
		}
	}
	return (NULL);
}

char	*ft_find_first_decade(char *str, char *buf)
{
	char	*first_decade;
	int		i;

	i = 0;
	first_decade = NULL;
	while (buf[i])
	{
		first_decade = test2(i, str, buf);
		i++;
	}
	return (first_decade);
}
