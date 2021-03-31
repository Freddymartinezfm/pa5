#include "Graph.h"
#include <iostream>
#include "Node.h"
#include "math.h"
#include <cassert>
#include <fstream>
#include <string>


void Graph::iterative_deepening(){
	std::cout << std::endl;
	std::cout << "===== Iterative Deepening DFS =====" << std::endl;	
	list w =  successors(14);
	// w.display();

	std::cout << "data: " <<  w.head->data->get_key() << "\n";
	std::cout << "weight: " <<  w.head->data->get_weight();


		
}

void Graph::iterative_dfs_from_vertex(Graph &G, int u) {


		/* code */
	
}


list Graph::successors(int index){
	list succ;
	return *vertices[index];

}








































/**
 * expierementation above
 * @brief pa5 below
 */

Graph::Graph()
{}

void Graph::read(const std::string & fn){
	Error_code result = success;
	std::ifstream in_file;
	file_name = fn;
	in_file.open(file_name, std::ios::in);
	int from, to, weight;
	in_file >> size;
	
	init(size + 1); // exclude index 0
	ts_stack = new list();

	while (in_file >> from >> to >> weight)
		insert(from, to , weight);	
}


void Graph::cut_link(int from, int to){
	try {
		Error_code result =  remove(from, to);
	} catch (std::string &e){
		std::cerr << "Remove includes invalid arguments. Please restart. " << std::endl;
		std::cerr << e << std::endl;
		throw 2;
		
	}

}

