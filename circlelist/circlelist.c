#include <stdio.h>
#include <malloc.h>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;

	int length;
}TCircleList;

CircleList* CircleList_Create()
{
	TCircleList* ret = (TCircleList *)malloc(sizeof(TCircList));

	if(ret == NULL)
	{
		return NULL;
	}

	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;

	return ret;
}

void CircleList_Destroy(CircleList* list)
{
	if(list == NULL)
	{
		return;
	}

	free(list);
}

void CircleList_Clear(CircleList* list)
{
	TCircleList* sList = (TCircleList *)list;
	if (sList == NULL)
	{
		return;
	}

	sList->length = 0;
	sList->header.next = NULL;
	sList->slider = NULL;
}

int CircleList_Length(CircleList* list)
{
	TCircleList* sList = (TCircleList)list;
	if(sList == NULL)
	{
		return -1;
	}

	return sList->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int ret = 0, i = 0;
	TCircleList* sList = (TCircleList *)list;

	if(list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	{
		CircleListNode* current = (CircleListNode *)sList;

		for(i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		node->next = current->next;
		current->next = node;

		if( sList->length == 0 )
		{
			sList->slider = node;
		}

		sList->length++;

		if(current == (CircleListNode *)sList)
		{
			CircleListNode* last = CircleList_Get(sList, sList->length = 1);
			last->next = current->next;
		}

	}

	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList* sList = (TCircleList *)list;
	CircleListNode* current = NULL;
	int i = 0;

	if(sList == NULL || pos < 0)
	{
		return NULL;
	}

	current = &(sList->header);

	for(i = 0; i < pos; i++)
	{
		current	= current->next;
	}

	return current->next;

}


