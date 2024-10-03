/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echevali <echevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:17:09 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/29 23:37:06 by echevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_atoi(char *str);
int		ft_errors_handling(int argc, char **argv);
int		ft_error_len(int ac, char *av[]);
int		ft_rush02(int argc, char **argv);
void	ft_putstr(char *str, int index);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_filelen(int argc, char **argv);
void	ft_print_word(char *str, char *buf);
char	*ft_find_unite(char *str, char *buf);
char	*ft_find_decade(char *str, char *buf);
char	*ft_find_first_decade(char *str, char *buf);
char	*ft_take_until_newline(char *str);
int		ft_close(int fd);

#endif
