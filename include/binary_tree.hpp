#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

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

	};

	template <class Type>
	class BinaryTree{

	protected:
		TreeNode<Type>* root;

	public:
		BinaryTree(void): root(nullptr){}

		BinaryTree(TreeNode<Type>* root): root(root){}

		~BinaryTree(void);

		void clear(void);

	};

}

#endif
