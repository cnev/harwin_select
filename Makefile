NAME = ft_select
CC = gcc -I $(HEADERFOLDER)
CFLAGS = -Wall -Wextra -Werror -O3
SRCFOLDER = srcs
HEADERFOLDER = includes/

SRC += srcs/cdlist.c
SRC += srcs/display.c
SRC += srcs/getkey.c
SRC += srcs/getkey2.c
SRC += srcs/list.c
SRC += srcs/list2.c
SRC += srcs/main.c
SRC += srcs/select.c
SRC += srcs/signals.c
SRC += srcs/signals2.c
SRC += srcs/singleton.c

OBJ = $(SRC:%.c=%.o)
LIB = libft/

all: $(NAME)

$(NAME): $(OBJ) lib
	@$(CC) $(CFLAGS) -Llibft/ -lft -L /usr/lib -ltermcap -o $(NAME) $(OBJ)

%.o: %.c
	@echo "Building $@"
	@$(CC) $(CFLAGS) -I. -o $@ -c $^

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(LIB): lib

lib:
	@make -C libft/
