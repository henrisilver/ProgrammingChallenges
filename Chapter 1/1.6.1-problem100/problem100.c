/* Henrique de Almeida Machado da Silveira
 * Solution to the 3n + 1 problem: UVa ID 100
 */

#include <stdio.h>

int getMaximumCycleLength(int i, int j) {
	int max_cycle_length = 0; /* maximum cycle lenght found */
	int current_cycle_lenght; /* current cycle length */
	int x; /* iteration variable */
	int aux; /* auxiliary variable to compute the 3n + 1 problem */

	if(i > j) {
		int swap; /* Used to help swap i and j */
		swap = i;
		i = j;
		j = swap;
	}

	for(x = i; x <= j; x++) {
		current_cycle_lenght = 1;
		aux = x;
		while(aux > 1) {
			if(aux % 2 == 0) {
				aux = aux / 2;
			} else {
				aux = 3 * aux + 1;
			}
			current_cycle_lenght++;
		}
		if(current_cycle_lenght > max_cycle_length) {
			max_cycle_length = current_cycle_lenght;
		}
	}
	return max_cycle_length;
}

int main(int argc, const char** argv) {

	int i, j; /* i and j: input numbers */
	int max_cycle_length; /* maximum cycle lenght found */
	int current_cycle_lenght = 0;
	while(scanf("%d %d", &i, &j) != EOF) {
		max_cycle_length = getMaximumCycleLength(i, j);
		printf("%d %d %d\n", i, j, max_cycle_length);
	}

	return 0;
}