/*
 * $Id: template.c,v 1.1 2014/01/17 13:08:49 urs Exp $
 */

#include <stdio.h>

#define DEF(name)				\
	def_ ## name(int)			\
	def_ ## name(float)			\
	def_ ## name(double)

#define foo(type, a, b) foo_ ## type(a, b)
#define def_foo(type)				\
void foo(type, type *a, int b)			\
{						\
	*a = bar(type, *a, b);			\
}

#define bar(type, a, b) bar_ ## type(a, b)
#define def_bar(type)				\
type bar(type, type a, type b)			\
{						\
	type tmp = a + b;			\
	return tmp;				\
}

DEF(bar)
DEF(foo)

int main(void)
{
	int    i = 10;
	float  f = 10;
	double d = 10;

	foo(int,    &i, 1);
	foo(float,  &f, 2);
	foo(double, &d, 3);
	printf("%d %f %f\n", i, f, d);

	return 0;
}
