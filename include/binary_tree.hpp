#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <queue>
#include <cstring>

inline unsigned int max(unsigned int a, unsigned int b){

	return a > b ? a : b;

}

namespace Nlib{

	enum class PrintStyle{
		suspend,
		stretch
	};

	template <class Type>
	class TreeNode{

		template <class> friend class BinaryTree;

		template <class> friend class BinarySearchTree;

		template <class> friend class AVLTree;

	protected:
		Type data;

		TreeNode<Type>* parent;

		TreeNode<Type>* left;

		TreeNode<Type>* right;

		unsigned int height;

	public:
		TreeNode(void): parent(nullptr), left(nullptr), right(nullptr), height(0){}

		TreeNode(Type data): data(data), parent(nullptr), left(nullptr), right(nullptr), height(0){}

		Type getData(void) const;

		TreeNode<Type>* getParent(void) const;

		TreeNode<Type>* getLeftChild(void) const;

		TreeNode<Type>* getRightChild(void) const;
		
		bool hasChildren(void) const;

		unsigned int getHeight(void) const;

	};

	template <class Type>
	class BinaryTree{

	protected:
		TreeNode<Type>* root;

		void updateHeight(TreeNode<Type>* node);

		void preorderPrint(TreeNode<Type>* node, const std::string& prefix, bool isLeft) const;

		void inorderPrint(TreeNode<Type>* node, const std::string& prefix, bool isLeft) const;

	public:
		BinaryTree(void): root(nullptr){}

		~BinaryTree(void);

		TreeNode<Type>* getRoot(void) const;

		// add a new node with BFS
		bool add(Type data);

		void removeRecusively(TreeNode<Type>* node);

		void clear(void);

		// print the tree with preorder visit
		void print(PrintStyle style);

	};

}

#include "../src/binary_tree.tpp"

#endif
