#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int **board;
int size;

void generate_board(int sz)
{
	size = sz;
	board = (int **)malloc(sizeof(int *) * sz);
	for (int i = 0; i < size; i++) {
		board[i] = (int *)malloc(sizeof(int) * sz);
	}
}

void destroy_board()
{
	for(int i = 0; i < size; i++) {
		free(board[i]);
	}
	free(board);
}

void fill_default()
{
	int n;
	for (int i = 0; i < size; i++) {
		n = i + 1;
		for (int j = 0; j < size; j++, n++) {
			if (n > size) n -= size;
			board[i][j] = n;
		}
	}
}

void print_board()
{
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("%d", board[i][j]);
			if (j < size - 1)
				putchar(' ');
		}
		putchar('\n');
	}
}

void swap_row(int r1, int r2)
{
	int *temp;
	temp = board[r1];
	board[r1] = board[r2];
	board[r2] = temp;
}

void swap_col(int c1, int c2)
{
	int temp;
	for(int i = 0; i < size; i++) {
		temp = board[i][c1];
		board[i][c1] = board[i][c2];
		board[i][c2] = temp;
	}
}

void random_swap()
{
	int dir = rand() % 2;
	int num1 = rand() % size;
	int num2 = rand() % size;
	if (dir) swap_row(num1, num2);
	else swap_col(num1, num2);
}

int count_col_up(int col)
{
	int	count = 0;
	int	max = 0;
	for (int i = 0; i < size; i++) {
		if (board[i][col] > max) {
			max = board[i][col];
			count++;
		}
	}
	return (count);
}

int count_col_down(int col)
{
	int	count = 0;
	int	max = 0;
	for(int i = size - 1; i >= 0; i--) {
		if (board[i][col] > max) {
			max = board[i][col];
			count++;
		}
	}
	return (count);
}

int count_row_left(int row)
{
	int count = 0;
	int max = 0;
	for(int i = 0; i < size; i++) {
		if (board[row][i] > max) {
			max = board[row][i];
			count++;
		}
	}
	return (count);
}

int count_row_right(int row)
{
	int count = 0;
	int max = 0;
	for(int i = size - 1; i >= 0; i--) {
		if (board[row][i] > max) {
			max = board[row][i];
			count++;
		}
	}
	return (count);
}

int main(int argc, char **argv)
{
	int sz = 4;
	if (argc >= 2) {
		sz = atoi(argv[1]);
	}
	if (sz <= 0) {
		printf("size must be greater than 0!\n");
		return -1;
	}

	generate_board(sz);
	fill_default();
	srand(time(NULL));
	for(int i = 0; i < size * size; i++)
		random_swap();
	printf("./rush-01 \"");
	for (int i = 0; i < size; i++) {
		printf("%d ", count_col_up(i));
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", count_col_down(i));
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", count_row_left(i));
	}
	for (int i = 0; i < size - 1; i++) {
		printf("%d ", count_row_right(i));
	}
	printf("%d", count_row_right(size - 1));
	printf("\" | cat -e\n");
	print_board();
	destroy_board();
	return 0;
}
