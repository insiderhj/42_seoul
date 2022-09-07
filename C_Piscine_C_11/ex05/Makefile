SRC_DIR=srcs
INC_DIR=includes

CC=gcc
SRCS=main.c do-op.c
CFLAGS=-Wall -Werror -Wextra
TARGET=do-op

all : $(TARGET)

clean :
	@:

fclean : clean
	rm -rf $(TARGET)

re : fclean all

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
