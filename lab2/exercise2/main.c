#include <stdio.h>
#include <omp.h>

int main() {
	int A[15] = {12, -7, 5, -3, 8, -2, 0, 15, -4, 9, -1, -6, 3, 10, -11};
	int S1 = 0, S2 = 0;
	int i;
	#pragma omp parallel for reduction(+:S1) reduction(+:S2)
	for (i = 0; i < 15; i++) {
		if (A[i] > 0) {
			S1 += A[i];
		} else if (A[i] < 0) {
			S2 += A[i];
		}
	}
	printf("Positive sum (S1): %d\n", S1);
	printf("Negative sum (S2): %d\n", S2);
	if (S1 > -S2) {
		printf("S1 > -S2 \n");
	} else if (S1 < -S2) {
		printf("S1 < -S2 \n");
	} else {
		printf("S1 == -S2 \n");
	}
	return 0;
}
