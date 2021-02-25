#include "Edge.h"
#include "Node.h"
#include "utility.h"
#include <vector>

// enum Status  {visited, unvisited, empty};
class list {
private:
	Node *head;
	Node *tail;
	std::vector<int> order;
	int count;
	// Status status;
public:
	list();

	list(std::string &);
	void push_front(int to = 0, int w = 0, Node *next_node = nullptr);
	void push_back(int to = 0, int w = 0,  Node*next_node = nullptr);
	void remove(int entry);
	Error_code pop_front( std::string &, Node * head);
	int num_nodes() const;
	void display() const;
	friend class  Graph;
	
	


};