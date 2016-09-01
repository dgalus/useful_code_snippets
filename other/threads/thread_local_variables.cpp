#include <stdio.h>
#include <thread>

thread_local int thread_var;

void print_thread_var()
{
	printf("[2] Initial thread_var value: %u\n", thread_var);
	thread_var = 8765;
	printf("[3] Changed thread_var value: %u\n", thread_var);
}

int main()
{
	thread_var = 1234;
	printf("[1] Initial thread_var value: %u\n", thread_var);
	std::thread second_thread(print_thread_var);
	second_thread.join();
	printf("[4] Final thread_var value: %u\n", thread_var);
	return 0;
}
