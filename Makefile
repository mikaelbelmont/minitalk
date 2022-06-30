CFLAGS = -Wall -Werror -Wextra

CC = gcc

all:
	@cd libft && make all
	@cd ft_printf && make all
	@$(CC) $(CFLAGS) server.c libft/libft.a ft_printf/printf.a -o server
	@$(CC) $(CFLAGS) client.c libft/libft.a ft_printf/printf.a -o client

clean:
	@cd libft && make clean
	@cd ft_printf && make clean
	@rm -rf server
	@rm -rf server

fclean: clean
	@cd libft && make fclean
	@cd ft_printf && make fclean

re: fclean all
