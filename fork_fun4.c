#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkeg()
{
	int x=1;
	
	if(fork()==0)
		printf("\n hello from child x = %d\n",++x);
		
	else 
		printf("\n hello from parent x= %d\n",--x);
}
int main()
{
	forkeg();
	return 0;
}
