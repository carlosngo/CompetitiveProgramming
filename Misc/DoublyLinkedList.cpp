#include <iostream>
#include<stdlib.h>

using namespace std;

struct Node {
	int n;
	Node *next;
	Node *prev;
}; 

class deque {
	int size;
	Node *start, *end;
	public:
	deque() {
		size = 0;
		start = NULL;
		end = NULL;	
	}
	
	bool empty() {
		return size == 0;
	}
	
	int front() {
		return start->n;
	}
	
	int back() {
		return end->n;
	}
	
	void push_back(int n) {
		Node *cur = new Node;
		cur->n = n;
		cur->next = NULL;
		cur->prev = NULL;
		if (!start) start = end = cur;
		else {
			end->next = cur;
			cur->prev = end;
			end = cur;	
		}
		size++;
	}
	
	void push_front(int n) {
		Node *cur = new Node;
		cur->n = n;
		cur->next = NULL;
		cur->prev = NULL;
		if (!start) start = end = cur;
		else {
			cur->next = start;
			start->prev = cur;
			start = cur;
		}
		size++;
	}
	
	int pop_back() {
		if (!start) return -1;
		else if (start == end) {
			int n = start->n;
			free(start);
			start = NULL;
			end = NULL;
			size--;
			return n;
		}
		int n = end->n;
		Node *cur = end;
		Node *prev = cur->prev;
		prev->next = NULL;
		free(cur);
		end = prev;
		size--;
		return n;
	}
	
	int pop_front() {
		if (!start) return -1;
		else if (start == end) {
			int n = start->n;
			free(start);
			start = NULL;
			end = NULL;
			size--;
			return n;
		}
		Node *cur = start->next;
		Node *prev = start;
		cur->prev = NULL;
		start = cur;
		int n = prev->n;
		free(prev);
		size--;
		return n;
	}
};

int
main() {
	deque q;
	q.push_back(1);
	q.push_front(2);
	q.push_front(5);
	while (!q.empty()) {
		int n = q.front(); q.pop_front();
		cout << n << '\n';
	}
	return 0;
}
