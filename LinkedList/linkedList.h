#include "node.h"

/**
 * sets head and tail to NULL
 */
void listInit(LinkedList** pLinkedList);

/**
 * returns 1 if pLinkedList is empty ( if(pLinkedList -> mHead == NULL) )
 * otherwise returns 0;
 */
int listIsEmpty(LinkedList* pLinkedList);

/**
 * Adds a new Node to the front (head) of the linked list.
 * If parameter == NULL the function returns 1 (is empty)
 */
void listPushFront(LinkedList** pLinkedList, Node* pNewNode);

/**
 * pops the first Node (head) of the linked list
 */
void listPopFront(LinkedList** pLinkedList);

/**
 * Adds a new Node to the back (tail) of the linked list.
 */
void listPushBack(LinkedList** pLinkedList, Node* pNewNode);

/**
 * Deletes the last node (tail) of the linked list.
 */
void listPopBack(LinkedList** pLinkedList);

/**
 * returns 1 if pNode is in Linked List, 0 if there is not or when pNode is NULL.
 */
int containsInList(LinkedList* pLinkedList, Node* pNode);

/**
 * reverses the original Linked List using recursion
 */
void listReverseRecursively(LinkedList** pLinkedList);

/**
 * reverses the original Linked List using iterative approach
 */
void listReverseIterativerly(LinkedList** pLinkedList);

/**
 * Makes a copy of given Linked List.
 * 
 * Parameters:
 * pOriginalLinkedList = pointer to an existing and initialized Linked List.
 * pCopyLinkedList = pointer to a Linked List ( where HEAD == TAIL == NULL ), to which the pOriginalLinkedList should be copied.
 * copyNode = pointer to a function, which creates a copy of a Node from the original Linked List and returns a pointer to the copied Node.
 * 
 * Important: If pCopyLinkedList is not empty ( when the function listIsEmpty returns 0), then pCopyLinkedList is
 * deleted using listDelete function. After that, the copy is made.
 */ 
void listCopy(LinkedList** pOriginalLinkedList, LinkedList** pCopyLinkedList, Node* (*copyNode) (Node*) );

/**
 * Splits Linked List into 2 parts.
 * The first part is pointed by pOriginalLinkedList. The Tail the previous Node of pNewHeadNode
 * The first part is pointed by pNewLinkedList. The Head is pNewHeadNode.
 * Important: 
 * 1) If pOriginalLinkedList is empty (when the function listIsEmpty returns 1), then Head and Tail of pNewLinkedList is initialized to NULL.
 * 2) If pNewHeadNode is not contained in the pOriginalLinkedList, then the function does nothing.
 * 3) If there is only 1 element in pOriginalLinkedList, then pNewLinkedList Head and Tail are set to this 1 element and
 *  pOriginalLinkedList Head and Tail are set to NULL.
 * 4) If pNewLinkedList is as a parameter not empty (function listIsEmpty returns 0), then the content of pNewLinkedList is deleted.
 * -------------------------------------------------------------------------------------
 * Example:
 * 
 * Before:
 * pOriginalLinkedList:  1(Head) -> 2 -> 3 -> 4(pNewHeadNode) -> 5 -> 6(Tail) -> NULL
 * 
 * After:
 * pOriginalLinkedList:  1(Head) -> 2 -> 3(Tail)
 * pNewLinkedList 4(Head, pNewHeadNode) -> 5 -> 6(Tail) -> NULL
 * -------------------------------------------------------------------------------------
 */ 
void listSplit(LinkedList** pOriginalLinkedList, LinkedList** pNewLinkedList, Node* pNewHeadNode);

/**
 * Deletes a Linked List and sets Head = NULL and Tail = NULL
 */
void listDelete(LinkedList** pLinkedList);

/**
 * Deletes pNodeToDelete from pLinkedList.
 * pLinkedList remains unchanged if pNodeToDe == NULL or pNodeTodelete is not in pLinkedList
 */
void nodeDelete(LinkedList** pLinkedList, Node* pNodeToDelete);

