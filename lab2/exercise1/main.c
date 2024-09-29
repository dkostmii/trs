#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
	int num_threads = -1;
	printf("Enter number of threads: ");
	int scanf_result = scanf("%d", &num_threads);
	if (scanf_result != 1)
	{
		printf("Error getting number of threads from user");
		return 1;
	}
	omp_set_num_threads(num_threads);
	printf("\n");

#pragma omp parallel
{
	int thread_num = omp_get_thread_num();

	if (thread_num % 2)
	{
		printf("Hello, OpenMP!\n");
	}
	else
	{
		printf("Dmytro-Andrii Kostelnyi\n");
	}
}
	return 0;
}
