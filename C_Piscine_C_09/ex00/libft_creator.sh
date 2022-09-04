CC=gcc
SRCS=*.c
CFLAGS="-c -Wall -Werror -Wextra"
TARGET="libft.a"

$CC $CFLAGS $SRCS
ar rc $TARGET *.o
ranlib $TARGET
rm *.o
