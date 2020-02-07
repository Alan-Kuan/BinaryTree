#include "../include/binary_tree.hpp"

//-------- TreeNode --------//
template <class Type>
Type Nlib::TreeNode<Type>::getData(void) const{

	return data;

}

template <class Type>
void Nlib::TreeNode<Type>::setData(Type data){

	this -> data = data;

}

template <class Type>
Nlib::TreeNode<Type>* Nlib::TreeNode<Type>::getParent(void) const{

	return parent;

}

template <class Type>
Nlib::TreeNode<Type>* Nlib::TreeNode<Type>::getLeftChild(void) const{

	return left;

}

template <class Type>
Nlib::TreeNode<Type>* Nlib::TreeNode<Type>::getRightChild(void) const{

	return right;

}


//-------- BinaryTree --------//
template <class Type>
Nlib::BinaryTree<Type>::~BinaryTree(void){

	clear();

}
