#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "binary_search_tree.hpp"

namespace Nlib{

	template <class Type>
	class AVLTree: public BinarySearchTree<Type>{

	protected:
		TreeNode<Type>* leftRotate(TreeNode<Type>* pivot);

		TreeNode<Type>* rightRotate(TreeNode<Type>* pivot);

		int getBalanceFactor(TreeNode<Type>* node);

		// balance the tree; track to the root from the given node
		void balance(TreeNode<Type>* node);

		// Overriding
		void remove(TreeNode<Type>* node);

	public:
		// Overriding
		bool insert(Type data);

		// Overriding
		bool remove(Type data);

	};

}

#include "../src/AVL_tree.tpp"

#endif
