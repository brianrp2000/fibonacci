#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long *array;
void *runner(void *param);

int main (int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2){
		printf("ERROR; enter a number as argument indicating the desired number of threads\n");
		return -1;
	}

	long num = atol(argv[1]);
	if(num <= 0){
		fprintf(stderr, "usage: fib <natural number>\n");
		return -1;
	}

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, (void *) num);
	pthread_join(tid, NULL);

	for(int i = 0; i < num - 1; i++){
		printf("%lu, ", array[i]);
	}
	printf("%lu\n", array[num-1]);

	free(array);
}

void *runner(void *param){
	long upper = (long)param;
	array = (long*)malloc(upper * sizeof(long));
	array[0] = 0;
	if (upper == 1) return 0;
	array[1] = 1;
 
	long a = 0, b = 1, c;
	for(long i = 2; i < upper; i++){
		c = a + b;
		a = b;
		b = c;

		array[i] = b;
	}
	pthread_exit(0);
}