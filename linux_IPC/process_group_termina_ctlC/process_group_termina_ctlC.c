#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//system()函数导致执行 system() 的进程收不到 SIGINT 信号

sem_t *sem;
pid_t pid;

void ch_sig_f(int sig_no)
{
	printf("ch sig f!\n");
	exit(1);
}
void fa_sig_f(int sig_no)
{
	printf("fa sig f!\n");
	exit(1);
}

int main(int argc,char* argv[])
{
	int stat;
	pid = fork();
	if(0 == pid){
		printf("child getpid() = %d\n",getpid());
		system("./test.sh");
	}
	else if(pid < 0){
	}
	else{
		signal(SIGINT,fa_sig_f);
		printf("father getpid() = %d\n",getpid());
		wait(&stat);
	}	
	return 1;

}
