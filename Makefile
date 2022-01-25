SRC = philo_live.c utils.c clear_mutex.c parser.c main.c check_death_eats.c

HEADER = philo.h

NAME = philo

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror


all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	gcc $(SRC) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY = all clean fclean re
