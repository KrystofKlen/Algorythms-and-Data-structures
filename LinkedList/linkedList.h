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