/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:16:06 by echevali          #+#    #+#             */
/*   Updated: 2024/09/19 13:46:40 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*i;
	char	*j;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		i = str;
		j = to_find;
		while (*i == *j && *i != '\0' && *j != '\0')
		{
			i++;
			j++;
		}
		if (*j == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

// int main(void)
// {
//     char str[] = "c bon la ratatouille maison";
//     char to_find[] = "ratatouille";

//     printf("%s", ft_strstr(str, to_find));
//     return (0);
// }