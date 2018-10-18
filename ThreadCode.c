#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int arr[1000];
int size=1000;
int c_size=100;

void function()
{
	int i;
	for(i=0;i<size;i++)
		arr[i]=i;
}

void *add(void *arg)
{
	int start = (int)arg;
	int end = start + c_size;
	int s=0, i=start;
	for(;i<end;i++)
		s=s+arr[i];
	return ((void*)s);
}

int main()
{
	function();

	pthread_t thread_t[10];
	int var[10], sum, i=0;

	for(;i<10;i++)
	{
		pthread_create(&(thread_t[i]), NULL, add, (void*)(i*c_size));
		pthread_join(thread_t[i], (void**) & var[i]);
		sum = sum + var[i];
	}
	printf("Sum of 1000 numbers = %d\n",sum);
return 0;
}

