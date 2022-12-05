CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=philo_utils.c table.c threads.c philo.c main.c
OBJS=$(SRCS:.c=.o)
NAME=philo

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

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
