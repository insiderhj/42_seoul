INC_DIR=./include
SRC_DIR=./src
BONUS_DIR=./bonus
LIB_DIR=./libft

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR)
CLIB=-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

LIB_SRCS= $(addprefix $(LIB_DIR)/, ft_atoi.c ft_hexlen.c ft_isdigit.c ft_nbrlen.c ft_printf_parser.c \
									ft_printf_printer.c ft_printf_utils.c ft_printf.c ft_putchar.c ft_puthex.c \
									ft_putnbr.c ft_putnchar.c ft_putnstr.c ft_putstr.c ft_strchr.c \
									ft_strlen.c get_next_line_utils.c get_next_line.c ft_itoa.c)
LIB_OBJS=$(LIB_SRCS:.c=.o)
LIB=libft.a

SRCS=$(addprefix $(SRC_DIR)/, so_long_utils.c map.c checker.c event.c gui.c \
								animate.c enemy.c main.c)
OBJS=$(SRCS:.c=.o)
BONUS_SRCS=$(addprefix $(BONUS_DIR)/,so_long_utils_bonus.c map_bonus.c checker_bonus.c event_bonus.c gui_bonus.c \
									animate_bonus.c enemy_bonus.c main_bonus.c)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=so_long

ifdef BONUS
	M_OBJS=$(BONUS_OBJS)
else
	M_OBJS=$(OBJS)
endif

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS) $(LIB_OBJS) $(LIB)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make

$(NAME) :  $(M_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(CLIB) $(M_OBJS) $(LIB) -o $(NAME)

$(LIB) : $(LIB_OBJS)
	ar -rcs $(LIB) $(LIB_OBJS)

bonus : $(BONUS_OBJS)
	make BONUS=1 $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
