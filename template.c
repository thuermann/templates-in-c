/*
 * $Id: template.c,v 1.2 2014/01/20 09:44:49 urs Exp $
 */

#include <stdio.h>

#define DEFINE(name)				\
	TEMPLATE_ ## name(int)			\
	TEMPLATE_ ## name(float)		\
	TEMPLATE_ ## name(double)

#define foo(type, a, b) foo_ ## type(a, b)
#define TEMPLATE_foo(type)			\
void foo(type, type *a, int b)			\
{						\
	*a = bar(type, *a, b);			\
}

#define bar(type, a, b) bar_ ## type(a, b)
#define TEMPLATE_bar(type)			\
type bar(type, type a, type b)			\
{						\
	type tmp = a + b;			\
	return tmp;				\
}

DEFINE(bar)
DEFINE(foo)

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
