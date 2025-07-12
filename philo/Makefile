NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

SRC = init_data.c monitor.c mutexes.c parse_input.c philo_handlers.c philo_routine.c philo.c printter.c time.c utils.c
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
