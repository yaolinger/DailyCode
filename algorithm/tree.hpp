#ifndef __ALGORITHM_TREE_HPP__
#define __ALGORITHM_TREE_HPP__

#include <iostream>

// 树节点
struct TreeNode {
	int mVal = 0;
	TreeNode* mRight = NULL;
	TreeNode* mLeft = NULL;
};

// 增加有序树节点
TreeNode* addSortNode(TreeNode* root, int val);

// 删除有序树节点
TreeNode* delSortNode(TreeNode* root, int val);

// 打印二叉树
void printTreeNode(TreeNode* root);

// 树测试
void testTree();

#endif
