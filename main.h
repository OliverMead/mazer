#ifndef MAIN_HEADER
#define MAIN_HEADER

typedef struct Node node;

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

typedef struct Tree tree;

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

int distBetween(node*, node*);

#endif
