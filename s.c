#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av){
	
	pid_t x;

	x = fork();

	while(x > 0)
		execve("/bin/ls",av,NULL);
	if (x == 0)
	{
		printf("hello");
	}
	wait(NULL);
	return 0;
}
