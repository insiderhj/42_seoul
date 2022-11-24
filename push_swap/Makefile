CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_utils.c push_swap.c stack_ops.c stack_ops_2.c stack.c calculator.c \
	memory_manager.c main.c
OBJS=$(SRCS:.c=.o)
BONUS_SRCS=ft_utils.c stack_ops.c stack_ops_2.c stack.c memory_manager.c checker_bonus.c main_bonus.c
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=push_swap
BONUS_NAME=checker

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean :
	make clean
	rm -f $(NAME) $(BONUS_NAME)

re :
	make fclean
	make

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
