#include <stdio.h>

#define NUM_ROW 3
#define NUM_COL 3

int a[NUM_ROW][NUM_COL];
int b[NUM_ROW][NUM_COL];
int sum[NUM_ROW][NUM_COL];

void mat_add(int rows, int cols);

int main(void)
{
	int i, j;
	
	sum[1][2] = 50;
	printf("Elements of a");
	for(i = 0; i < NUM_ROW; i++) {
		printf("raw %d enter %d numbers: ", i + 1, NUM_COL);
		for(j = 0; j < NUM_COL; j++)
			scanf("%d", &a[i][j]);
	}
	
	printf("Elements of b");
	for(i = 0; i < NUM_ROW; i++) {
		printf("raw %d enter %d numbers: ", i + 1, NUM_COL);
		for(j = 0; j < NUM_COL; j++)
			scanf("%d", &b[i][j]);
	}

	mat_add(NUM_ROW, NUM_COL);

	for(i = 0; i < NUM_ROW; i++) {
		for(j = 0; j < NUM_COL; j++)
			printf(" %d ", sum[i][j]);
		printf("\n");
	}
}

void mat_add(int rows, int cols)
{
	int i, j;

	for(i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++)
			sum[i][j] = (a[i][j] + b[i][j]);
	}
}
