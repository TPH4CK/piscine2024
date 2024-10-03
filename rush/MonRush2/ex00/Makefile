CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = *.c
OBJECTS = $(SRCS:.c=.o)
NAME = rush-02

#make cmd
all: $(NAME) exec clean

#.c -> .o
$(OBJECTS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

#Static lib archived (Step 2)
# -r: insert/replace existing .o files in lib, with new ones
# -c: create/update the archive
# -s: index used by compiler(order of symbols in lib during compilation)
$(NAME): $(OBJECTS)
	ar -rcs lib$(NAME).a $(OBJECTS)

exec:
	$(CC) main.c -g -L. -l$(NAME) -o $(NAME)

clean:
	rm -Rf $(OBJECTS)

fclean: clean
	rm -Rf $(NAME)
