VAL := valgrind --leak-check=full --log-file=grind.log
CC := cc -pthread -g -O0
NAME := codexion
SRC := ./codexion.c \
./utils/ft_calloc.c \
./utils/ft_strlcpy.c \
./utils/ft_strlen.c \
./utils/ft_memcpy.c \
./utils/ft_putstr_fd.c \
./utils/append_msg.c \
./utils/ft_itoa.c \
./utils/ft_isdigit.c \
./utils/ft_gettimems.c \
./src/thread_ops/helper.c \
./src/thread_ops/thread_ops.c \
./src/validation/check_args.c \
./src/validation/init.c \
./src/types/coder/coder.c \
./src/types/dongle/dongle.c \
./src/types/heap/heap.c \
./src/types/heap/heap_ops.c \
./src/types/w_thread/w_thread.c \
./src/types/log/log.c \
./src/threads/coders.c \
./src/threads/main.c \
./src/threads/monitor.c

ARGS := 2 4100 200 5 5 5 200 edf

$(NAME):
	$(CC) $(SRC) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(NAME)
	rm -rf res.txt

fclean: clean

re:	fclean all

test: 
	clear
	$(CC) *.c */*.c */*/*.c */*/*/*.c -o $(NAME)

grind:
	$(VAL) ./$(NAME) $(ARGS)

run:
	./$(NAME) $(ARGS)

full: test run

srcs:
	find . -type f -name "*.c" > res.txt

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean