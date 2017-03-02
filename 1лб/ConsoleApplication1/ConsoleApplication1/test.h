#ifndef __TEST__
#define __TEST__

template <class T>
class rbtree;

template <class T>
struct _rbTreeNode {
	friend class rbtree<T>;
	T getkey() {
		return key;
	}
private:
	T key;
	_rbTreeNode<T> *left;
	_rbTreeNode<T> *right;
	_rbTreeNode<T> *p;
	bool color;
};

template <class T>
class rbtree {

public:
	rbtree()
		:nil(new _rbTreeNode<T>), root(nil) {
		nil->left = 0; nil->p = 0; nil->right = 0; nil->color = false;
	}

	void insert(T key);
	_rbTreeNode<T> * search(T key);
	_rbTreeNode<T> * ssearch(T key);
	_rbTreeNode<T> * min(T key);
	void minimum(T key);
	void maximum(T key);
	_rbTreeNode<T> * max(T key);
	void erase(T key);


	int display();
	void _display(_rbTreeNode<T> * );


	void leftRotate(_rbTreeNode<T> *);
	void rightRotate(_rbTreeNode<T> *);

	void rbDelete(_rbTreeNode<T> *);
	void rbDeleteFixup(_rbTreeNode<T> *);

	void rbInsertFixup(_rbTreeNode<T> *);

	_rbTreeNode<T>* treeSuccessor(_rbTreeNode<T> *);


	_rbTreeNode<T> *nil;
	_rbTreeNode<T> *root;

};

#endif