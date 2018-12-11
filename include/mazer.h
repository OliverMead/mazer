#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void makeTree
(
 	tree*,
	node*,
	node*
);

void initNode 
(
	node*,
	unsigned char,
	unsigned short,
	unsigned short,
	node*,
	node*,
	node*,
	node*
);

double distBetween(node*, node*);

void testNodes();

#endif
