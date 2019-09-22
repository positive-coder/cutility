#include "clist.h"

List init(List li )
{
	if(li == NULL)
		return NULL;

	li->pNext = NULL;
}

List apend(List list, Node *node)//front insert
{   

	if(node == NULL)
		return list;

	if (list == NULL)
	{
		return NULL;
	}
	if (list->pNext != NULL)
	{
		Node* tmp = list->pNext;
		list->pNext = node;
		node->pNext = tmp;
		return list;
	}
	else
	{
		node->pNext = NULL;	
		list->pNext = node;
		return list;
	}
	
}

List deleteNode(List list, Node *node)
{
	if(list == NULL)
		return NULL;

	if(node == NULL)
	{
		return list;
	}

	Node *head = list;
	while (list)
	{
		if (list->pNext == node)
		{
			Node* tmpNode = list->pNext;
			list->pNext = tmpNode->pNext;
			free((void*) (tmpNode->entity));
			free((void*)(tmpNode));
			return head;
		}
		list = list->pNext;
	}

	return head;

}

List insert(List list, Node *node, Pos pos)// insert node in one pos
{
	if(list == NULL)
		return NULL;

	if(node == NULL || pos == NULL)
	{
		return list;
	}
	

	Head head = list;
	while (list != pos && list->pNext)
	{
		list = list->pNext;
	}
	if (list == pos)
	{
		Node* tmpNode = list->pNext;
		list->pNext = node;
		node->pNext = tmpNode;
	}
	return list;
}

void freeList(List list)
{
	if(list == NULL)
		return ;

	while (list)
	{
		Node* tmpNode = list;
		list = list->pNext;
		free((void*)(tmpNode->entity));
		free((void*)(tmpNode));
	}
}

int length(List list)
{
	int len = 0;
	List tmpli = list;
	while (tmpli)
	{
		len++;
		tmpli = tmpli->pNext;

	}
	return len;
}