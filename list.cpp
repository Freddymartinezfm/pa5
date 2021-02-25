#include "list.h"
#include "Node.h"
#include <cassert>
#include <iostream>

list::list() : head(nullptr), tail(nullptr), count(0) { }

void list::display() const {
	if (head == nullptr) {
		return;
	} else {
		Node *t = head;
		while (t != nullptr){
			t->data->display(std::cout);
			t = t->next;
		}
	}
}


int list::num_nodes() const {
	assert(count > 0);
	return count;
}


void list::push_front(int entry, int w , Node*next_node){
	Node *new_node = new Node(entry,w,  next_node);
	if (head == nullptr && tail == nullptr) {
		head = tail =  new_node;
		count++;
	} else {
		new_node->next = head;
		head = new_node;
		count++;
	}
}

void list::push_back(int entry, int w,  Node * next_node){
	Node *new_node = new Node(entry, w,  next_node);
	if (head == nullptr && tail == nullptr) {
		head = tail =  new_node;
		count++;
	} else if (head->next == nullptr) {
		head->next = new_node;
		tail = new_node;
		count++;
	} else {
		tail->next = new_node;
		count++;
	}
}

void list::remove(int e){
	Node *curr = head;
	Node *prev = head;

	for (int i = 0; i < count; i ++){
		if (curr->data->key == e){
			if (i == 0){
				head = head->next;
				
			} else if (i == count) {
				std::cout << "end of list";
				prev->next = nullptr;
				
			} else {
				prev->next = curr->next;
				
			}
		}
		prev = curr;
		curr = curr->next;
	}
}

