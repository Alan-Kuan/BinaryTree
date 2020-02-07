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


//-------- BinaryTree --------//
template <class Type>
Nlib::BinaryTree<Type>::~BinaryTree(void){

	clear();

}
