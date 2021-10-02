#include <iostream>
#include <chrono>
#include "tree.hpp"
using namespace std;

int main(void) {
	Node<int>* root = nullptr;
	root = CreateTree(0);
	root->color = black;

	
	cout << "Enter Number of nodes to create: ";
	int x;
	cin >> x;
	if(x != 0) {
		for(int i = 1; i <= x; i++) {
			root = insert(root, i);
		}
	}


    cout << "Now we find the last node! " << x << endl;
 	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();
	LookUp(root, x); 
	end = chrono::system_clock::now();

	chrono::duration<double, micro> TotalTime = end - start;

	cout	<< "Total Time: " << TotalTime.count() << " microseconds" << endl;
	cout << "Tree Height: " << Height(root) << endl;

	return 0;
}