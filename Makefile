NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Wextra -Werror
INCLUDES=-Iincludes/ -Ilibft/includes/
SRCDIR=srcs/
LIBDIR=libft/

LIB=$(addprefix $(LIBDIR), libft.a)
SRC=$(addprefix $(SRCDIR), \
		main.c \
		parse_arg.c \
		parse_option.c \
		new_elem.c \
		add_elem.c \
		add_back.c \
		del_list.c \
		del_link.c \
		merge_sort.c \
		pop_elem.c \
		print_list.c \
		print_file.c \
		print_long.c \
		rotate.c \
		r_rotate.c \
		ls_err.c \
		dir_walk.c \
		one_arg.c \
		multiple_arg.c \
		ft_ls.c \
		ft_ls_input.c \
		prepare_long.c \
		prepare_file.c \
		get_link.c \
		get_size.c \
		sort_filelist.c)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIB)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean
	$(MAKE)

.PHONY: $(LIB) re fclean clean all
