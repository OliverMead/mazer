#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void initNodes
( 
 	node** theNodes
);

void makeNodes
(
 	node**, 
	unsigned short ptsQty, 
	unsigned short offset,
	unsigned short points[ptsQty][2]
);

void findLinks ( node* );

double distBetween(node*, node*);

void testNodes();

#endif
