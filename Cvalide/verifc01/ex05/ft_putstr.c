/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:19:17 by echevali          #+#    #+#             */
/*   Updated: 2024/09/16 16:05:14 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	tmp;

	tmp = 0;
	while (str[tmp] != '\0')
	{
		write(1, &str[tmp], 1);
		tmp++;
	}
}

int main()
{
    char my_string[] = "H";
    ft_putstr(my_string);
    write(1, "\n", 1);
    return 0;
}