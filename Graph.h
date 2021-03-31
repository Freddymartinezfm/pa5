#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include "list.h"
#include <vector>
#include "IntFiniteQueue.h"
class Graph  {
public:
	Graph();
	Error_code insert(int, int, int);
	Error_code remove(int, int);
	void read(const std::string&);
	void bfs();
	void dfs();
	void topological_sort();
	void reset() ;
	void init(int);
	double num_vertices();
	double edges();
	void display();
	double avg_node_degree();
	void dijkstra(int s);
	void prims(int s);
	void print_paths(int [], int);
	void cut_link(int, int);
	void iterative_deepening();
private:
	State state[14];
	int w(Node *) const;
	int *parent;
	void order(int []);
	void dfs_from_vertex(Graph&, int);
	void iterative_dfs_from_vertex(Graph&, int);
	void sort_from_vertex(Graph&, int);
	void dijkstra(Graph&, int);
	void prims(Graph&, int);
	int size;
	int *visited;
	std::string  file_name;
	std::vector<int> sequence;
	int count;
	list **vertices;
	list *ts_stack;
	double node_degree;
	void relax(Node *, Node *, int);
	void relax(int, int, int);
	list successors(int index);

	
	friend class Entry;
};



#endif