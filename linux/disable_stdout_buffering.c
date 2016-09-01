#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	return 0;
}
