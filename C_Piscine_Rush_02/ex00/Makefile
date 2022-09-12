SRC_DIR=srcs
INC_DIR=includes

CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(INC_DIR)
TEMP=
FILES=ft_dict ft_reader ft_reader_2 ft_string ft_utils ft_print_num ft_print_checker ft_print_unit ft_split
SRCS=$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS=$(SRCS:.c=.o)
LIB=libft.a

TARGET_SRC=main.c
TARGET=rush-02

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
