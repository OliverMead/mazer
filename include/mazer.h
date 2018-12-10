#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node node;
typedef struct Tree tree;

struct Node {
	 // type - (0 : start) (1 : any) (2 : end)
	unsigned char type : 2;
	unsigned short x;
	unsigned short y;
	node* up;
	node* down;
	node* left;
	node* right;
};


struct Tree {
	node* start;
	node* end;
};

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

#endif
