#include <types.h>
#include <mazer.h>
#include <test.h>

node* nodes;
tree theTree;
unsigned short qty;
unsigned short start[2];
unsigned short end[2];

unsigned char layout[5][5] =
	{{ 1,0,1,1,1 },
	 { 1,0,1,0,1 },
	 { 1,0,0,0,1 },
	 { 1,0,1,0,1 },
	 { 1,1,1,0,1 }};

unsigned short ptsQty = 4;
unsigned short points[][2] = 
	{{ 3,1 },
	 { 1,2 },
	 { 3,2 },
	 { 1,3 }};

int main(void) {
	//testNodes();
	
	// The layout of this test:
	// s x n
	// n x n
	// x x e
	
	// initialise the array of nodes
	initNodes(&nodes);
	qty = 2;

	// start and end points
	start[0] =  1;
	start[1] = 0;
	end[0] =  4;
	end[1] = 5;
	
	// initialise the start and end points
	initNode(nodes+0, 0, start[0], start[1], NULL, NULL, NULL, NULL);
	initNode(nodes+1, 2,   end[0],   end[1], NULL, NULL, NULL, NULL);
	
	// make the tree with the first 2 elements of nodes, 
	makeTree(&theTree, nodes+0, nodes+1);
	
	// printf("The first node is at (%i,%i)\n", theTree.start->x, theTree.start->y);
	// printf("The size of nodes is %i\n", sizeof(nodes));
	reallocarray(nodes, ptsQty+qty, sizeof(node) * (qty+ptsQty)); 
	memset(nodes+2, 0, sizeof(node)*ptsQty);

	//initNode(&nodes[2], 1, 2, 0, NULL, &nodes[4], theTree.start, NULL);
	//initNode(&nodes[3], 1, 0, 1, theTree.start, NULL, NULL, &nodes[4]);
	//initNode(&nodes[4], 1, 2, 1, &nodes[2], theTree.end, &nodes[3], NULL);
	//qty = 5;

	makeNodes(nodes, ptsQty, 0, points);
	qty += ptsQty;
	printNodes(&nodes, qty);

	printf("%i\n", nodes[2].up);

	return 0;
}

void makeTree( tree* theNode, node* start, node* end ) {
	theNode->start = start;
	theNode->end = end;
}

void initNode(	node* theNode, unsigned char type,
		unsigned short x, unsigned short y,
		node* up, node* down, 
		node* left, node* right ) {
	// create a node at memory location theNode
	theNode->type = type;
	theNode->x = x;
	theNode->y = y;
	theNode->up = up;
	theNode->down = down;
	theNode->left = left;
	theNode->right = right;
}

void initNodes( node** theNodes ) {
	// initialise the array of nodes for just the start and end nodes
	char num = 2;
	*theNodes = malloc(sizeof(node) * num);
	if (!theNodes) {
		perror("Error allocating memory");
		abort();
	}
	memset(*theNodes, 0, sizeof(node) * num);
}

void makeNodes( node* nodes, unsigned short ptsQty, 
		unsigned short offset, unsigned short points[ptsQty][2] ) {
	// function to create all of the required nodes, 
	// memory must already be allocated for nodes
	if(offset == ptsQty) {
		return;
	}
	printf("Initialising node %i\n", qty+offset+1);
	initNode((nodes + qty+offset), 1, 
			*(*(points + offset)+0), 
			*(*(points + offset)+1),
			NULL, NULL, NULL, NULL );

	findLinks(nodes + qty+offset);
	makeNodes(nodes, ptsQty, offset + 1, points);
}

void findLinks( node* node ) {
	// find all of the nodes that node can see and 
	//printf("Finding links for node at (%u,%u)\n", node->x, node->y);
	return;
}

char canSee( node* node1Ptr, node* node2Ptr ) {
	
}


double distBetween(node* node1, node* node2) {
	// the distance between two nodes 
	// (in this case dx + dy because the nodes 
	// exist only on a grid)
	double theDist;
	int dx = node2->x - node1->x;
	int dy = node2->y - node1->y;
	theDist = sqrt((double) (dx*dx+dy*dy));
	return theDist;
}
