/*
 * $Id: template.c,v 1.2 2014/01/20 09:44:39 urs Exp $
 */

#include <stdio.h>

#define DEFINE(name, type) TEMPLATE_ ## name(type)

#define add_to(type, a, b) add_to_ ## type(a, b)
#define TEMPLATE_add_to(type)			\
void add_to(type, type *a, int b)		\
{						\
	*a = add(type, *a, b);			\
}

#define add(type, a, b) add_ ## type(a, b)
#define TEMPLATE_add(type)			\
type add(type, type a, type b)			\
{						\
	type tmp = a + b;			\
	return tmp;				\
}

/* Define the functions for each instantiation */
DEFINE(add, int)
DEFINE(add, float)
DEFINE(add, double)

/* We can also use DEFINE() in another macro */
#define DEFINE_MULTI(name)	\
	DEFINE(name, int)	\
	DEFINE(name, float)	\
	DEFINE(name, double)
DEFINE_MULTI(add_to)

int main(void)
{
	int    i = 10;
	float  f = 10;
	double d = 10;

	add_to(int,    &i, 1);
	add_to(float,  &f, 2);
	add_to(double, &d, 3);
	printf("%d %f %f\n", i, f, d);

	return 0;
}
