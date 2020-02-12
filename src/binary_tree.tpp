#include "../include/binary_tree.hpp"

namespace Nlib{

	//-------- TreeNode --------//
	template <class Type>
	Type TreeNode<Type>::getData(void) const{

		return data;

	}

	template <class Type>
	void TreeNode<Type>::setData(Type data){

		this -> data = data;

	}

	template <class Type>
	TreeNode<Type>* TreeNode<Type>::getParent(void) const{

		return parent;

	}

	template <class Type>
	TreeNode<Type>* TreeNode<Type>::getLeftChild(void) const{

		return left;

	}

	template <class Type>
	TreeNode<Type>* TreeNode<Type>::getRightChild(void) const{

		return right;

	}

	template <class Type>
	bool TreeNode<Type>::hasChildren(void) const{

		return left != nullptr || right != nullptr;

	}


	//-------- BinaryTree --------//
	template <class Type>
	BinaryTree<Type>::~BinaryTree(void){

		clear();

	}

	template <class Type>
	TreeNode<Type>* BinaryTree<Type>::getRoot(void) const{

		return root;

	}

	template <class Type>
	bool BinaryTree<Type>::add(Type data){

		TreeNode<Type>* new_node = new TreeNode<Type>(data);

		// memory allocation failed
		if(new_node == nullptr)
			return false;

		if(root == nullptr){

			root = new_node;

			return true;

		}

		// add a new node with BFS
		std::queue<TreeNode<Type>*> Q;

		Q.push(root);

		while(!Q.empty()){

			TreeNode<Type>* node = Q.front();

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
	void BinaryTree<Type>::removeRecusively(TreeNode<Type>* node){

		if(node != nullptr){

			removeRecusively(node -> left);

			removeRecusively(node -> right);

			delete node;

		}

	}

	template <class Type>
	void BinaryTree<Type>::clear(void){
		
		removeRecusively(root);

		root = nullptr;

	}

	template <class Type>
	void BinaryTree<Type>::preorderPrint(TreeNode<Type>* node, const std::string& prefix, bool isLeft) const{

		if(node == nullptr)
			return;

		std::string new_prefix = prefix;

		std::cout << prefix;
	   
		if(isLeft && node -> parent -> right != nullptr){

			std::cout << "├-";

			new_prefix += "| ";

		}else{

			std::cout << "└-";

			new_prefix += "  ";

		}
		
		std::cout << node -> data;
	   
		// If the node is a left child of its parent and its parent does not have a right child, then shows that it's left.
		// I did this for the reason that in most of the time, a node with the prefix '└-' is a right child of its parent.
		if(isLeft && node -> parent -> right == nullptr)
			std:: cout << " (left)";

		std::cout << std::endl;

		preorderPrint(node -> left, new_prefix, true);

		preorderPrint(node -> right, new_prefix, false);

	}

	template <class Type>
	void BinaryTree<Type>::inorderPrint(TreeNode<Type>* node, const std::string& prefix, bool isLeft) const{

		if(node == nullptr)
			return;

		inorderPrint(node -> left, prefix + (isLeft ? "  " : "| "), true);

		std::cout << prefix << (isLeft ? "┌-" : "└-") << node -> data << std::endl;

		inorderPrint(node -> right, prefix + (isLeft ? "| " : "  "), false);

	}

	template <class Type>
	void BinaryTree<Type>::print(PrintStyle style){

		if(root == nullptr)
			std::cout << "(empty)" << std::endl;
		else if(style == PrintStyle::suspend)
			preorderPrint(root, "", false);
		else if(style == PrintStyle::stretch)
			inorderPrint(root, "", false);

	}

}
