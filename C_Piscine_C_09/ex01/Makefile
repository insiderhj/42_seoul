SRC_DIR=srcs
INC_DIR=includes

CC=gcc
FILES=ft_putchar ft_swap ft_putstr ft_strlen ft_strcmp
SRCS=$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS=$(SRCS:.c=.o)
HEADERS=$(HEADERDIR)/ft.h
CFLAGS=-c -Wall -Werror -Wextra -I$(INC_DIR)
TARGET=libft.a

all : $(TARGET)

clean :
	rm $(OBJS)

fclean : clean
	rm $(TARGET)

re : fclean all

$(TARGET) : $(OBJS)
	ar rc $(TARGET) $(OBJS)
	ranlib $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
