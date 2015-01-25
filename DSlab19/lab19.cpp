#include <iostream>
using namespace std;

template <typename ItemType>
class BST {//unbalanced binary search tree, no duplicates allowed, templated
public:
	BST() { root = 0; }//empty tree

	bool empty() const { return (root == 0); } //return true iff no nodes

	bool insert(ItemType val) { //insert val into a correct spot, return false if duplicate or out of memory
		if (empty()) {
			root = new Node(val);
			return (root != 0); //return true if root is not NULL, NULL if no memory
		}
		return insert(val, root);
	}

	bool search(ItemType val) const{	//return true iff val found in tree
		return search(val, root);
	}

	ItemType total() const { return total(root); }  //obviously, this isn't right
	//implement total, hint: recursion is your friend
	//total uses + on every data item in the tree and returns a total
	//assume that ItemType supports + and 0

	int size() const { return size(root); }  //obviously, this isn't right.
	//implement size which is the number of nodes, hint: recursion is your friend

private:
	struct Node {//constructor provided for simplicity of insert
		Node(ItemType d) : data(d), lChild(0), rChild(0) {}
		ItemType data;
		Node *lChild, *rChild;
	};
	Node * root;

	ItemType total(Node * curr)const {
		if (!curr) return 0;
		return curr->data + total(curr->lChild) + total(curr->rChild);

	}

	
	int size(Node * curr) const{
		if (!curr) return 0;
		return 1 + size(curr->lChild) + size(curr->rChild);
	}

	//below are recursive helpers for public methods with the same name
	bool insert(ItemType val, Node *cur) {
		if (cur->data == val) return false;
		if (val < cur->data) {//go left
			if (cur->lChild)	  return insert(val, cur->lChild);//no left so insert here
			cur->lChild = new Node(val);
			return (cur->lChild != 0);
		}
		else {
			if (cur->rChild)	  return insert(val, cur->rChild);//no right so insert here
			cur->rChild = new Node(val);
			return (cur->rChild != 0);
		}
	}

	bool search(ItemType val, Node *cur) const {
		if (cur == 0)			  return false;
		if (cur->data == val) return true;
		if (val < cur->data)  return search(val, cur->lChild);//val smaller so we go left
		else				  return search(val, cur->rChild);
	}

};

void main() {
	BST<int> tree;//your additional test code would go here
	int vals[] = { 5, 10, 8, 6, 7, 9, 1, 3, 2, 4 };
	for (int i = 0; i<10; i++) tree.insert(vals[i]);
	cout << tree.size() << endl;
	cout << tree.total() << endl;
}