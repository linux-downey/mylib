#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


//该实验证明，进程之间的信号量只会导致线程睡眠，而不会导致整个进程睡眠。sleep 函数也是一样

sem_t *sem;
pid_t pid;
pthread_t test_p;
pthread_t test1_p;

void *test_callback(void *arg)
{
	sem_t *sem = (sem_t*)arg;
	while(1){
		int ret = sem_wait(sem);
		if(ret < 0){
			printf("wait sem failed\n");
		}
		printf("Get a sem return,ret = %d\n",ret);		
	}
}

void *test1_callback(void *arg)
{
	arg = arg;
	while(1)
		printf("I'm running!!\n");
}

int main(int argc,char *argv[])
{
	pid = fork();
	if(0 == pid){
		sem = sem_open("my_sem",O_CREAT|O_RDONLY,0777);
		if(SEM_FAILED == sem){
			printf("Open|Create sem failed\n");
		}
		pthread_create(&test_p,NULL,test_callback,sem);
		pthread_create(&test1_p,NULL,test1_callback,NULL);
		pthread_join(test_p,NULL);	
		pthread_join(test1_p,NULL);	
	}
	else if(pid < 0){
		printf("Fork failed\n");
		exit(-1);
	}
	sem = sem_open("my_sem",O_CREAT|O_WRONLY,0777);
	if(SEM_FAILED == sem){
		printf("Open|Create sem failed\n");
	}
	while(1){
		int ret = sem_post(sem);
		if(ret < 0){
			printf("Post sem failed\n");
		}
		printf("Post sem,ret = %d\n",ret);
		sleep(5);
	}
}





