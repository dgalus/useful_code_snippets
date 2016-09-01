#include <map>
#include <string>

int main()
{
	std::map<std::string, int> m = {{"a",1}, {"b", 2}, {"c", 3}};
	if(m.count("b"))
	{
		// key "b" exists in m
	}
}
