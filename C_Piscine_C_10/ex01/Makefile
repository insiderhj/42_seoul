SRC_DIR=srcs
INC_DIR=includes

CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(INC_DIR)
FILES=ft_putchar ft_putstr ft_puterr ft_display_file
SRCS=$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS=$(SRCS:.c=.o)
LIB=libft.a

TARGET_SRC=ft_cat.c
TARGET=ft_cat

all : $(TARGET)

clean :
	rm -rf $(OBJS) $(LIB)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

$(TARGET) : $(LIB)
	$(CC) $(CFLAGS) $(TARGET_SRC) $(LIB) -o $(TARGET)

$(LIB) : $(OBJS)
	ar rcus $(LIB) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
