#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include "Edge.h"



class Edge {
private:
	int key;
	int weight;
	
public:
	Edge();
	Edge(int, int);
	auto get_key() -> int;
	auto get_weight() -> int;
	auto display(std::ostream&) -> void;

	friend class Graph;
	friend class list;
	friend class Node;
	
};


#endif