#include "main.h"
int main()
{
	char *str = "ait";
	int p;
	p = _printf("youssef %s gouraine\n", str);
	printf("%d\n", p);
	p = _printf("youssef %% ait %cgouraine\n", 'g');
	printf("%d\n", p);
	p = _printf("%m", str);
	printf("%d\n", p);
	printf("error : %\n", str);
}
