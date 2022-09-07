SRC_DIR=srcs
INC_DIR=includes

CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(INC_DIR)
FILES=ft_io ft_string ft_buf ft_put_dump ft_dump_input ft_dump_file
SRCS=$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS=$(SRCS:.c=.o)
LIB=libft.a

TARGET_SRC=ft_hexdump.c
TARGET=ft_hexdump

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
