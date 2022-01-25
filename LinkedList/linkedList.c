#include "node.h"
#include <stdlib.h>

void listInit(LinkedList** pLinkedList){
    (*pLinkedList) -> mHead = NULL;
    (*pLinkedList) -> mHead = NULL;
}

int listIsEmpty(LinkedList* pLinkedList){
    if(!pLinkedList) return 1;
    if(pLinkedList -> mHead == NULL) return 1;
    else return 0;
}

void listPushFront(LinkedList** pLinkedList, Node* pNewNode){

    if(listIsEmpty(*pLinkedList)){
        (*pLinkedList) -> mHead = pNewNode;
        (*pLinkedList) -> mTail = pNewNode;
        return;
    }
    if((*pLinkedList) -> mHead == (*pLinkedList) -> mTail){
        (*pLinkedList) -> mHead = pNewNode;
        (*pLinkedList) -> mHead -> mNext = (*pLinkedList) -> mTail;
        return;
    }

    Node* pOldHead = (*pLinkedList) -> mHead;
    (*pLinkedList) -> mHead = pNewNode;
    (*pLinkedList) -> mHead -> mNext = pOldHead;
}

void listPopFront(LinkedList** pLinkedList){

    if(listIsEmpty(*pLinkedList)) return;
    if((*pLinkedList) -> mHead == (*pLinkedList) -> mTail){
        free((*pLinkedList) -> mHead);
        listInit(pLinkedList);
        return;
    }
    Node* pOldHead = (*pLinkedList) -> mHead;
    (*pLinkedList) -> mHead = (*pLinkedList) -> mHead -> mNext;
    free(pOldHead);
}

Node* getPreviousNode(LinkedList** pLinkedList, Node* pNode){
    if(listIsEmpty(*pLinkedList)) return NULL;
    if((*pLinkedList) -> mHead == (*pLinkedList) -> mTail) return NULL;
    
    Node* previousNode = (*pLinkedList) -> mHead;
    while(previousNode -> mNext != pNode){
        if(previousNode -> mNext == NULL) return NULL;
        previousNode = previousNode -> mNext;
    }
    return previousNode;
}

void listPushBack(LinkedList** pLinkedList, Node* pNewNode){
    if(listIsEmpty(*pLinkedList)){
        (*pLinkedList) -> mHead = pNewNode;
        (*pLinkedList) -> mTail = pNewNode;
        return;
    }
    if((*pLinkedList) -> mHead == (*pLinkedList) -> mTail){
        (*pLinkedList) -> mTail = pNewNode;
        (*pLinkedList) -> mHead -> mNext = (*pLinkedList) -> mTail;
    }
    (*pLinkedList) -> mTail -> mNext = pNewNode;
    (*pLinkedList) -> mTail = (*pLinkedList) -> mTail -> mNext;
}

void listPopBack(LinkedList** pLinkedList){
    if(listIsEmpty(*pLinkedList)) return;
    if((*pLinkedList) -> mHead == (*pLinkedList) -> mTail){
        free((*pLinkedList) -> mHead);
        listInit(pLinkedList);
        return;
    }
    Node* previousNode = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
    free((*pLinkedList) -> mTail);
    (*pLinkedList) -> mTail = previousNode; 
    (*pLinkedList) -> mTail -> mNext = NULL;
}

int containsInList(LinkedList* pLinkedList, Node* pNode){
    if(!pNode) return 0;
    Node* currentNode = pLinkedList -> mHead;
    while(currentNode){
        if(currentNode == pNode) return 1;
        currentNode = currentNode -> mNext;
    }
    return 0;
}

void recursiveReverse(Node* pPreviousNode, Node* pCurrentNode){
    if(pCurrentNode -> mNext == NULL){
        pCurrentNode -> mNext = pPreviousNode;
        pPreviousNode -> mNext = NULL;
        return;
    }else{
        recursiveReverse(pCurrentNode, pCurrentNode -> mNext);
    }
    pCurrentNode -> mNext = pPreviousNode;
    pPreviousNode -> mNext = NULL;

}

void listReverseRecursively(LinkedList** pLinkedList){
    if(listIsEmpty(*pLinkedList)) return;
    if((*pLinkedList)->mHead == (*pLinkedList)->mTail) return;
    recursiveReverse((*pLinkedList)->mHead, (*pLinkedList)->mHead -> mNext);
    Node* pOldHead = (*pLinkedList)->mHead;
    (*pLinkedList)->mHead = (*pLinkedList)-> mTail;
    (*pLinkedList)->mTail = pOldHead;
}

