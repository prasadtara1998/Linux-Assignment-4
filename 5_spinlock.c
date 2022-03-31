#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<bits/types.h>
#include<unistd.h>
#include<errno.h>

static pthread_spinlock_t spinlock;
volatile int slock;


void *spinlockThread(void *t)
{
	int rc;

	printf("%s\n",(char *)t);
	rc = pthread_spin_lock(&spinlock);
	printf("\nThread function got spinlock\n");
	rc= pthread_spin_unlock(&spinlock);
	printf("thread complete\n");
	return NULL;
}

int main()
{
	int rc;
	pthread_t thread,thread1;

	if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0)
	{
		perror("init");
	}


	printf("spin lock\n");
	rc = pthread_spin_lock(&spinlock);

	
	pthread_create(&thread,NULL,spinlockThread,(int *)"Entered thread function");

	printf("Waiting....\n");
	sleep(5);

	printf("Spin unlock\n");
	rc = pthread_spin_unlock(&spinlock);

	if(rc==0)
	{
		printf("\nSuccessfully unlocked\n");
	}
	else
	{
		printf("\n UnSuccessfully unlocked\n");
	}

	printf("Waiting...\n");
	rc = pthread_join(thread,NULL);
	printf("main complete\n");
	return 0;

}
