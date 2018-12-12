#include <types.h>
#include <mazer.h>
#include <test.h>

void testNodes() {
	node myNode;
	node* nodes[4] = { NULL, NULL, NULL, NULL };
	initNode(&myNode, 0, 0, 0, nodes[0], nodes[1], 
			nodes[2], nodes[3]);
	printf("Size of myNode = %i\n", sizeof(myNode));
	printf("%i, %i, %i, %x, %x, %x, %x\n",
			myNode.type, 
			myNode.x, myNode.y,
			myNode.up, myNode.down,
			myNode.left, myNode.right
	      );
	printf("Size of tree datatype: %i\n", 
			sizeof(tree));
	printf("Size of node*: %i\n", sizeof(node*));
	printf("Size of nodes array: %i\n", 
			sizeof(nodes));
	
	node node2;
	initNode(&node2, 2, 0, 1, &myNode, 
			NULL, NULL, NULL);
	//printf("Distance: %d\n", distBetween(&myNode, &node2)); 
	tree myTree;
	makeTree(&myTree, &myNode, &node2);
	printf("Distance: %f\n", distBetween(myTree.start, 
				myTree.end));
}

void printNodes(node** nodesPtr, unsigned short qty) {
	for (int i = 0; i < qty; i++) {
		printf(
		"Node %u:\t type %u, position (%u,%u)\n", 
			i,
			(*nodesPtr)[i].type, 
			(*nodesPtr)[i].x, 
			(*nodesPtr)[i].y);
		printf(
		"\t Connects to \n\t\t%p, %p, \n\t\t%p and %p\n\n",
				(*nodesPtr)[i].up,
				(*nodesPtr)[i].down,
				(*nodesPtr)[i].left,
				(*nodesPtr)[i].right);
	}
}
