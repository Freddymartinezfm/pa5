#ifndef NODE_H
#define NODE_H

#include <string>
#include "Edge.h"
#include "Node.h"
#include <string>



class Node {
private:
	Edge *data;
	
	Node *next;
public:
	Node();
	// Node(const std::string &);
	Node(int, int,  Node*);
	~Node();
	Node (Node*);
	friend class list;
	friend class Graph;

};


#endif