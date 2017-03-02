#include <iostream>
#include <stdio.h>
#include <math.h>
#include "test.h"
#include "test.cpp"
using namespace std;

template <class T>
void rbtree<T>::_display(_rbTreeNode<T> * x) {
	if (x->left != nil)
		_display(x->left);
	if (x != nil) {
		cout << x->key << ' ';
		if (x->color == true)
			cout << "RED ";
		else
			cout << "BLACK ";
		if (x->p != nil)
			cout << x->p->key << ' ';
		else
			cout << "NULL ";
		if (x->left != nil)
			cout << x->left->key << ' ';
		else
			cout << "NULL ";
		if (x->right != nil)
			cout << x->right->key << ' ';
		else
			cout << "NULL ";
	}
	cout << endl;
	if (x->right != nil)
		_display(x->right);
}

template <class T>
_rbTreeNode<T> * rbtree<T>::ssearch(T key) {
	_rbTreeNode<T> * x = root;
	while (x != nil && key != x->key) {
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	if (x != nil) {
		cout << x->key << ' ';
		if (x->color == true)
			cout << "RED ";
		else
			cout << "BLACK ";
		if (x->p != nil)
			cout << x->p->key << ' ';
		else
			cout << "NULL ";
		if (x->left != nil)
			cout << x->left->key << ' ';
		else
			cout << "NULL ";
		if (x->right != nil)
			cout << x->right->key << ' ';
		else
			cout << "NULL ";
	}


	return 0;

}

template <class T>
_rbTreeNode<T> * rbtree<T>::min(T key) {
	_rbTreeNode<T> * x = root;

	while (x->left != nil)
		x = x->left;

	if (x != nil) {
		cout << x->key << ' ';
		if (x->color == true)
			cout << "RED ";
		else
			cout << "BLACK ";
		if (x->p != nil)
			cout << x->p->key << ' ';
		else
			cout << "NULL ";
		if (x->left != nil)
			cout << x->left->key << ' ';
		else
			cout << "NULL ";
		if (x->right != nil)
			cout << x->right->key << ' ';
		else
			cout << "NULL ";
	}

	cout << endl;

	return 0;
}

template <class T>
_rbTreeNode<T> * rbtree<T>::max(T key) {
	_rbTreeNode<T> * x = root;

	while (x->right != nil)
		x = x->right;

	if (x != nil) {
		cout << x->key << ' ';
		if (x->color == true)
			cout << "RED ";
		else
			cout << "BLACK ";
		if (x->p != nil)
			cout << x->p->key << ' ';
		else
			cout << "NULL ";
		if (x->left != nil)
			cout << x->left->key << ' ';
		else
			cout << "NULL ";
		if (x->right != nil)
			cout << x->right->key << ' ';
		else
			cout << "NULL ";
	}

	cout << endl;

	return 0;
}

template <class T>
void rbtree<T>::minimum(T key) {
	_rbTreeNode<T> * x = search(key);
	x = x->left;
	if (x != nil)
	{
		cout << x->key << ' ';
		if (x->color == true)
			cout << "RED ";
		else
			cout << "BLACK ";
		if (x->p != nil)
			cout << x->p->key << ' ';
		else
			cout << "NULL ";
		if (x->left != nil)
			cout << x->left->key << ' ';
		else
			cout << "NULL ";
		if (x->right != nil)
			cout << x->right->key << ' ';
		else
			cout << "NULL ";
	}
	else { cout << "NULL"; }
	cout << endl;
}

template <class T>
void rbtree<T>::maximum(T key) {
	_rbTreeNode<T> * x = search(key);
	x = x->right;
	if (x != nil)
	{
		cout << x->key << ' ';
		if (x->color == true)
			cout << "RED ";
		else
			cout << "BLACK ";
		if (x->p != nil)
			cout << x->p->key << ' ';
		else
			cout << "NULL ";
		if (x->left != nil)
			cout << x->left->key << ' ';
		else
			cout << "NULL ";
		if (x->right != nil)
			cout << x->right->key << ' ';
		else
			cout << "NULL ";
	}
	else { cout << "NULL"; }
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int x, k;
	rbtree<int> test;

	while (true)
	{
		system("cls");

		if (test.display()==-7) cout << "Tree is empty! " << endl;
		else test._display(test.root);

		cout << endl;

		cout << "1. Вставка" << endl;
		cout << "2. Поиск" << endl;
		cout << "3. Удаление" << endl;
		cout << "4. Поиск минимума" << endl;
		cout << "5. Поиск максимума" << endl;
		cout << "6. Поиск ближайшего минимума" << endl;
		cout << "7. Поиск ближайшего максимума" << endl;
		cout << "8. Выход" << endl;


		cin >> k;
		switch (k)
		{
		case(1) :
			system("cls");
			cin >> x;
			test.insert(x);
			break;

		case(2) :
			system("cls");
			cin >> x;
			test.ssearch(x);
			cout << endl;
			system("pause");
			break;

		case(3) :
			system("cls");
			cin >> x;
			test.erase(x);
			break;

		case(4) :
			system("cls");
			test.min(x);
			system("pause");
			break;

		case(5) :
			system("cls");
			test.max(x);
			system("pause");
			break;

		case(6) :
			system("cls");
			cin >> x;
			test.minimum(x);
			system("pause");
			break;

		case(7) :
			system("cls");
			cin >> x;
			test.maximum(x);
			system("pause");
			break;

		}

		if (k == 8) break;

	}

	return 0;
}
//2,12 CC