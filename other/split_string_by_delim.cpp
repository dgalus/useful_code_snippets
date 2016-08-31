#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

template<typename T, typename U>
auto add(T t, U u) -> decltype(t+u)
{
	t++;
	u--;

	return t+u;
}

class String {
	std::string s;
public:
	String(const std::string &s) : s(s) { }

	String to_lower_copy() const {
		return { boost::to_lower_copy(s) };
	}

	std::vector<String> split(const std::string& delimeter = " ") const {
		std::vector<std::string> parts;
		boost::split(parts, s, boost::is_any_of(delimeter), boost::token_compress_on);
		return std::vector<String>(parts.begin(), parts.end());
	}

	size_t get_length() const { return s.length(); }
};

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	int a = 1;
	std::cout << add(a, 2) << std::endl;


	std::string s{"Hello   world!"};
	std::string s1 = boost::to_lower_copy(s);
	std::vector<std::string> parts;
	boost::split(parts, s1, boost::is_any_of(" "), boost::token_compress_on);
	for(auto& p : parts)
	{
		std::cout << p.length() << std::endl;
	}


	String s2 { "Hello     world!" };
	for(auto& w : s2.to_lower_copy().split())
	{
		std::cout << w.get_length() << std::endl;
	}

	return 0;
}
