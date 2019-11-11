#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

sem_t *sem;
pid_t pid;
int main(int argc,char *argv[])
{
	pid = fork();
	if(0 == pid){
		sem = sem_open("my_sem",O_CREAT|O_RDONLY,0777);
		if(SEM_FAILED == sem){
			printf("Open|Create sem failed\n");
		}
		while(1){
			int ret = sem_wait(sem);
			if(ret < 0){
				printf("wait sem failed\n");
			}
			printf("Get a sem return,ret = %d\n",ret);
		}
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



