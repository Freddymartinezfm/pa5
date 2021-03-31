/*
pa5 - GRAPHS
*/



#include <fstream>
#include <iostream>
#include <string>
#include "Graph.h"

void menu(int);
void begin(int, char **);


int main(int argc, char **argv){
	begin(argc, argv);
	return 0;
}




void begin(int argc, char ** argv){
	Graph graph;
	if (argc == 1) menu(1);	
	else if (argc == 2) graph.read(std::string(argv[1]));
	if (argc == 5) graph.read("test.txt");;	

	// R1 & R2
	graph.display();
			graph.iterative_deepening();


	try {
		// R3
		// std::cout << "===== R3 - shortest paths from node 1 to all the other nodes ===== " << std::endl; 
		// graph.dijkstra(1);
		
		// // R4
		// std::cout << "\n===== R4 - minimum spanning tree with the starting node 1 =====" << std::endl;
		// graph.prims(1);
			
		// // R5
		// std::cout << "\n===== R5 =====" << std::endl;
		// graph.cut_link(2,4);
		// graph.dijkstra(1);

		// // R6
		// std::cout << "\n===== R6 =====" << std::endl;
		// graph.cut_link(2,4);
		// graph.prims(1);



		// // R7 BFS
		// graph.bfs();

		// graph.reset();

		// // R8 DFS
		// graph.dfs();

		


	} catch (int &s) {
		menu(s);
	} catch (...){
		std::cout << "Unknown Error. " << std::endl;
	}

}
void menu(int state){
	switch (state) {
		case 1:
			std::cerr << "Please include file name: ";
			std::cerr << "example: 'pa5 test_file.txt'";
			std::cerr << std::endl;
			exit(1);
			break;
		case 2:
			std::cerr << "Please enter valid arguments for 'remove()': ";
			std::cerr << std::endl;
			exit(1);
		break;
	}
	
}