#include <vector>
#include <sstream>
#include <iterator>

int main()
{
	std::istringstream stream{"4 2 5 1 34"};
	std::vector<int> values;
	std::copy(std::istream_iterator<int>{stream}, std::istream_interator<int>{}, std::back_inserter(values));
}
