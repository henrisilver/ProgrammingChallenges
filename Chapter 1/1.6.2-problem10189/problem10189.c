#include <stdio.h>

#define SIZE 102

int matrixNumbers[SIZE][SIZE]; /* matrix representing the field in numbers */
char matrixChars[SIZE][SIZE]; /* matrix representing the field in chars */

void resetMatrices() {
	int i, j;
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			matrixNumbers[i][j] = 0;
			matrixChars[i][j] = '.';
		}
	}
}

void increaseMineCount(int i, int j) {
	if(matrixChars[i][j] != '*')
		matrixNumbers[i][j]++;
}

void processMatrix(int count, int n, int m) {
	int i, j;
	if(count > 1)
		printf("\n");
	printf("Field #%d:\n", count);
	for(i = 1; i < n + 1; i++) {
		for(j = 1; j < m + 1; j++) {
			if(matrixChars[i][j] == '*') {
				matrixNumbers[i][j] = -1;
				increaseMineCount(i-1, j-1);
				increaseMineCount(i-1, j);
				increaseMineCount(i-1, j+1);
				increaseMineCount(i, j-1);
				increaseMineCount(i, j+1);
				increaseMineCount(i+1, j-1);
				increaseMineCount(i+1, j);
				increaseMineCount(i+1, j+1);
			}
		}
	}

	for(i = 1; i < n + 1; i++) {
		for(j = 1; j < m + 1; j++) {
			if(matrixNumbers[i][j] == -1 )
				printf("*");
			else
				printf("%d", matrixNumbers[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, const char **argv) {
	
	int n, m; /* n = lines, m = columns */
	int i, j; /* iteration variables */
	int count = 1; /* counting the number of fields */
	char c; /* char reprsenting each square */
	scanf("%d %d", &n, &m);
	
	while(n > 0 && m > 0) {

		resetMatrices();
		for(i = 1; i < n + 1; i ++) {
			for(j = 1; j < m + 1; j++) {
				do {
					c = getchar();
				} while(c != '*' && c != '.');
				matrixChars[i][j] = c;
			}
		}
		getchar();
		
		processMatrix(count++, n, m);
		scanf("%d %d", &n, &m);
	}

	return 0;
}