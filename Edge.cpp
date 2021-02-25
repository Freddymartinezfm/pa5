
#include "Edge.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const static std::string TAG {"Edge"};

Edge::Edge() : key(0), weight(0) {}



Edge::Edge(int d, int w){
	// Log::m(TAG, "Edge(string)", this);
	key = d;
	weight = w;
}

auto Edge::get_key() -> int {
	// std::cout << this->key <<  "  ";
	return key; 
}

auto Edge::get_weight() -> int {
	// std::cout << this->key <<  "  ";
	return weight; 
}




// std::ostream& operator<<(const std::ostream& os, Edge& entry){
// 	std::cout << entry.key << std::endl;
// }


auto Edge::display(std::ostream& os) -> void {
	os << "[" << key  << "] ";
	
}


