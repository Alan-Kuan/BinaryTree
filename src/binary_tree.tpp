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

template <class Type>
bool Nlib::TreeNode<Type>::hasChildren(void) const{

	return left != nullptr || right != nullptr;

}


//-------- BinaryTree --------//
template <class Type>
Nlib::BinaryTree<Type>::~BinaryTree(void){

	clear();

}

template <class Type>
Nlib::TreeNode<Type>* Nlib::BinaryTree<Type>::getRoot(void) const{

	return root;

}

template <class Type>
bool Nlib::BinaryTree<Type>::add(Type data){

	Nlib::TreeNode<Type>* new_node = new Nlib::TreeNode<Type>(data);

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	if(root == nullptr){

		root = new_node;

		return true;

	}

	// add a new node with BFS
	std::queue<Nlib::TreeNode<Type>*> Q;

	Q.push(root);

	while(!Q.empty()){

		Nlib::TreeNode<Type>* node = Q.front();

		Q.pop();

		if(node -> left == nullptr){

			node -> left = new_node;

			new_node -> parent = node;

			break;

		}else
			Q.push(node -> left);

		if(node -> right == nullptr){

			node -> right = new_node;

			new_node -> parent = node;

			break;

		}else
			Q.push(node -> right);

	}

	return true;

} 

template <class Type>
void Nlib::BinaryTree<Type>::removeRecusively(Nlib::TreeNode<Type>* node){

	if(node != nullptr){

		removeRecusively(node -> left);

		removeRecusively(node -> right);

		delete node;

	}

}

template <class Type>
void Nlib::BinaryTree<Type>::clear(void){
	
	removeRecusively(root);

	root = nullptr;

}

template <class Type>
void Nlib::BinaryTree<Type>::preorderPrint(Nlib::TreeNode<Type>* node, const std::string& prefix, bool isLeft) const{

	if(node == nullptr)
		return;

	std::cout << prefix;
   
	if(isLeft && node -> parent -> right != nullptr)
		std::cout << "├-";
	else
		std::cout << "└-";
	
	std::cout << node -> data;
   
	// If the node is a left child of its parent and its parent does not have a right child, then shows that it's left.
	// I did this for the reason that in most of the time, a node with the prefix '└-' is a right child of its parent.
	if(isLeft && node -> parent -> right == nullptr)
		std:: cout << " (left)";

	std::cout << std::endl;

	const std::string new_prefix = prefix + (isLeft ? "| " : "  ");

	preorderPrint(node -> left, new_prefix, true);

	preorderPrint(node -> right, new_prefix, false);

}

template <class Type>
void Nlib::BinaryTree<Type>::print(void){

	if(root == nullptr){

		std::cout << "(empty)" << std::endl;

		return;

	}

	preorderPrint(root, "", false);

}