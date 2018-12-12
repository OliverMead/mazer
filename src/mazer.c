#include <types.h>
#include <mazer.h>
#include <test.h>

node* nodes;
tree theTree;
unsigned short qty;
unsigned short start[2];
unsigned short end[2];

//		    [y][x]
unsigned char layout[5][5] =
	{{ 1,0,1,1,1 },
	 { 1,0,1,0,1 },
	 { 1,0,0,0,1 },
	 { 1,0,1,0,1 },
	 { 1,1,1,0,1 }};

unsigned short ptsQty = 4;

//	 { x,y }
unsigned short points[][2] = 
	{{ 3,1 },
	 { 1,2 },
	 { 3,2 },
	 { 1,3 }};

int main(void) {
	//testNodes();
	
	// initialise the array of nodes
	initNodes(&nodes);
	qty = 2;

	// start and end points
	start[0] =  1;
	start[1] = 0;
	end[0] =  3;
	end[1] = 4;
	
	// initialise the start and end points
	initNode(nodes+0, 0, start[0], start[1], NULL, NULL, NULL, NULL);
	initNode(nodes+1, 2,   end[0],   end[1], NULL, NULL, NULL, NULL);
	
	// make the tree with the first 2 elements of nodes, 
	makeTree(&theTree, nodes+0, nodes+1);
	
	// allocate memory for all of the nodes based on the points
	reallocarray(nodes, ptsQty+qty, sizeof(node) * (qty+ptsQty));
	// wipe this memory
	memset(nodes+2, 0, sizeof(node)*ptsQty);

	// create the nodes
	makeNodes(nodes, ptsQty, 0, points);
	// update the number of nodes
	qty += ptsQty;
	
	// link each node to every node it can see
	linkNodes(nodes, qty, 0, 0);
	
	printNodes(&nodes, qty);
	
	//printf("%i\n", nodes[2].up);
	
	assert( theTree.start == nodes );
	assert( theTree.end == nodes + 1);

	assert( theTree.start->down == nodes + 3 );

	return 0;
}


