CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c ft_check_die.c ft_check_nbrs.c ft_cleanup.c \
		ft_forks_to_philos.c ft_philo_routine.c ft_print_error.c \
		ft_time.c ft_usleep.c philo.c

OBJ = $(SRC:.c=.o)

NAME = philo

HDR = philo.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean