#include "list.hpp"

#include <array>
#include <map>
#include <sstream>
#include "utils/log.hpp"
#include "utils/log_helper.hpp"

void listPrint(Node* head) {
	std::ostringstream oss;
	Node* p = head;
	while(NULL != p) {
		if (p != head) {
		    oss << ",";
		}
		oss << std::to_string(p->value);
		p = p->next;
	}
	log_info("List[%s]", oss.str().c_str());
}

void listAddNode(Node* &head, int value) {
	Node* pNode = new Node;
	pNode->value = value;
	pNode->next = NULL;

	if (NULL == head) {
		head = pNode;
	} else {
		Node* p = head;
		while(NULL != p->next) {
			p = p->next;
		}
		p->next = pNode;	
	}
}

void listDelNode(Node* &head, int value) {
	if (NULL == head) {
		return;
	}
	// 删除头节点
//	if (head->value == value) {
//		Node* p = head;
//		head = head->next;
//		delete p;
//	} else {
//		Node* before = head;
//		Node* p = head->next;
//		while(NULL != p) {
//			if (p->value == value) {
//				before->next = p->next;
//				delete p;	
//				break;
//			}
//			before = p;
//			p = p->next;
//		}
//	}

        Node* pBefore = NULL;
        Node* pCur = head;
        do {
            if (pCur->value == value) {
                if (pBefore != NULL) {
                    pBefore->next = pCur->next;
                }
                if (pCur == head) {
                    head = pCur->next;
                }
                delete pCur;
                break;
            } else {
                pBefore = pCur;
                pCur = pCur->next;
            }
        } while(pCur != NULL);
}

void listReverse(Node* &head) {
	if (head == NULL || head->next == NULL) {
		return;
	}

	Node* pCur = head;
	Node* pNext = head->next;
	do {
		 if (head == pCur) {
		 	pCur->next = NULL;
		 }
		 Node* pNNext = pNext->next; 
		 pNext->next = pCur;
		 pCur = pNext;
		 pNext = pNNext;
	} while(pNext != NULL);
	
	head = pCur;
}

void listDelBehindN(Node* &head, int n) {
	if (n == 0) {
		return;
	}
	std::map<int, std::array<Node*, 3>> mapData;
	Node* pBefore = NULL;
	Node* pCur = head;
	int i = 0;
	while(pCur != NULL) {
		std::array<Node*, 3>& dataArray = mapData[i];
		dataArray[0] = pBefore;
		dataArray[1] = pCur;
		dataArray[2] = pCur->next;
		pBefore = pCur;
		pCur = pCur->next;
		i++;
	}
	if (n > (int)mapData.size()) {
		return;
	}
	int index = mapData.size() - n;
	std::array<Node*, 3>& dataArray = mapData[index];
	if (dataArray[0] != NULL) {
		dataArray[0]->next = dataArray[2];
	}
	delete dataArray[1];
	if (index == 0) {
		head = dataArray[2];
	}
}

Node* mergeTwoLists(Node* l1, Node* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

	// 遍历方案
//  Node p;
//	Node* cur = &p;
//  while(l1 != nullptr && l2 != nullptr) {
//      if (l1->value <= l2->value) {
//          cur->next = l1;
//          l1 = l1->next;
//      } else {
//          cur->next = l2;
//          l2 = l2->next;
//      }
//      cur = cur->next;
//  }
//	if (l1 == nullptr) {
//		cur->next = l2;
//	}
//	if (l2 == nullptr) {
//		cur->next = l1;
//	}
//    return p.next;

	// 递归方案
	if (l1->value < l2->value) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	} else  {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

void listTest() {
	FUNC_TRACE;

	Node* head = NULL;
	listAddNode(head, 1);
	listAddNode(head, 2);
	listAddNode(head, 3);
	listAddNode(head, 4);
	listAddNode(head, 5);
	listAddNode(head, 76);
	listAddNode(head, 17);
	listAddNode(head, 81);
	listAddNode(head, 36);
	listAddNode(head, 12);

	listPrint(head);

	listReverse(head);

	listPrint(head);
	
//	listDelNode(head, 3);

	listDelNode(head, 12);

	listPrint(head);

	listDelBehindN(head, 3);
	
	listPrint(head);
	
	listDelBehindN(head, 7);
	
	listPrint(head);

	listReverse(head);
	
	listPrint(head);
	
	Node* head2 = NULL;
	listAddNode(head2, 3);
	listAddNode(head2, 6);
	listAddNode(head2, 12);
	listAddNode(head2, 13);
	listPrint(head2);

	Node* head3 = mergeTwoLists(head, head2);
	listPrint(head3);
}

