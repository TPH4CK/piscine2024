/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_until_newline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:45:09 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 16:41:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

char	*ft_take_until_newline(char *str)
{
	char	*rest;
	int		str_len;
	int		i;

	i = 0;
	str_len = 0;
	while (str[i] && str[i] != '\n')
	{
		str_len++;
		i++;
	}
	rest = (char *)malloc((str_len + 1) * sizeof(char));
	if (rest == NULL)
	{
		write(1, "Rest memory error!", 18);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rest[i] = str[i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
