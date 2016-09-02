#include <future>

int func()
{
	int some_value = 0;

	// do something

	return some_value;
}


int main()
{
	std::future<int> result_future = std::async(func);

	// do something

	int result = result_future.get();
	return 0;
}
