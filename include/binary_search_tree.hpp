#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "binary_tree.hpp"

namespace Nlib{

	template <class Type>
	class BinarySearchTree: public BinaryTree<Type>{
	
	protected:
		bool insert(TreeNode<Type>* node, TreeNode<Type>* new_node);

		TreeNode<Type>* getInorderSuccessor(TreeNode<Type>* node) const;

		virtual void remove(TreeNode<Type>* node);

	public:
		// Overriding 
		bool insert(Type data);

		TreeNode<Type>* search(Type data) const;

		bool exists(Type data) const;

		virtual bool remove(Type data);

	};

}

#include "../src/binary_search_tree.tpp"

#endif
