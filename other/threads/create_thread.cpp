#include <thread>
#include <iostream>

void hello()
{
	std::cout << "Hello world!" << std::endl;
}

int main()
{
	std::thread t(hello);
	t.join();
	std::thread t2(
		[](){
			std::cout << "Z t2!" << std::endl;
	});
	t2.join();
}
