#ifndef NODE_TYPES_HEADER
#define NODE_TYPES_HEADER

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

#endif
