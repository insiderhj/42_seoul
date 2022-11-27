LIB_DIR=./libft
INC_DIR=./include
SRC_DIR=./src

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR)
LIB_SRCS= $(addprefix $(LIB_DIR)/, ft_hexlen.c ft_isdigit.c ft_nbrlen.c ft_printf_parser.c ft_printf_printer.c\
									ft_printf_utils.c ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c\
									ft_putnchar.c ft_putnstr.c ft_putstr.c ft_strchr.c ft_strlen.c \
									ft_atoi.c)
LIB_OBJS=$(LIB_SRCS:.c=.o)
LIB=libft.a

SERVER_SRCS=$(addprefix $(SRC_DIR)/, server.c)
CLIENT_SRCS=$(addprefix $(SRC_DIR)/, client.c)
SERVER_BONUS_SRCS=$(addprefix $(SRC_DIR)/, server_bonus.c)
CLIENT_BONUS_SRCS=$(addprefix $(SRC_DIR)/, client_bonus.c)
SERVER_OBJS=$(SERVER_SRCS:.c=.o)
CLIENT_OBJS=$(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS=$(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS=$(CLIENT_BONUS_SRCS:.c=.o)

ifdef BONUS
	T_SERVER_OBJS=$(SERVER_BONUS_OBJS)
	T_CLIENT_OBJS=$(CLIENT_BONUS_OBJS)
else
	T_SERVER_OBJS=$(SERVER_OBJS)
	T_CLIENT_OBJS=$(CLIENT_OBJS)
endif

NAME=minitalk
SERVER=server
CLIENT=client

all : $(NAME)

clean :
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) $(LIB_OBJS) $(LIB)

fclean :
	make clean
	rm -f $(SERVER) $(CLIENT)

re :
	make fclean
	make

$(LIB) : $(LIB_OBJS)
	ar rcs $(LIB) $(LIB_OBJS)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER): $(T_SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(SERVER) $(T_SERVER_OBJS) $(LIB)

$(CLIENT): $(T_CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(CLIENT) $(T_CLIENT_OBJS) $(LIB)

bonus :
	make BONUS=1

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus test $(NAME)
