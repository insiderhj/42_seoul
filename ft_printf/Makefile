LIB_DIR=./libft
INC_DIR=./include
SRC_DIR=./src
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR)
LIB_SRCS= $(addprefix $(LIB_DIR)/, ft_nbrlen.c ft_hexlen.c ft_strlen.c ft_isdigit.c ft_putchar.c\
									ft_putstr.c ft_putnchar.c ft_putnbr.c ft_puthex.c ft_putnstr.c\
									ft_strchr.c)
LIB_OBJS=$(LIB_SRCS:.c=.o)
LIB=libft.a

SRCS=$(addprefix $(SRC_DIR)/, ft_printf_parser.c  ft_printf_utils.c ft_printf_printer.c ft_printf.c)
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=libftprintf.a

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS) $(LIB_OBJS) $(LIB)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

$(NAME) : $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIB) : $(LIB_OBJS)
	ar rcs $(LIB) $(LIB_OBJS)

bonus : fclean $(NAME)

test : main.c $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out
	rm a.out

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus test
