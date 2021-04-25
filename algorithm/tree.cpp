#include "tree.hpp"

#include <functional>
#include <sstream>
#include "utils/log.hpp"
#include "utils/log_helper.hpp"

TreeNode* addSortNode(TreeNode* root, int val) {
	TreeNode* pNode = new TreeNode;
	pNode->mVal = val;
	if (root == NULL) {
		return pNode;
	} else {
		TreeNode* pCur = NULL;
		TreeNode* pHead = root;
		do {
			pCur = root;
			if (root->mVal < val) {
				root = root->mRight;
			} else {
				root = root->mLeft;
			}
		} while(root != NULL);
		if (pCur->mVal < val) {
			pCur->mRight = pNode;
		} else {
			pCur->mLeft = pNode;
		}
		return pHead;
	}
}

TreeNode* delSortNode(TreeNode* root, int val) {
	if (root == NULL) {
		return root;
	}
	// 查询节点
	if (root->mVal > val) {
		root->mLeft = delSortNode(root->mLeft, val);
	} else if (root->mVal < val) {
		root->mRight = delSortNode(root->mRight, val);
	} else {
		// root-mVal == val
		// 左节点为空 直接反回右节点
		if (root->mLeft == NULL) {
			return root->mRight;
		}
		// 右节点为空 直接返回左节点
		if (root->mRight == NULL) {
			return root->mLeft;
		}
		// 寻找右节点的最左节点, 链接原节点左分支
		TreeNode* pNode = root->mRight;
		while(pNode->mLeft != NULL) {
			pNode = pNode->mLeft;
		}
		pNode->mLeft = root->mLeft;
		TreeNode* pDelete = root;
		root = root->mRight;
		delete pDelete;
		pDelete = NULL;
	}
	return root;
}

void printTreeNode(TreeNode* root) {
	std::function<void(TreeNode* node)> func;
	{
		std::ostringstream oss;
		func = [&](TreeNode* node) {
			if (node == NULL) {
				return;
			}
			func(node->mLeft);
			oss << "|"<< node->mVal;
			func(node->mRight);
		};
		func(root);
		log_info("中序 Tree [%s]", oss.str().c_str());
	}
	{
		std::ostringstream oss;
		func = [&](TreeNode* node) {
			if (node == NULL) {
				return;
			}
			oss << "|"<< node->mVal;
			func(node->mLeft);
			func(node->mRight);
		};
		func(root);
		log_info("先序 Tree [%s]", oss.str().c_str());
	}
	{
		std::ostringstream oss;
		func = [&](TreeNode* node) {
			if (node == NULL) {
				return;
			}
			func(node->mLeft);
			func(node->mRight);
			oss << "|"<< node->mVal;
		};
		func(root);
		log_info("后序 Tree [%s]", oss.str().c_str());
	}
}

void testTree() {
	FUNC_TRACE;
	TreeNode* root = NULL;
	root = addSortNode(root, 55);
	root = addSortNode(root, 23);
	root = addSortNode(root, 33);
	root = addSortNode(root, 68);
	root = addSortNode(root, 72);
	root = addSortNode(root, 71);
	root = addSortNode(root, 15);
	root = addSortNode(root, 32);
	root = addSortNode(root, 76);
	
	printTreeNode(root);

	root = delSortNode(root, 55);
	printTreeNode(root);
}

