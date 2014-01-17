/*
 * $Id: template.c,v 1.1 2014/01/17 13:08:49 urs Exp $
 */

#include <stdio.h>

#define DEF(name, type) def_ ## name(type)

#define add_to(type, a, b) add_to_ ## type(a, b)
#define def_add_to(type)			\
void add_to(type, type *a, int b)		\
{						\
	*a = add(type, *a, b);			\
}

#define add(type, a, b) add_ ## type(a, b)
#define def_add(type)				\
type add(type, type a, type b)			\
{						\
	type tmp = a + b;			\
	return tmp;				\
}

/* Define the functions for each instantiation */
DEF(add, int)
DEF(add, float)
DEF(add, double)

/* We can also use DEF() in another macro */
#define DEF_MULTI(name) 	\
	DEF(name, int)		\
	DEF(name, float)	\
	DEF(name, double)
DEF_MULTI(add_to)

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
