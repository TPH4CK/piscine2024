/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:31:48 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 15:32:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rush02.h"

int	ft_rush02(int argc, char **argv)
{
	int		fd;
	char	*buf;
	int		cnt;
	int		sz;

	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Open file error!", 16);
		return (-1);
	}
	cnt = ft_filelen(argc, argv);
	buf = (char *)malloc((cnt + 1) * sizeof(char));
	sz = read(fd, buf, cnt);
	buf[cnt] = '\0';
	if (argc == 2)
		ft_print_word(argv[1], buf);
	else
		ft_print_word(argv[2], buf);
	ft_close(fd);
	free(buf);
	return (sz);
}
