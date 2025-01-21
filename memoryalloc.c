#include "jun.h"
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>




void *custommalloc(size_t size){
	// this accesses the top of the heap
	void *top = sbrk(0);
	// this changes the top of the heap to where size is
	void *request = sbrk(size);
	if (request == (void*) -1){
		return NULL; // make sure there is no error
	}
	else{
		assert(top == request); // make sure the thread is safe
		return top;
	}
}


int main(void){
	void *ptr = custommalloc(sizeof(int));
	if (ptr == NULL){
		printf("Memory fail\n");
		return 1;
	}
	else{
		printf('%p',(void *)ptr);
		return 0;
	}
}
