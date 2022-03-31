#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *init()
{
	printf("\nInside Pthread once function\n");
}

void *mythread(void *i)
{
	printf("\n%s\n",(char *)i);
	printf("\nInside thread function\n");
	pthread_once(&once,(void *)init);
	printf("\nexit from thread function\n\n");
}

int main()
{

	pthread_t thread, thread1;
	pthread_create(&thread,NULL,mythread,(void *)"thread function called");
	pthread_create(&thread1,NULL,mythread,(void *)"thread function called");

	
	pthread_join(thread,NULL);
	pthread_join(thread1,NULL);
	printf("\n***end of program***\n");
}
