#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

namespace Nlib{

	template <class Type>
	class TreeNode{

		template <class> friend class BinaryTree;

	protected:
		Type data;

		TreeNode* left;

		TreeNode* right;

	public:
		TreeNode(void): left(nullptr), right(nullptr){}

		TreeNode(Type data): data(data), left(nullptr), right(nullptr){}

		TreeNode(Type data, TreeNode* left, TreeNode* right): data(data), left(left), right(right){}

		Type getData(void) const;

		void setData(Type data);

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
