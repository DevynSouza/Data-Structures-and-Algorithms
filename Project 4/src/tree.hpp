#include <iostream>
using namespace std;

enum color {red, black};

template <typename T>
struct Data {
	T data;
    Data() = default;
	Data(T t) { data = t; }
	bool operator>(T& t) { return data > t; }
	bool operator<(T& t) { return data < t; }
    bool operator==(T& t) { return data == t; }
};

template <typename T>
struct Node {
	Data<T> value;  //Why does capitalizing the D make crap work?
	bool color;
    Node();
	Node<T> *left, *right, *parent;
};

template <typename T>
Node<T>::Node() {
	left = nullptr;
	right = nullptr;
	parent= nullptr;
}

template <typename T>
Node<T>* CreateTree(const T& stuff) {
	Node<T>* node = new Node<T>;
	node->value.data = stuff;
	return node;
}

//Implement right rotate
//Implement left rotate
//Implement fixviolation
//I need to do insert before anything so that I can rotate

/* 
        c
       / \
      A   D
     / \
        B(z)     
*/

template <typename T>
Node<T>* TreeInsert(Node<T>* root, Node<T>* stuff) {
	if (root == nullptr)
		return stuff;
	if (stuff->value.data < root->value.data) {
		root->left = TreeInsert(root->left, stuff);
		root->left->parent = root;
	} else if (stuff->value.data > root->value.data) {
		root->right = TreeInsert(root->right, stuff);
		root->right->parent = root;
	}
	return root;
}


template <typename T>
Node<T>* insert(Node<T>* root, const T& stuff) {
	Node<T>* node = CreateTree(stuff);
	root = TreeInsert(root, node);
	fixViolation(root, node);
	return root;
}


template <typename T>
void fixViolation(Node<T>*& root, Node<T>*& stuff) {
	Node<T> *parent_stuff = nullptr;
	Node<T> *grant_parent_stuff = nullptr;
	while ((stuff != root) && (stuff->color != black) && (stuff->parent->color == red)) {
		parent_stuff = stuff->parent;
		grant_parent_stuff = stuff->parent->parent;
		if (parent_stuff == grant_parent_stuff->left) {
			Node<T>* uncle_stuff = grant_parent_stuff->right;
			if (uncle_stuff != nullptr && uncle_stuff->color == red) {
				grant_parent_stuff->color = red;
				parent_stuff->color = black;
				uncle_stuff->color = black;
				stuff = grant_parent_stuff;
			} else {
				if (stuff == parent_stuff->right) {
					rotateLeft(root,parent_stuff);
					stuff = parent_stuff;
					parent_stuff = stuff->parent;
				}
				rotateRight(root,grant_parent_stuff);
				swap(parent_stuff->color, grant_parent_stuff->color);
				stuff = parent_stuff;
			}
		} else {
			Node<T>* uncle_stuff = grant_parent_stuff->left;
			if ((uncle_stuff != nullptr) && (uncle_stuff->color == red)) {
				grant_parent_stuff->color = red;
				parent_stuff->color = black;
				uncle_stuff->color = black;
				stuff = grant_parent_stuff;
			} else {
				if (stuff == parent_stuff->left) {
					rotateRight(root,parent_stuff);
					stuff = parent_stuff;
					parent_stuff = stuff->parent;
				}
				rotateLeft(root,grant_parent_stuff);
				swap(parent_stuff->color, grant_parent_stuff->color);
				stuff = parent_stuff;
			}
		}
	}
	root->color = black;
}




template <typename T>
void rotateRight(Node<T>*& root, Node<T>*& stuff) {
	Node<T>* parent_left = stuff->left;

	stuff->left = parent_left->right;

	if (stuff->left != nullptr)
		stuff->left->parent = stuff;
	parent_left->parent = stuff->parent;

	if (stuff->parent == nullptr)
		root = parent_left;

	else if (stuff == stuff->parent->left)
		stuff->parent->left = parent_left;

	else
		stuff->parent->right = parent_left;
	parent_left->right = stuff;
	stuff->parent = parent_left;
}

template <typename T>
void rotateLeft(Node<T>*& root, Node<T>*& stuff) {
	Node<T>* parent_right = stuff->right;
	stuff->right = parent_right->left;

	if (stuff->right != nullptr)
		stuff->right->parent = stuff;

	parent_right->parent = stuff->parent;
	if (stuff->parent == nullptr)
		root = parent_right;

	else if (stuff == stuff->parent->left)
		stuff->parent->left = parent_right;

	else
		stuff->parent->right = parent_right;
	parent_right->left = stuff;
	stuff->parent = parent_right;
}


template <typename T>
void LookUp(Node<T>* root, T x) {
	if (root == nullptr) {
		return;
	}
	Node<T>* p = root;
	auto _x = x;
	bool found = false;
	while(p != nullptr && !found) {
		if(p->value == _x)
			found = true;
		if(!found) {
			if(p->value < _x)
				p = p->right;
			else
				p = p->left;
		}
	}
	if(!found)
		cout << "\nNode Not Found.";
	else {
		cout << "\nFound Node!" << "\ncolor: ";
		if(p->color == red)
			cout << "red";
		else
			cout << "black";
		cout << "\nvalue: " << p->value.data << endl;
	}
}

int Max(int x, int y) {
	if(x >= y)
		return x;
	else
		return y;
}

template <typename T>
int Height(const Node<T>* root) {
	if(root == nullptr)
		return 0;
	else
		return 1 + Max(Height(root->left), Height(root->right));
}