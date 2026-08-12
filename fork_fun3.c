#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkeg()
{
	if(fork()==0)
		printf("hello from child \n");
		
	else 
		printf("hello from parent \n");
}
int main()
{
	forkeg();
	return 0;
}