void listReverseIterativerly(LinkedList** pLinkedList){
    if(listIsEmpty(*pLinkedList)) return;
    if((*pLinkedList)->mHead == (*pLinkedList)->mTail) return;

    Node* pCurrentNode = (*pLinkedList) -> mHead;
    Node* pPreviousNode = NULL;
    Node* pTmpNode;
    while(pCurrentNode){
        pTmpNode = pCurrentNode -> mNext;
        pCurrentNode -> mNext = pPreviousNode;
        pPreviousNode = pCurrentNode;
        pCurrentNode = pTmpNode;
    }
    Node* pOldHead = (*pLinkedList)->mHead;
    (*pLinkedList)->mHead = (*pLinkedList)-> mTail;
    (*pLinkedList)->mTail = pOldHead;
}

void listDelete(LinkedList** pLinkedList){
    Node* pTmpNode = (*pLinkedList) -> mHead;
    while(pTmpNode){
        pTmpNode = (*pLinkedList) -> mHead -> mNext;
        free((*pLinkedList) -> mHead);
        (*pLinkedList) -> mHead = pTmpNode;
    }
    (*pLinkedList) -> mHead =  NULL;
    (*pLinkedList) -> mTail = NULL;
}

void nodeDelete(LinkedList** pLinkedList, Node* pNodeToDelete){
    if(!pNodeToDelete || listIsEmpty(*pLinkedList)) return;
    if( (*pLinkedList)->mHead == pNodeToDelete ){
        listPopFront(pLinkedList);
        return;
    }
    if( (*pLinkedList)->mTail == pNodeToDelete ){
        listPopBack(pLinkedList);
        return;
    }
    Node* pPreviousNode = getPreviousNode(pLinkedList, pNodeToDelete);
    if(!pPreviousNode) return; // happens when pNodeToDelete is not in pLinkedList
    pPreviousNode -> mNext = pNodeToDelete -> mNext;
    free(pNodeToDelete);
}

void listSplit(LinkedList** pOriginalLinkedList, LinkedList** pNewLinkedList, Node* pNewHeadNode){
    if(listIsEmpty(*pOriginalLinkedList)){
        listInit(pNewLinkedList);
        return;
    }
    if(!containsInList(*pOriginalLinkedList, pNewHeadNode)){
        return;
    }
    if(!listIsEmpty(*pNewLinkedList)){
        listDelete(pNewLinkedList);
    }
    if((*pOriginalLinkedList) -> mHead == (*pOriginalLinkedList) -> mTail
    || (*pOriginalLinkedList) -> mHead == pNewHeadNode ){
        (*pNewLinkedList) -> mHead = (*pOriginalLinkedList) -> mHead;
        (*pNewLinkedList) -> mTail = (*pOriginalLinkedList) -> mTail;
        listInit(pOriginalLinkedList);
        return;
    }
    (*pNewLinkedList) -> mHead = (*pOriginalLinkedList) -> mHead;
    Node* pPreviousNode = NULL;
    while((*pNewLinkedList) -> mHead != pNewHeadNode){
        pPreviousNode = (*pNewLinkedList) -> mHead;
        (*pNewLinkedList) -> mHead = (*pNewLinkedList) -> mHead -> mNext;
    }
    pPreviousNode -> mNext = NULL;
    (*pOriginalLinkedList) -> mTail = pPreviousNode;
    
    Node* pNewTail = (*pNewLinkedList) -> mHead;
    while(pNewTail -> mNext){
        pNewTail = pNewTail -> mNext;
    }
    (*pNewLinkedList) -> mTail = pNewTail;
}

void listCopy(LinkedList** pOriginalLinkedList, LinkedList** pCopyLinkedList, Node* (*copyNode) (Node*) ){

    if(listIsEmpty(*pOriginalLinkedList)){
        listInit(pCopyLinkedList);
        return;
    }
    if(!listIsEmpty(*pCopyLinkedList)){
        listDelete(pCopyLinkedList);
    }
    Node* currentNodeOriginal = (*pOriginalLinkedList) -> mHead;
    (*pCopyLinkedList) -> mHead = copyNode(currentNodeOriginal);

    Node* currentNodeCopy = (*pCopyLinkedList) -> mHead;
    currentNodeOriginal = currentNodeOriginal -> mNext;
    Node* previousNodeCopy =  currentNodeCopy;

    while(currentNodeOriginal){
        currentNodeCopy -> mNext = copyNode(currentNodeOriginal);
        currentNodeCopy = currentNodeCopy -> mNext;
        currentNodeOriginal = currentNodeOriginal -> mNext;
        if(!currentNodeOriginal){
            (*pCopyLinkedList) -> mTail = currentNodeCopy;
            (*pCopyLinkedList) -> mTail = NULL;
            return;
        }
    }
}

