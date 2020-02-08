#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
    int a=rdtsc();
	sleep(1);

	int b=rdtsc();

	printf("total cycles = %d", b-a);
	return 0;
} 
