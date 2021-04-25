#ifndef __ALGORITHM_LIST_HPP__
#define __ALGORITHM_LIST_HPP__

#include <iostream>

// 单一节点
struct Node {
	int value;
	Node* next;
};

// 打印链表
void listPrint(Node* head);

// 链表增加单一节点
void listAddNode(Node* &head, int value);

// 链表删除一节点
void listDelNode(Node* &head, int value);

// 删除链表反向第n个节点
void listDelBehindN(Node* &head, int n);

// 反转链表
void listReverse(Node* &head);

// 合并两个有序表
Node* mergeTwoLists(Node* l1, Node* l2);

// 基础链表测试
void listTest(); 

#endif