void listSwap(LinkedList** pLinkedList, Node* pNode1, Node* pNode2){
    if(listIsEmpty(*pLinkedList)) return;
    if(pNode1 == pNode2) return;
    if((*pLinkedList) -> mHead == (*pLinkedList) -> mTail) return;

    if((*pLinkedList) -> mHead -> mNext == (*pLinkedList) -> mTail){
        (*pLinkedList) -> mTail -> mNext = (*pLinkedList) -> mHead;
        (*pLinkedList) -> mHead -> mNext = NULL;
        (*pLinkedList) -> mHead = (*pLinkedList) -> mTail;
        (*pLinkedList) -> mTail = (*pLinkedList) -> mHead;
        return;
    }
    if( (*pLinkedList) -> mHead == pNode1 && (*pLinkedList) -> mTail == pNode2 ){
        Node* pPreviousTail = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
        pNode2 -> mNext = pNode1 -> mNext;
        pPreviousTail -> mNext = pNode1;
        pNode1 -> mNext = NULL;
        (*pLinkedList) -> mHead = pNode2;
        (*pLinkedList) -> mTail = pNode1;
        return;
    }
    if( (*pLinkedList) -> mHead == pNode2 && (*pLinkedList) -> mTail == pNode1 ){
        Node* pPreviousTail = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
        pNode1 -> mNext = pNode2 -> mNext;
        pPreviousTail -> mNext = pNode2;
        pNode2 -> mNext = NULL;
        (*pLinkedList) -> mHead = pNode1;
        (*pLinkedList) -> mTail = pNode2;
        return;
    }
    if((*pLinkedList) -> mHead == pNode1 && (*pLinkedList) -> mHead -> mNext == pNode2){
        pNode1 -> mNext = pNode2 -> mNext;
        pNode2 -> mNext = pNode1;
        (*pLinkedList) -> mHead = pNode2;
        return;
    }
    if((*pLinkedList) -> mHead == pNode2 && (*pLinkedList) -> mHead -> mNext == pNode1){
        pNode2 -> mNext = pNode1 -> mNext;
        pNode1 -> mNext = pNode2;
        (*pLinkedList) -> mHead = pNode1;
        return;
    }
    if((*pLinkedList) -> mTail == pNode1 && pNode2 -> mNext == (*pLinkedList) -> mTail){
        Node* pNode2Previous = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
        pNode2Previous -> mNext = pNode1;
        pNode1 -> mNext = pNode2;
        (*pLinkedList) -> mTail = pNode2;
        (*pLinkedList) -> mTail -> mNext = NULL;
        if((*pLinkedList) -> mHead -> mNext == pNode2){
            (*pLinkedList) -> mHead -> mNext = pNode1;
        }
        return;
    }
    if((*pLinkedList) -> mTail == pNode2 && pNode1 -> mNext == (*pLinkedList) -> mTail){
        Node* pNode1Previous = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
        pNode1Previous -> mNext = pNode2;
        pNode2 -> mNext = pNode1;
        (*pLinkedList) -> mTail = pNode1;
        (*pLinkedList) -> mTail -> mNext = NULL;
        if((*pLinkedList) -> mHead -> mNext == pNode1){
            (*pLinkedList) -> mHead -> mNext = pNode2;
        }
        return;
    }
    if((*pLinkedList) -> mHead == pNode1){
        Node* pNode2previousNode = getPreviousNode(pLinkedList, pNode2);
        Node* pNodeAfterHead = (*pLinkedList) -> mHead -> mNext;
        (*pLinkedList) -> mHead = pNode2;
        pNode2previousNode -> mNext = pNode1;
        pNode1 -> mNext = pNode2 -> mNext;
        pNode2 -> mNext = pNodeAfterHead;
        return;
    }
    if((*pLinkedList) -> mHead == pNode2){
        Node* pNode1previousNode = getPreviousNode(pLinkedList, pNode1);
        Node* pNodeAfterHead = (*pLinkedList) -> mHead -> mNext;
        (*pLinkedList) -> mHead = pNode1;
        pNode1previousNode -> mNext = pNode2;
        pNode2 -> mNext = pNode1 -> mNext;
        pNode1 -> mNext = pNodeAfterHead;
        return;
    }
    if((*pLinkedList) -> mTail == pNode1){
        Node* pNodePreviousTail = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
        (*pLinkedList) -> mTail = pNode2;
        Node* pNode2previousNode = getPreviousNode(pLinkedList, pNode2);
        pNode1 -> mNext = pNode2 -> mNext;
        pNode2previousNode -> mNext = pNode1;
        pNodePreviousTail -> mNext = pNode2;
        (*pLinkedList) -> mTail -> mNext = NULL;
        return;
    }
    if((*pLinkedList) -> mTail == pNode2){
        Node* pNodePreviousTail = getPreviousNode(pLinkedList, (*pLinkedList) -> mTail);
        (*pLinkedList) -> mTail = pNode1;
        Node* pNode1previousNode = getPreviousNode(pLinkedList, pNode1);
        pNode2 -> mNext = pNode1 -> mNext;
        pNode1previousNode -> mNext = pNode2;
        pNodePreviousTail -> mNext = pNode1;
        (*pLinkedList) -> mTail -> mNext = NULL;
        return;
    }
    if(pNode1 -> mNext == pNode2){
        Node* pNode1previousNode = getPreviousNode(pLinkedList, pNode1);
        pNode1previousNode -> mNext = pNode2;
        pNode1 -> mNext = pNode2 -> mNext;
        pNode2 -> mNext = pNode1;
        return;
    }
    if(pNode2 -> mNext == pNode1){
        Node* pNode2previousNode = getPreviousNode(pLinkedList, pNode2);
        pNode2previousNode -> mNext = pNode1;
        pNode2 -> mNext = pNode1 -> mNext;
        pNode1 -> mNext = pNode2;
        return;
    }

    Node* pNode1previousNode = getPreviousNode(pLinkedList, pNode1);
    Node* pNode2previousNode = getPreviousNode(pLinkedList, pNode2);
    Node* pNode1nextNode = pNode1 -> mNext;
    pNode1previousNode -> mNext = pNode2;
    pNode1 -> mNext = pNode2 -> mNext;
    pNode2 -> mNext = pNode1nextNode;
    pNode2previousNode -> mNext = pNode1;
    return;
}

