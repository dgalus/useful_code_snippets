#ifndef FACTORIAL_H_
#define FACTORIAL_H_

template <size_t n> struct fact;

template<> struct fact<0> {
	const static auto value = 1;
};

template<size_t n> struct fact {
	const static auto value = n*fact<n-1>::value;
};

/** Usage:
* void example(){ std::cout << fact<5>::value; }
*/

#endif
