#include<stdio.h>
main(){
	int pid;
	pid=fork();
	if(pid<0){
		printf("fork failed");}
	else if(pid==0){
		printf("child Process\n");
		printf("child pid=%d and it's parent pid =%d\n",getpid()
		,getppid());}
	else{
		printf("parent process\n");
		printf("parent pid=%d and it's parent pid =%d\n",getpid()
			,getppid());
	}
}
