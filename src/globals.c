#include <types.h>
#include <globals.h>
#include <mazer.h>

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

direction* path;

