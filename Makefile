CC := cc -Wall -Wextra -Werror -pthread -g
NAME := codexion
SRC := codexion.c

$(NAME):
	$(CC) $(SRC) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re:	fclean all

test: 
	clear
	$(CC) *.c */*.c */*/*.c -o $(NAME)

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean