#ifndef CLIST
#define CLIST
#include "stdio.h"
#include "stdlib.h"

#ifdef TEST
#define Entity int
#else
#define Entity wchar_t*
#endif


struct Node
{
	int len ;
	Entity entity ;
	Node* pNext;
};

typedef Node* Head;
typedef Head List;
typedef Node* Pos;

List init(List);

List apend(List list,Node* node);

List deleteNode(List list,Node* node);

List insert(List list, Node* node, Pos pos);

void freeList(List list);

int length(List list);

#endif