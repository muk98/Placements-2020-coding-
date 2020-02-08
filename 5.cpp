#include <iostream>
#include <cstdlib>
#include <stdint.h>
 #include <sys/types.h> 
#include <unistd.h> 

//  Windows
#ifdef _WIN32
 
#include <intrin.h>
uint64_t rdtsc(){
    return __rdtsc();
}
 
//  Linux/GCC
#else
 
uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}
 
#endif

int main() 
{ 
    int a=rdtsc();
	sleep(1);

	int b=rdtsc();

	sleep(1);
	int c = rdtsc();
	printf("total cycles = %d %d", b-a,c-b);
	return 0;
} 
