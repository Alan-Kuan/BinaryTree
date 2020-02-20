#include "../include/AVL_tree.hpp"

namespace Nlib{

	/*
	 *        x                      y
	 *       / \                    / \
	 *      T1  y         ==>      x  T3
	 *         / \                / \
	 *        T2 T3              T1 T2
	 */
	template <class Type>
	TreeNode<Type>*  AVLTree<Type>::leftRotate(TreeNode<Type>* pivot){

		TreeNode<Type>* y = pivot -> right;
		TreeNode<Type>* T2 = y -> left;

		pivot -> right = T2;
		if(T2 != nullptr)
			T2 -> parent = pivot;

		y -> left = pivot;
		pivot -> parent = y;

		this -> updateCurrHeight(pivot);
		this -> updateCurrHeight(y);

		return y;

	}

	/*
	 *        x                   y
	 *       / \                 / \
	 *      y  T3       ==>     T1  x
	 *     / \                     / \
	 *    T1 T2                   T2 T3
	 */
	template <class Type>
	TreeNode<Type>* AVLTree<Type>::rightRotate(TreeNode<Type>* pivot){

		TreeNode<Type>* y = pivot -> left;
		TreeNode<Type>* T2 = y -> right;

		pivot -> left = T2;
		if(T2 != nullptr)
			T2 -> parent = pivot;

		y -> right = pivot;
		pivot -> parent = y;

		this -> updateCurrHeight(pivot);
		this -> updateCurrHeight(y);

		return y;

	}

	template <class Type>
	int AVLTree<Type>::getBalanceFactor(TreeNode<Type>* node){

		if(node -> left == nullptr && node -> right == nullptr)
			return 0;
		if(node -> left == nullptr)
			return -1 - node -> right -> height;
		if(node -> right == nullptr)
			return node -> left -> height + 1;

		return node -> left -> height - node -> right -> height;

	}

	template <class Type>
	void AVLTree<Type>::balance(TreeNode<Type>* node){

		TreeNode<Type>* curr = node;

		TreeNode<Type>* parent = nullptr;

		// balance the tree
		for(; curr != nullptr; curr = parent){

			parent = curr -> parent;

			// update the height whenever we meet an ancestor because we may just rotated its children
			this -> updateCurrHeight(curr);

			int factor = getBalanceFactor(curr);

			// left subtree of the current node is too tall; need right rotation
			if(factor > 1){

				// right subtree of the unbalanced (current) node's left child is taller; need left rotation first
				if(getBalanceFactor(curr -> left) < 0){
				
					TreeNode<Type>* balanced_left_child = leftRotate(curr -> left);

					curr -> left = balanced_left_child;
					balanced_left_child -> parent = curr;

				}

				TreeNode<Type>* balanced_node = rightRotate(curr);

				if(parent == nullptr){

					this -> root = balanced_node;

				}else{

					if(curr -> data < parent -> data)
						parent -> left = balanced_node;
					else
						parent -> right = balanced_node;

				}

				balanced_node -> parent = parent;

			// right subtree of the current is too tall; need left rotation
			}else if(factor < -1){

				// left subtree of the unbalanced (current) node's right child is taller; need right rotation first
				if(getBalanceFactor(curr -> right) > 0){

					TreeNode<Type>* balanced_right_child = rightRotate(curr -> right);

					curr -> right = balanced_right_child;
					balanced_right_child -> parent = curr;

				}

				TreeNode<Type>* balanced_node = leftRotate(curr);

				if(parent == nullptr){

					this -> root = balanced_node;

				}else{

					if(curr -> data < parent -> data)
						parent -> left = balanced_node;
					else
						parent -> right = balanced_node;

				}

				balanced_node -> parent = parent;

			}

		}

	}

	template <class Type>
	bool AVLTree<Type>::insert(Type data){

		TreeNode<Type>* new_node = new TreeNode<Type>(data);

		// memory allocation failed
		if(new_node == nullptr)
			return false;

		if(this -> root == nullptr){

			this -> root = new_node;

			return true;

		}

		if(BinarySearchTree<Type>::insert(this -> root, new_node)){

			balance(new_node -> parent);

			return true;

		}

		// duplicate data
		return false;

	}

	template <class Type>
	void AVLTree<Type>::remove(TreeNode<Type>* node){

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

			balance(node -> parent);

			delete node;

		// if the removed node has two children, replace its data with its inorder successor's
		// and remove its inorder successor
		}else if(node -> left != nullptr && node -> right != nullptr){

			// for a node with two children
			// its inorder successor must be a leaf node or a node with only one right child
			// because its inorder successor is the node with the smallest data in its right subtree
			TreeNode<Type>* successor = this -> getInorderSuccessor(node);

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

			balance(node -> parent);

			delete node;
		
		}

	}	

	template <class Type>
	bool AVLTree<Type>::remove(Type data){

		TreeNode<Type>* node = this -> search(data);

		// not found
		if(node == nullptr)
			return false;

		remove(node);

		return true;

	}

}
