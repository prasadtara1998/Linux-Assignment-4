#include<stdio.h>
#include<pthread.h>

void main()
{

	pthread_t tid;
	struct sched_param param;
	int priority,policy,ret;

	ret = pthread_getschedparam (pthread_self(),&policy,&param);
	printf("\n----------------Main Thread--------------\n Policy : %d\t Priority : %d \n",policy,param.sched_priority);
	policy = SCHED_RR;
	param.sched_priority = 2;
	ret = pthread_setschedparam (pthread_self(),policy,&param);
	if(ret!=0)
	{
		perror("getschedparam");
	}
	
	ret = pthread_getschedparam (pthread_self(),&policy,&param);
	if(ret!=0)
	{
		perror("getschedparam");
	}
	printf("\n----------------Main Thread--------------\n Policy : %d\t Priority : %d \n",policy,param.sched_priority);
}
