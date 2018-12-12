#include <types.h>
#include <mazer.h>
#include <test.h>

node* nodes;
tree theTree;
unsigned short qty;
unsigned short start[2];
unsigned short end[2];

unsigned short points[][2] = 
	{{ 2,0 },
	 { 0,1 },
	 { 2,1 }};
unsigned short ptsQty = 3;

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
	start[0] =  0;
	start[1] = 0;
	end[0] =  2;
	end[1] = 2;
	
	// initialise the start and end points
	initNode(&nodes[0], 0, start[0], start[1], NULL, NULL, NULL, NULL);
	initNode(&nodes[1], 2,   end[0],   end[1], NULL, NULL, NULL, NULL);
	
	// make the tree with the first 2 elements of nodes, 
	makeTree(&theTree, &nodes[0], &nodes[1]);
	
	// printf("The first node is at (%i,%i)\n", theTree.start->x, theTree.start->y);
	// printf("The size of nodes is %i\n", sizeof(nodes));
	reallocarray(nodes, 5, sizeof(node) * 5); 

	//initNode(&nodes[2], 1, 2, 0, NULL, &nodes[4], theTree.start, NULL);
	//initNode(&nodes[3], 1, 0, 1, theTree.start, NULL, NULL, &nodes[4]);
	//initNode(&nodes[4], 1, 2, 1, &nodes[2], theTree.end, &nodes[3], NULL);
	//qty = 5;

	makeNodes(&nodes, ptsQty, 0, points);
	printNodes(&nodes, qty);

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
	theNode->type = type;
	theNode->x = x;
	theNode->y = y;
	theNode->up = up;
	theNode->down = down;
	theNode->left = left;
	theNode->right = right;
}

void initNodes( node** theNodes ) {
	char num = 2;
	*theNodes = malloc(sizeof(node) * num);
	if (!theNodes) {
		perror("Error allocating memory");
		abort();
	}
	memset(*theNodes, 0, sizeof(node) * num);
}

void makeNodes( node** nodesPtr, unsigned short ptsQty, 
		unsigned short offset, unsigned short points[ptsQty][2] ) {
	printf("entering makeNodes");
	if(offset == ptsQty-1) {
		return;
	}
	reallocarray(*nodesPtr, (qty+offset+1), sizeof(node)*(qty+offset+1));
	printf("reallocated");

	initNode(nodesPtr[qty+offset-1], 1, 
			points[offset][0], 
			points[offset][1],
			NULL, NULL, NULL, NULL );

	findLinks(nodesPtr[qty+offset-1]);
	makeNodes(nodesPtr, ptsQty, offset + 1, points);
}

void findLinks( node* node ) {
	printf("Finding links for node at (%u,%u)\n", node->x, node->y);
	return;
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
