#include<pthread.h>
#include<stdio.h>


void *thread(void)
{
	printf("\n****I am in my thread****\n");
}

int main()
{

	pthread_t threadid;
	pthread_create(&threadid,NULL,thread,NULL);
	printf("\n exit for main thread\n");
	pthread_exit(NULL);
}
