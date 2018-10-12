#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	pid_t child;
	child = fork();
	
	
	if(child == 0)
	{
		printf("\nchild process");
		printf("\nMy PID=%d",getpid());
		printf("my parent PID=%d",getppid());
		exit(0);
	}
	else
	{
		wait();
		printf("\n parent process");
		printf("\n my pid=%d", getpid());
		printf("\n my child pid=%d",child);
	}

return 0;	
}
