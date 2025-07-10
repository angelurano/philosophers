NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

SRC = init_data.c monitor.c parse_input.c philo.c philosopher.c prints.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

dev: CFLAGS += -g3 -fsanitize=address,leak,undefined
dev: re

.PHONY: all clean fclean re
