CC=gcc
CFLAGS=-Werror -Wextra -Wall -g -I libft/ -I includes
LIBFLAGS=-L libft/ -lft
NAME=ft_ls
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)

.PHONY: clean fclean all re norm norme debug test

VPATH = src obj libft/includes include

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) obj/* $(LIBFLAGS)
	@echo "ft_ls build complete!"

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
	
norm:
	norminette src/. include/.

norme: norm
