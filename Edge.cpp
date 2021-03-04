
#include "Edge.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const static std::string TAG {"Edge"};

Edge::Edge() : key(0), weight(0) {}

Edge::Edge(int d, int w){
	key = d;
	weight = w;
}

auto Edge::get_key() -> int {
	return key; 
}

auto Edge::get_weight() -> int {
	return weight; 
}
auto Edge::display(std::ostream& os) -> void {
	os << "[" << key  << "] ";
	
}


