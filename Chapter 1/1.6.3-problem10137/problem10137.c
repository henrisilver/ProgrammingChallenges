#include <stdio.h>
#include <math.h>

#define MAX 1000

double expenses[MAX];

double computeAmount(int numberOfStudents) {
	double negativeDifference = 0.0 , positiveDifference = 0.0, difference;
	double average = 0.0;
	int i;
	
	for(i = 0; i < numberOfStudents; i++) {
		average += expenses[i];
	}
	
	average = average / numberOfStudents; /* computing average */

	for(i = 0; i < numberOfStudents; i++) {
		difference = (double) (int) ((average - expenses[i])*100)/100;

		if(difference < 0.0)
			negativeDifference += difference;
		else
			positiveDifference += difference;
	}

	return - negativeDifference > positiveDifference ? - negativeDifference : positiveDifference;

}

int main(int argc, const char **argv) {

	int numberOfStudents;
	int i;
	double exchangeAmount;

	scanf("%d", &numberOfStudents);
	while(numberOfStudents > 0) {
		for(i = 0; i < numberOfStudents; i++) {
			scanf("%lf", &expenses[i]);
		}
		exchangeAmount = computeAmount(numberOfStudents);
		printf("$%.2lf\n", exchangeAmount);
		scanf("%d", &numberOfStudents);
	}

	return 0;
}