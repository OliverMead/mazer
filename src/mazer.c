#include <types.h>
#include <mazer.h>
#include <test.h>

int main(void) {
	testNodes();
	
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
	theDist = sqrt((double) (dx*dx+dy*dy));
	return theDist;
}