void Graph::display(){
	std::cout << std::endl;
	std::cout << "===== R1, R2 =====" << std::endl;
	for (int i = 1; i < size; i++) {
		std::cout << "[" << i  << ":"<< vertices[i]->count << "] - >";
		vertices[i]->display();
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << "Node count: " << num_vertices() << std::endl;
	std::cout << "Edge count: " << edges() << " X 2 "  <<  std::endl;
	std::cout << "Average node degree: " << avg_node_degree() << std::endl << std::endl;
}

void Graph::order(int A[]){
	std::cout << "Sequence of node visits: ";
	for (int i = 1; i < size; i++)
		std::cout  << A[i] << " ";
	std::cout  << std::endl;
}

void Graph::bfs(){
	std::cout << "===== R7: BFS =====" << std::endl;
	IntFiniteQueue *q = new IntFiniteQueue(size - 1);
	visited[0] = false;
	int d = 1;
	for (int v = 1; v < size; v++) {
		Node *V =  vertices[v]->head;
		if (visited[v] == false) {
			visited[v] = true;
			q->enqueue(v);
			while (!q->isEmpty()){
				sequence.push_back(q->front());
				int p = q->front();
				Node *u = vertices[p]->head;
				for (; u != nullptr; u = u->next) {
					if (visited[u->data->key] == false){
						std::cout << p << "-> " << w(u) << std::endl;
						visited[u->data->key] = true;
						q->enqueue(u->data->key);

					}
				}
				q->dequeue();
			}
		}
	}
	order(sequence.data() - 1);
	std::cout << std::endl;
	ts_stack->display();
	


}

void Graph::dfs(){
	std::cout << std::endl;
	std::cout << "===== R8 DFS =====" << std::endl;	
	for (int i = 0; i < size; i++) visited[i] = false;
	for (int v = 1; v < size; v++) {
		if (visited[v] == false)
			dfs_from_vertex(*this, v);
	}
	order(sequence.data() - 1);
	std::cout << std::endl;
	reset();
}

void Graph::dfs_from_vertex(Graph &G, int u) {
	visited[u] = true;
	sequence.push_back(u);
	Node *w = vertices[u]->head;
	for (; w != nullptr; w = w->next) {
		if (visited[w->data->key] == false){
			std::cout << u << "-> " << w->data->key << " : " << w->data->weight << std::endl;
			dfs_from_vertex(*this, w->data->key);
		}
	}	
}

int Graph::w(Node * n) const { return n->data->weight; }

void Graph::topological_sort(){
	std::cout << std::endl;
	std::cout << "===== topological_sort" << "=====" << std::endl;	
	for (int i = 0; i < size; i++) state[i] = State::unvisited;
	for (int v = 1; v < size; v++)
		if (state[v] == unvisited)
			sort_from_vertex(*this, v);
		
	Node *t = ts_stack->head;
	while (t != nullptr) {
		std::cout << t->data->key;
		t = t->next;
	}
	std::cout << std::endl;
	reset();
}

void Graph::sort_from_vertex(Graph &G, int v) {
	state[v] = State::visited;
	Node *w = vertices[v]->head;
	for (; w != nullptr; w = w->next) {
		if (state[w->data->key] == unvisited && state[w->data->key] != finished)
			sort_from_vertex(*this, w->data->key);
		else if (state[w->data->key] == State::visited) {
			std::cout << "Cycle detected or graph is undirected " << std::endl;
		}
	}
	state[v] = State::finished;
	ts_stack->push_back(v);
}

void Graph::reset() {
	sequence.clear();
	for (int i = 0; i < size; i++) {
		vertices[i] = new list();
		visited[i] = 0;
		state[i] = State::unvisited;
	}
	count = 0;
	node_degree = 0; 
	read(this->file_name);
}

void Graph::relax(Node *, Node *, int){
	// TODO
}

void Graph::dijkstra(int s) { 
	dijkstra(*this, s);
	reset(); 
}

void Graph::dijkstra(Graph &G, int s) {
	std::cout << "Shortest paths from node 1: " << std::endl;
	int d [size];
	int p [size];
	bool c [size];
	for (int i = 0; i < size; i++) d[i] = 99999;
	for (int i = 0; i < size; i++) p[i] = -1;
	for (int i = 0; i < size; i++) c[i] = false;
	d[s] = 0;
	p[s] = -1;
	// c[s] = true;
	int x = 1;
	int m = 0;
	int min_index;
	for (int w = 1; w < size; w++) { // while V - C that offers min dist, overall iteration of all V's
		while (c[w] == false){ // V - C 
			// find min and set it to true
			int i = w;
			min_index = i;
			m = d[min_index];
			 for (; i < size-1; i++) {
				 if ( c[i+1] == false && d[i+1] < m){
					 m = d[i +1];
					 min_index = i +1; 
				 }
			 }
			Node *t = vertices[min_index]->head;
			while (t != nullptr) {
			if (d[min_index] + t->data->weight < d[t->data->key]){
				d[t->data->key] = d[min_index] +  t->data->weight;
				p[t->data->key] = min_index;
 			}
			t = t->next;
			}
			c[min_index] = true;
			
		}
	}

	int source = 1;
	int total_sp_distance = 0;
	for (int i = 2; i < size; i++) {
		std::cout << source << " -> "; 
		print_paths(p, i);
		total_sp_distance += d[i];
		std::cout << d[i] << std::endl;

	}

	std::cout << "SP count: " << size - 1 - source << std::endl;
	std::cout << "Total SP distance: " << total_sp_distance << std::endl;
	std::cout << "Average SP distance: " << static_cast<double>(total_sp_distance) / (size - 1 - source)  << std::endl;
	std::cout << std::endl;
	
}


void Graph::prims(int s) { 
	prims(*this, s);
	reset();
	
}

void Graph::prims(Graph &G, int s) {
	std::cout << "Minimum Spanning Tree: " << std::endl;
	int parent [size];
	int d [size];
	for (int i = 0; i < size; i++) d[i] = 99999;
	d[s] = 0;
	parent[s] = -1;
	int C[size];
	int min = 0;
	int min_index = 0;
	
	for (int v = 1; v < size ; v++) {

		min = d[v];
		min_index = v;
		if (visited[v] == false) {
			for (int i = v + 1; i < size; i++) {
					if (min > d[i]) {
						min = d[i];
						min_index = i;
					} else  { 
						continue;
					}
				}
		visited[min_index] = true;
		Node *t = vertices[min_index]->head;
		while (t != nullptr) {
			if (t->data->weight < d[t->data->key] && visited[t->data->key] == false){
				d[t->data->key] = t->data->weight;
				parent[t->data->key] = min_index;
 			}
			t = t->next;
			}
		}	
	}

	int source = 1;
	int edge_count = 0;
	int total_cost = 0;
	int i = 0;
	for (i = 2; i < size; i++) {
		std::cout << i << " - ";
		std::cout << parent[i] << " ";
		std::cout << d[i] << std::endl;
		total_cost += d[i];
	}
	std::cout << "Node count: " << num_vertices() << std::endl;
	std::cout << "Edge count: " << i - 1 - source <<  std::endl;
	std::cout << "Total distance (cost): " << total_cost << std::endl << std::endl;
	
}

void Graph::print_paths(int p[], int j){
	if (p[j] == -1)
		return;
	print_paths(p, p[j]);
	std::cout << j << " -> ";
}

Error_code Graph::remove(int from, int to){
	Error_code result = success;
	std::cout << "Removing: (" << from << ", " << to << ") " << std::endl; 
	std::cout << "Removing: (" << to << ", " << from << ") " << std::endl;
	// try catch exception 
	if (size < from || from < 1) throw std::string("invalid 'from' "  + from);
	if (size < to || to < 1) throw std::string("invalid to");
	vertices[from]->remove(to);
	count -= 1;
	vertices[to]->remove(from);
	count -= 1;
	return success;
	
}

double Graph::num_vertices() { return size -1; }

double Graph::edges(){ return count; }

double Graph::avg_node_degree(){
	double total = 0.0;
	for (int i = 0; i < size; i++) {
		if (vertices[i]->head != nullptr) {
			total += vertices[i]->count;
		}
	}
	return total/(size - 1);
}

void Graph::init(int size){
	this-> size = size;
	vertices = new list*[size];
	visited = new int[size];
	for (int i = 0; i < size; i++) {
		vertices[i] = new list();
		visited[i] = 0;
		state[i] = State::unvisited;
	}
	count = 0;
	node_degree = 0;

}

Error_code Graph::insert(int from, int to, int weight) {
	Error_code result = success;
	vertices[from]->push_front(to, weight);
	vertices[to]->push_front(from, weight);
	count += 1;
	return success;
}




