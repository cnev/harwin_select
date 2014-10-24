NAME = ft_ls
CC = gcc -I $(HEADERFOLDER)
CFLAGS = -Wall -Wextra -Werror -O3
SRCFOLDER = srcs
HEADERFOLDER = includes/
SRC += $(SRCFOLDER)/argcheck.c
SRC += $(SRCFOLDER)/display_results.c
SRC += $(SRCFOLDER)/display_results2.c
SRC += $(SRCFOLDER)/exec_ls.c
SRC += $(SRCFOLDER)/exec_ls2.c
SRC += $(SRCFOLDER)/fifo.c
SRC += $(SRCFOLDER)/formats.c
SRC += $(SRCFOLDER)/ft_create_elem.c
SRC += $(SRCFOLDER)/ft_list_clear.c
SRC += $(SRCFOLDER)/ft_list_find.c
SRC += $(SRCFOLDER)/ft_list_push_back.c
SRC += $(SRCFOLDER)/ft_list_sort.c
SRC += $(SRCFOLDER)/ft_list_rsort.c
SRC += $(SRCFOLDER)/main.c
SRC += $(SRCFOLDER)/print_l.c
SRC += $(SRCFOLDER)/print_l2.c
SRC += $(SRCFOLDER)/recursive_ls.c
SRC += $(SRCFOLDER)/return_error.c
OBJ = $(SRC:%.c=%.o)
LIB = libft/

all: $(NAME)

$(NAME): $(OBJ) lib
	@$(CC) $(CFLAGS) -Llibft/ -lft -g -o $(NAME) $(OBJ)

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