Node* recursiveMerge(Node* pCurrentNodeFrom1, Node* pCurrentNodeFrom2, int (nodeCompare) (Node*, Node*)){
    if(!pCurrentNodeFrom1) return pCurrentNodeFrom2;
    if(!pCurrentNodeFrom2) return pCurrentNodeFrom1;

    int result = nodeCompare( pCurrentNodeFrom1, pCurrentNodeFrom2);

    //Node from 1 bigger than Node from 2 or they are same
    if(result >= 0){
        pCurrentNodeFrom2 -> mNext = recursiveMerge(pCurrentNodeFrom1, pCurrentNodeFrom2 ->mNext, nodeCompare);
        return pCurrentNodeFrom2 ;
    }
    //Node from 2 bigger than Node from 1
    else{
        pCurrentNodeFrom1 -> mNext = recursiveMerge(pCurrentNodeFrom1 -> mNext, pCurrentNodeFrom2, nodeCompare);
        return pCurrentNodeFrom1;
    }
}

void merge2SortedLinkedLists(LinkedList** pLinkedList1, LinkedList** pLinkedList2, LinkedList** pMergedLinkedList, int (nodeCompare) (Node*, Node*) ){
    
    if(!listIsEmpty(*pMergedLinkedList)){
        listDelete(pMergedLinkedList);
    }
    if(!pLinkedList1 && pLinkedList2){
        (*pMergedLinkedList) -> mHead = (*pLinkedList2) -> mHead;
        (*pMergedLinkedList) -> mTail = (*pLinkedList2) -> mTail;
        return;
    }
    if(pLinkedList1 && !pLinkedList2){
        (*pMergedLinkedList) -> mHead = (*pLinkedList1) -> mHead;
        (*pMergedLinkedList) -> mTail = (*pLinkedList1) -> mTail;
        return;
    }
    if(!pLinkedList1 && !pLinkedList2){
        listInit(pMergedLinkedList);
        return;
    }
    int list1IsEmpty = listIsEmpty(*pLinkedList1);
    int list2IsEmpty = listIsEmpty(*pLinkedList2);
    if(list1IsEmpty && list2IsEmpty){
        listInit(pMergedLinkedList);
        return;
    }else if(list1IsEmpty && !list2IsEmpty){
        (*pMergedLinkedList) -> mHead = (*pLinkedList2) -> mHead;
        (*pMergedLinkedList) -> mTail = (*pLinkedList2) -> mTail;
        return;
    }else if(!list1IsEmpty && list2IsEmpty){
        (*pMergedLinkedList) -> mHead = (*pLinkedList1) -> mHead;
        (*pMergedLinkedList) -> mTail = (*pLinkedList1) -> mTail;
        return;
    }

    Node* pCurrentNodeFrom1 = (*pLinkedList1) -> mHead;
    Node* pCurrentNodeFrom2 =(*pLinkedList2) -> mHead;

    recursiveMerge(pCurrentNodeFrom1, pCurrentNodeFrom2, nodeCompare);

    int resultHead = nodeCompare((*pLinkedList1) -> mHead, (*pLinkedList2) -> mHead);
    if(resultHead >= 0){
        (*pMergedLinkedList) -> mHead = (*pLinkedList2) -> mHead;
    }else{
        (*pMergedLinkedList) -> mHead = (*pLinkedList1) -> mHead;
    }
    int resultTail = nodeCompare((*pLinkedList1) -> mTail, (*pLinkedList2) -> mTail);
    if(resultTail >= 0){
        (*pMergedLinkedList) -> mTail = (*pLinkedList1) -> mTail;
    }else{
        (*pMergedLinkedList) -> mTail = (*pLinkedList2) -> mTail;
    }
}


