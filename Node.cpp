
#include "Node.h"
#include <iostream>
#include <string>
#include <iomanip>
const static std::string TAG {"Node"};

Node::Node(){
	data = nullptr;
}
Node::Node(int d, int w, Node *nextNode = nullptr){
	// Log::m(TAG, "Node(string, Node*)", this);
	data = new Edge(d, w);
	this->next = nextNode;
	
}

Node::Node(Node *n){
	// Log::m(TAG, "Node(string, Node*)", this); copy constructor

	data = new Edge(n->data->key, n->data->weight);
}

Node::~Node(){
	//Log::m(TAG, "~Node()", this);
	
}


