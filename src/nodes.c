#include <types.h>
#include <globals.h>
#include <mazer.h>

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
	if(offset >= ptsQty) {
		return;
	}
	printf("Initialising node %i\n", qty+offset+1);
	initNode((nodes + qty+offset), 1, 
			*(*(points + offset)+0), 
			*(*(points + offset)+1),
			NULL, NULL, NULL, NULL );

	makeNodes(nodes, ptsQty, offset + 1, points);
}

void linkNodes( node* nodes, unsigned short qty, 
		unsigned short index1, unsigned short index2 ) {
	if (index1 >= qty) { return; }
	if (index1 != index2)
	{
		if (canSee(nodes + index1, nodes + index2)) {
			if (nodes[index1].y == nodes[index2].y) { // on same row
				if (nodes[index1].x > nodes[index2].x) { // node 1 to right
					// not needed as accounted for by the else 
					// condition at some point in execution
					//nodes[index1].left = &nodes[index2];
					//nodes[index2].right = &nodes[index1];
				} else { // node 2 to right
					nodes[index1].right = &nodes[index2];
					nodes[index2].left = &nodes[index1];
				}
			} else { // in same column
				if (nodes[index1].y > nodes[index2].y) { // node 2 above
					// not needed as accounted for by the else 
					// condition at some point in execution
					//nodes[index1].up = &nodes[index2];
					//nodes[index2].down = &nodes[index1];
				} else { //node 1 above
					nodes[index1].down = &nodes[index2];
					nodes[index2].up = &nodes[index1];
				}
			} 
		}
	}
	if (index2 >= qty - 1) { linkNodes(nodes, qty, index1 + 1, 0); } 
	else { linkNodes(nodes, qty, index1, index2 + 1); }
	
	return;
}

node* nodeAt( unsigned short x, unsigned short y ) {
	printf("checking for node at (%i,%i)\n", x, y);
	for (int i = 0; i < qty; i++) {
		if ( nodes[i].x == x && nodes[i].y == y ) {
			return nodes+i;
		}
	}
	printf("no node at (%i,%i)\n", x, y);
	return NULL;
}

char canSee( node* node1, node* node2 ) {
	//printf("node1 at (%i,%i)\n", node1->x, node1->y);
	//printf("node2 at (%i,%i)\n", node2->x, node2->y);
	if (node1->x == node2->x) {
		//printf("Layout[4][3] = %i\n", layout[4][3]);
		int y;
		int end;
		
		if (node1->y > node2->y) {
			y = node2->y ;
			end = node1->y;
		} else { 
			y = node1->y; 
			end = node2->y;
		}
		//printf("end = %i\n", end);
		
		for (y++; y <end ; y++) {
			//printf("y = %i\n", y);
			if ( layout[y][(node1->x)] == 1 || nodeAt(node1->x,y) != NULL ) {
				//printf("oopx\n");
				return 0;
			} 
		}
		return 1;
	} else if (node1->y == node2->y) {
		int x;
		int end;
		
		if (node1->x > node2->x) {
			x = node2->x;
			end = node1->x;
		} else {
			x = node1->x;
			end = node2->x;
		}
		
		for (x++; x<end; x++) {
			if ( layout[node1->y][x] == 1 || nodeAt(x,node1->y) != NULL ) {
				//printf("oopy");
				return 0;
			}
		}
		return 1;
	} else {
		//printf("oop");
		return 0;
	}
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
