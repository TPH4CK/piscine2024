/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:06:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 15:32:27 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

int	ft_filelen(int argc, char **argv)
{
	int		c;
	int		fd;
	char	buf[1];

	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Open file error!", 16);
		return (-1);
	}
	c = 0;
	while (1)
	{
		if (read(fd, buf, 1) == 0)
			break ;
		c++;
	}
	ft_close(fd);
	return (c);
}
