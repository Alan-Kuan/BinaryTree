#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "binary_tree.hpp"

namespace Nlib{

	template <class Type>
	class BinarySearchTree: public BinaryTree<Type>{
	
	protected:
		bool add(TreeNode<Type>* node, TreeNode<Type>* new_node);

		TreeNode<Type>* getInorderSuccessor(TreeNode<Type>* node) const;

		void remove(TreeNode<Type>* node);

	public:
		// this is different from the add method in BinaryTree class
		bool add(Type data);

		TreeNode<Type>* search(Type data) const;

		bool exists(Type data) const;

		bool remove(Type data);

	};

}

#include "../src/binary_search_tree.tpp"

#endif