/**
 * Swaps 2 elements in the Linked List without creating new Nodes.
 */
void listSwap(LinkedList** pLinkedList, Node* pNode1, Node* pNode2);

/**
 * Merges 2 sorted linked lists into a single sorted linked list.
 * 
 * Parameters: 
 * pLinkedList1, pLinkedList2 = double pointers to two sorted linked lists
 * pMergedLinkedList = double pointer to linked list
 * int (nodeCompare) (Node* pNode1, Node* pNode2) = pointer to a function returning a number higher than 0 if pNode1 is greater than pNode2,
 *  smaller than 0 if pNode2 higher than pNode1, 0 if they are the same.
 * 
 * Important:
 * 1) If both pLinkedList1 and pLinkedList2 are empty (function listIsEmpty returns 1), then Head and Tail of pMergedLinkedList are set to NULL.
 * 2) If only pLinkedList1 (function listIsEmpty returns 1), then then Head and Tail of pMergedLinkedList are set Head and Tail of pLinkedList2.
 * 3) If only pLinkedList2 (function listIsEmpty returns 1), then then Head and Tail of pMergedLinkedList are set Head and Tail of pLinkedList1.
 * 4) Head and Tail of pLinkedList1 and pLinkedList2 will remain unchanged.
 * 5) If pMergedLinkedList is not empty (function listIsEmpty returns 1), then the previous content of pMergedLinkedList is deleted.
 * 6) NO COPY IS CREATED!
 * ----------------------------------------------------------
 * Example:
 * Before:
 * pLinkedList1: 1 (Head) -> 5 -> 6 -> 7 -> 20 -> 21 (Tail)
 * pLinkedList2: 3 (Head) -> 4 -> 7 -> 27(Tail);
 * pMergedLinkedList Head == Tail == NULL
 * ----------------------------------------------------------
 * After:
 * pLinkedList1: 1 (Head) -> 5 -> 6 -> 7 -> 20 -> 21 (Tail)
 * pLinkedList2: 3 (Head) -> 4 -> 7 -> 27(Tail);
 * pMergedLinkedList 1(Head of pMergedLinkedList, Head of pLinkedList1) -> 3 -> 4 (Head of pLinkedList2) -> 5 -> 6 -> 7 -> 7 -> 20 -> 21 (Tail of pLinkedList1) -> 27(Tail of pMergedLinkedList, Tail of pLinkedList2)
 */
void merge2SortedLinkedLists(LinkedList** pLinkedList1, LinkedList** pLinkedList2, LinkedList** pMergedLinkedList, int (nodeCompare) (Node*, Node*) );

/**
 * Returns the Length index of the given Linked list. 
 * Example:
 * 1 (Head) -> 2 -> 3 -> 4(Tail) .... length = 4;
 */
int getListLength(LinkedList* pLinkedList);

/**
 * Returns a pointer to the Node which is at Nth index at the given Linked list. NULL if n > max index of the Linked list.
 * -----------------------------------------------------------------
 * Example:
 * 1(Head) -> 2 -> 3 -> 4(Tail)
 * 2 == getListNodeAtNthIndex(LinkedList* pLinkedList, 1);
 * 1(Head) == getListNodeAtNthIndex(LinkedList* pLinkedList, 0);
 * NULL == getListNodeAtNthIndex(LinkedList* pLinkedList, 300);
 * -----------------------------------------------------------------
 */
Node* getListNodeAtNthIndex(LinkedList* pLinkedList, int n);

/**
 * Sorts given Linked List using merge sort algorithm.
 * Parameters:
 * pLinkedList = Linked List to sort
 * int (nodeCompare) (Node* pNode1, Node* pNode2) = pointer to a function returning a number higher than 0 if pNode1 is greater than pNode2,
 *  smaller than 0 if pNode2 higher than pNode1, 0 if they are the same.
 */
void listMergeSort(LinkedList** pLinkedList, int (nodeCompare) (Node*, Node*));