SRC_DIR=srcs
INC_DIR=includes

CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(INC_DIR)
FILES=ft_putchar ft_putstr
SRCS=$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS=$(SRCS:.c=.o)
LIB=libft.a

TARGET_SRC=ft_display_file.c
TARGET=ft_display_file

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
