/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:18:51 by echevali          #+#    #+#             */
/*   Updated: 2024/10/01 02:37:51 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_catsize(int size, char **strs, char *sep)
{
	int	i;
	int	catsize;

	i = 0;
	catsize = 0;
	while (i < size)
	{
		catsize = catsize + ft_strlen(strs[i++]);
	}
	catsize += ft_strlen(sep) * (size - 1);
	return (catsize);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		catsize;
	char	*la_ou_ca_ira;
	int		i;

	if (size == 0)
	{
		la_ou_ca_ira = malloc(1);
		la_ou_ca_ira[0] = '\0';
		return (la_ou_ca_ira);
	}
	catsize = ft_catsize(size, strs, sep);
	la_ou_ca_ira = malloc(sizeof(char) * (catsize + 1));
	if (!la_ou_ca_ira)
		return (NULL);
	i = 0;
	la_ou_ca_ira[0] = '\0';
	while (i < size)
	{
		ft_strcat(la_ou_ca_ira, strs[i]);
		if (i < size - 1)
			ft_strcat(la_ou_ca_ira, sep);
		i++;
	}
	return (la_ou_ca_ira);
}

// int	main(void)
// {
// 	char	*str[] = {"mac1", "mac2", "mac3"};
// 	char	*sep = "\\*\\!\\'";
// 	char	*result;

// 	result = ft_strjoin(3, str, sep);
// 	if (result)
// 	{
// 		printf("%s\n", result);
// 		free(result);
// 	}
//     return 0;
// }
