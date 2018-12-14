#include <types.h>
#include <mazer.h>
#include <globals.h>
#include <test.h>

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

	assert( path == truePath );

	return 0;
}


