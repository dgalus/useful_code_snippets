#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> nums = {1,2,3,4,5,6,5,4,3,2,1};
	int count = std::count(std::begin(nums), std::end(nums), 3);

}
