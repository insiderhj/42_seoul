CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=philo_utils_bonus.c philo_bonus.c monitor_bonus.c main_bonus.c
OBJS=$(SRCS:.c=.o)
NAME=philo_bonus

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: 
	make

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
