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
	int ret;

	tmp = (TLinkList *)malloc(sizeof(TLinkList));
	if(tmp == NULL)
	{
		ret = 1;
		printf("func LinkList_Create err:%d\n", ret);
		return NULL;
	}

	memset(tmp, 0, sizeof(TLinkList));

	tmp->length = 0;
	tmp->header.next = NULL;

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
	if(list == NULL)
	{
		return -1;
	}
	tmp = (TSeqList *)list;

	tmp->length = 0;
	tmp->header.next = NULL;

	return 0;

}

int LinkList_Length(LinkList* list)
{
	TLinkList* tmp = NULL;
	if(list == NULL)
	{
		return -1;
	}
	tmp = (TLinkList *)list;
	return tmp->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int i = 0;
	LinkListNode* current = NULL;
	TLinkList* tList = NULL;

	if(list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	tList = (TLinkList *)list;

	current = &(tList->header);

	for(i = 0; i < pos; i++)
	{
		current = current->next;	
	}

	node->next = current->next;
	current->next = node;

	tList->length ++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int i = 0;
	LinkListNode* current = NULL;
	TLinkList *tList = NULL;

	if(list == NULL || pos < 0)
	{
		return NULL;
	}

	tList = (TLinkList *)list;

	current = &(tList->header);

	for(i=0; i<pos; i++)
	{
		current = current->next;
	}

	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int i = 0;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;
	TLinkList* tList = NULL;

	if(list == NULL || pos < 0)
	{
		return NULL;
	}

	tList = (TLinkList *)list;

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
