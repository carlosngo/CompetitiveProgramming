#include<iostream>


using namespace std;

class heap {
	int capacity = 10;
	int arr[capacity];
	int size = 0;
	
	int getLeftChildIndex(int n) { return 2 * n + 1; }
	int getRightChildIndex(int n) { return 2 * n + 2; }
	int getParentIndex(int n) { return (n - 1) / 2; }	
	
	ensureExtraCapacity() {
		if (size == capacity) capacity *= 2;	
		arr =
	}
	
	int comparator(int a, int b) {
		return a > b;
	}
	
	public:
		bool empty() { return size == 0; }
		
		int top() { return arr[0]; }
		
		void push(int n) {
			
		}
		
		void pop() {
			
		}
	
};

int
main() {
	
	return 0;
}
