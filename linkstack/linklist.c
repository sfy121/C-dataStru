#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList* tmp = NULL;

	tmp = (TLinkList *)malloc(sizeof(TLinkList));

	if(tmp == NULL)
	{
		printf("func LinkList_Create() err\n");
		return NULL;
	}

	memset(tmp, 0, sizeof(tmp));

	tmp->header.next = NULL;
	tmp->length = 0;

	return tmp;
}

void LinkList_Destroy(LinkList* list)
{
	if(list == NULL)
	{
		return;
	}

	free(list);

	return;
}

void LinkList_Clear(LinkList* list)
{
	TLinkList* tmp = NULL;	
	tmp = (TLinkList *)list;

	if(tmp == NULL)
	{
		return;
	}

	tmp->header.next = NULL;
	tmp->length = 0;

	return;
}

int LinkList_Length(LinkList* list)
{
	TLinkList* tmp = NULL;
	tmp = (TLinkList *)list;

	if(tmp == NULL)
	{
		return -1;
	}

	return tmp->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int i = 0;
	LinkListNode *current = NULL;
	TLinkList *tList = NULL;

	tList = (TLinkList *)list;

	if(tList == NULL || node == NULL || pos < 0 || pos > tList->length)
	{
		return -1;
	}

	current = &(tList->header);

	for(i = 0; i < pos; i++)
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	tList->length++;

	return 0;

}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int i = 0;
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;

	tList = (TLinkList *)list;

	if(tList == NULL || pos < 0 || pos > tList->length)
	{
		return NULL;
	}

	current = &(tList->header);

	for(i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int i = 0;
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;

	tList = (TLinkList *)list;

	if(tList == NULL || pos < 0 || pos > tList->length)
	{
		return NULL;
	}

	current = &(tList->header);

	for(i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;

	current->next = ret->next;

	tList->length--;

	return ret;
}
