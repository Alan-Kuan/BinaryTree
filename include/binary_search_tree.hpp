#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "binary_tree.hpp"

namespace Nlib{

	template <class Type>
	class BinarySearchTree: public BinaryTree<Type>{
	
	protected:
		TreeNode<Type>* getInorderSuccessor(TreeNode<Type>* node) const;

	public:
		// this is different from the add method in BinaryTree class
		bool add(Type data);

		TreeNode<Type>* search(Type data) const;

		bool exists(Type data) const;

		void remove(Type data);

		void remove(TreeNode<Type>* node);

	};

}

#include "../src/binary_search_tree.tpp"

#endif
