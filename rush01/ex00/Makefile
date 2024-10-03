# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmichel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 12:48:05 by thmichel          #+#    #+#              #
#    Updated: 2024/09/22 12:48:07 by thmichel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g
	
SRC = rush_01_Erwan.c display_error.c ft_pointOfView.c impossible.c readmap.c ind_possible.c
	
OBJ = $(SRC:.c=.o)
	
rush-01: $(OBJ)
		$(CC) $(CFLAGS) -o rush-01 $(OBJ)

%.o:%.c
		$(CC) $(CFLAGS) -c $< -o $@
		
clean:
		rm -f *.o rush-01
