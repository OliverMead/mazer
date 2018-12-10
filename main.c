#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int main(void) {
	node myNode;
	node* nodes[4] = { NULL, NULL, NULL, NULL };
	initNode(&myNode, 0, 0, 0, nodes[0], nodes[1], nodes[2], nodes[3]);
	printf("Size of myNode = %i\n", sizeof(myNode));
	printf("%i, %i, %i, %x, %x, %x, %x\n",
			myNode.type, 
			myNode.x, myNode.y,
			myNode.up, myNode.down,
			myNode.left, myNode.right
	      );
	printf("Size of tree datatype: %i\n", sizeof(tree));
	printf("Size of node*: %i\n", sizeof(node*));
	printf("Size of nodes array: %i\n", sizeof(nodes));
	
	node node2;
	initNode(&node2, 2, 0, 1, &myNode, NULL, NULL, NULL);
	//printf("Distance: %d\n", distBetween(&myNode, &node2)); 
	tree myTree;
	makeTree(&myTree, &myNode, &node2);
	printf("Distance: %i\n", distBetween(myTree.start, myTree.end));
	return 0;
}

void makeTree( tree* theNode,
		node* start,
		node* end
	     ) {
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

double distBetween(node* node1, node* node2) {
	// the distance between two nodes 
	// (in this case dx + dy because the nodes 
	// exist only on a grid)
	double theDist;
	int dx = node2->x - node1->x;
	int dy = node2->y - node1->y;
	theDist = sqrt(dx*dx+dy*dy);
	return theDist;
}
