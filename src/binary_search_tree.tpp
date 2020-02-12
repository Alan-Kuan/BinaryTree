#include "../include/binary_search_tree.hpp"

namespace Nlib{

	template <class Type>
	bool BinarySearchTree<Type>::add(TreeNode<Type>* node, TreeNode<Type>* new_node){

		if(new_node -> data < node -> data){

			if(node -> left == nullptr){

				node -> left = new_node;

				new_node -> parent = node;

				this -> updateHeight(node);

				return true;

			}else
				return add(node -> left, new_node);

		}else if(new_node -> data > node -> data){

			if(node -> right == nullptr){

				node -> right = new_node;

				new_node -> parent = node;

				this -> updateHeight(node);

				return true;

			}else
				return add(node -> right, new_node);

		}

		// duplicate data are not allowed
		return false;

	}

	template <class Type>
	bool BinarySearchTree<Type>::add(Type data){

		TreeNode<Type>* new_node = new TreeNode<Type>(data);

		// memory allocation failed
		if(new_node == nullptr)
			return false;

		if(this -> root == nullptr){

			this -> root = new_node;

			return true;

		}

		return add(this -> root, new_node);

	}

	template <class Type>
	TreeNode<Type>* BinarySearchTree<Type>::search(Type data) const{

		TreeNode<Type>* curr = this -> root;

		while(curr != nullptr){

			if(data < curr -> data)
				curr = curr -> left;
			else if(data > curr -> data)
				curr = curr -> right;
			else
				break;

		}

		// returns nullptr if not found
		return curr;

	}

	template <class Type>
	bool BinarySearchTree<Type>::exists(Type data) const{

		return search(data) != nullptr;

	}

	template <class Type>
	TreeNode<Type>* BinarySearchTree<Type>::getInorderSuccessor(TreeNode<Type>* node) const{

		TreeNode<Type>* curr = node -> right;

		// if the node does not have a right child, then find the first ancestor whose data is bigger than its
		if(curr == nullptr){

			curr = node -> parent;

			for(; curr != nullptr && node -> data > curr -> data; curr = curr -> parent);

			// if the node does not have a inorder successor, it returns nullptr
			return curr;

		}

		// if the node has a right child, then find the node with the smallest data in the right subtree
		for(; curr -> left != nullptr; curr = curr -> left);

		return curr;

	}

	template <class Type>
	void BinarySearchTree<Type>::remove(TreeNode<Type>* node){

		if(node == nullptr)
			return;

		TreeNode<Type>** indirect = &(this -> root);

		while(*indirect != nullptr){

			if(node -> data < (*indirect) -> data)
				indirect = &((*indirect) -> left);
			else if(node -> data > (*indirect) -> data)
				indirect = &((*indirect) -> right);
			else
				break;

		}

		// if the removed node is a leaf node, just remove it
		if(!node -> hasChildren()){

			*indirect = nullptr;

			this -> updateHeight(node -> parent);

			delete node;

		// if the removed node has two children, replace its data with its inorder successor's
		// and remove its inorder successor
		}else if(node -> left != nullptr && node -> right != nullptr){

			// for a node with two children
			// its inorder successor must be a leaf node or a node with only one right child
			// because its inorder successor is the node with the smallest data in its right subtree
			TreeNode<Type>* successor = getInorderSuccessor(node);

			Type tmp_data = successor -> data;

			// because it's either a leaf node or a node with only one child
			// its removal will be easy
			remove(successor);

			node -> data = tmp_data;

		// if the removed node has one child, bypass it
		}else{
			
			if(node -> left != nullptr){

				*indirect = node -> left;

				node -> left -> parent = node -> parent;

			}else{

				*indirect = node -> right;

				node -> right -> parent = node -> parent;

			}

			this -> updateHeight(node -> parent);

			delete node;
		
		}

	}

	template <class Type>
	bool BinarySearchTree<Type>::remove(Type data){

		TreeNode<Type>* node = search(data);

		// not found
		if(node == nullptr)
			return false;

		remove(node);

		return true;

	}

}
