#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

struct my_thread
{
	int thread_id;
	char msg[100];
};

void *thread(void *arg)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1 = (struct my_thread *) arg;
	printf("\nInside thread function\n");
	printf("\nThread Id : %u\n",t1->thread_id);
	printf("\n%s\n",t1->msg);
}

int main()
{
	pthread_t thread1,thread_ID;
	int rc;
	struct my_thread t1;
	strcpy(t1.msg,"Structure passed\n");
	
	t1.thread_id = pthread_self();
	printf("Inside main function\n");
	printf("\nMain thread ID : %u",t1.thread_id);
	
	pthread_create(&thread1,NULL,thread,(void *)&t1);
	pthread_exit(NULL);
}
