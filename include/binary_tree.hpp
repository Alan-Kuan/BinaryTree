#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <queue>
#include <cstring>

namespace Nlib{

	template <class Type>
	class TreeNode{

		template <class> friend class BinaryTree;

	protected:
		Type data;

		TreeNode<Type>* parent;

		TreeNode<Type>* left;

		TreeNode<Type>* right;

	public:
		TreeNode(void): parent(nullptr), left(nullptr), right(nullptr){}

		TreeNode(Type data): data(data), parent(nullptr), left(nullptr), right(nullptr){}

		TreeNode(Type data, TreeNode<Type>* parent): data(data), parent(parent), left(nullptr), right(nullptr){}

		TreeNode(Type data, TreeNode<Type>* parent, TreeNode<Type>* left, TreeNode<Type>* right): data(data), parent(parent), left(left), right(right){}

		Type getData(void) const;

		void setData(Type data);

		TreeNode<Type>* getParent(void) const;

		TreeNode<Type>* getLeftChild(void) const;

		TreeNode<Type>* getRightChild(void) const;
		
		bool hasChildren(void) const;

	};

	template <class Type>
	class BinaryTree{

	protected:
		TreeNode<Type>* root;

		void preorderPrint(TreeNode<Type>* node, const std::string& prefix, bool isLeft, bool parentHasRightChild) const;

	public:
		BinaryTree(void): root(nullptr){}

		~BinaryTree(void);

		TreeNode<Type>* getRoot(void) const;

		// add a new node with BFS
		bool add(Type data);

		void removeRecusively(TreeNode<Type>* node);

		void clear(void);

		// print the tree with preorder visit
		void print(void);

	};

}

#include "../src/binary_tree.tpp"

#endif