int getListLength(LinkedList* pLinkedList){
    int len = 0;
    Node* tmp = pLinkedList -> mHead;
    while(tmp){
        len++;
        tmp = tmp -> mNext;
    }
    return len;
}

Node* getListNodeAtNthIndex(LinkedList* pLinkedList, int n){
    Node* pNodeAtNthIndex = pLinkedList -> mHead;
    int index = 0;
    while(pNodeAtNthIndex){
        if(index == n) return pNodeAtNthIndex;
        pNodeAtNthIndex = pNodeAtNthIndex -> mNext;
        index++;
    }
    return NULL;
}

// This function is used for mergeSort
Node* merge(Node* pNodeLeft, Node* pNodeRight, int (nodeCompare) (Node*, Node*)){
    if(!pNodeLeft) return pNodeRight;
    if(!pNodeRight) return pNodeLeft;

    int result = nodeCompare(pNodeLeft, pNodeRight);
    if(result >= 0){
        pNodeRight -> mNext = merge(pNodeLeft, pNodeRight -> mNext, nodeCompare);
        return pNodeRight;
    }else{
        pNodeLeft -> mNext = merge(pNodeLeft -> mNext, pNodeRight, nodeCompare);
        return pNodeLeft;
    }
}

Node* getNodeAtNthIndex(Node* pNode, int n){
    int index = 0;
    while(pNode){
        if(index == n) return pNode;
        pNode = pNode -> mNext;
        index++;
    }
    return NULL;
}

Node* mergeSort(Node* pHeadOfListToSort, int listLen, int (nodeCompare) (Node*, Node*)){
    
    if(!pHeadOfListToSort -> mNext) return pHeadOfListToSort;
    int mid = listLen / 2;

    //Split Linked List into 2 Linked lists
    Node* pMidNode = getNodeAtNthIndex(pHeadOfListToSort, mid - 1);
    Node* pHeadLeft = pHeadOfListToSort;
    Node* pHeadRight = pMidNode -> mNext;

    //cut off the connection between the 2 Linked Lists -> Now we have 2 Linked Lists
    pMidNode -> mNext = NULL;

    //Break down the Linked Lists until there is just a single Node within a Linked List.
    //Heads of lists have to be changed.
    pHeadLeft = mergeSort(pHeadLeft, mid, nodeCompare);
    pHeadRight = mergeSort(pHeadRight, listLen - mid, nodeCompare);

    //Mergin Nodes back together
    pHeadLeft = merge(pHeadLeft, pHeadRight, nodeCompare);
    
    //Returning the newHead of the sorted Linked List.
    return pHeadLeft;
}

void listMergeSort(LinkedList** pLinkedList, int (nodeCompare) (Node*, Node*)){
    int listLen = getListLength(*pLinkedList);
    if(listLen == 0) return;
    (*pLinkedList) -> mHead  = mergeSort((*pLinkedList) -> mHead, listLen, nodeCompare);
    (*pLinkedList) -> mTail = getListNodeAtNthIndex(*pLinkedList, listLen - 1);
}