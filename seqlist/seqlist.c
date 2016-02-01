#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "seqlist.h"

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	int** node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	int ret;
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if(tmp == NULL)
	{
		ret = 1;
		printf("func SeqList_Create() err :%d \n", ret);
		return NULL;
	}

	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);

	if(tmp->node == NULL)
	{
		ret = 2;
		printf("func SeqList_Create() malloc err: %d \n", ret);
		return NULL;
	}

	memset(tmp->node, 0, sizeof(void *) * capacity);

	return tmp;
}

void SeqList_Destroy(SeqList* list)
{
	TSeqList* tmp = NULL;
	if(list == NULL)
	{
		return;
	}

	tmp = (TSeqList *)list;
	if(tmp->node != NULL)
	{
		free(tmp->node);
	}

	free(tmp);
	return;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList* tmp = NULL;

	if(list == NULL)
	{
		return;
	}

	tmp = (TSeqList *)list;
	tmp->length = 0;
	memset(tmp->node, 0, sizeof(void *) * (tmp->capacity));

	return;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList* tmp = NULL;

	if(list == NULL)
	{
		return;
	}

	tmp = (TSeqList *)list;

	return tmp->capacity;
}

int SeqList_Length(SeqList* list)
{
	TSeqList* tmp = NULL;

	if(list == NULL)
	{
		return -1;
	}

	tmp = (TSeqList *)list;

	return tmp->length;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* tList = NULL;	
	int i = 0;
	if(list == NULL || node == NULL)
	{
		return -1;
	}

	tList = (TSeqList *)list;

	if(tList->length >= tList->capacity)
	{
		return -2;
	}

	if(pos > tList->length)
	{
		pos = tList->length;
	}

	for(i = tList->length; i > pos; i--)
	{
		tList->node[i] = tList->node[i-1];
	}

	tList->node[i] = (int *)node;
	tList->length++;

	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList* tList = NULL;
	SeqListNode* tmp = NULL;

	tList = (TSeqList *)list;

	if(list == NULL || pos < 0 || pos >= tList->length)
	{
		return NULL;
	}

	tmp = tList->node[pos];
	return tmp;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList* tList = NULL;
	SeqListNode* tmp = NULL;
	int i = 0;

	tList = (TSeqList *)list;

	if(list == NULL || pos < 0 || tList->length <= 0 || pos >= tList->capacity)
	{
		return NULL;
	}

	tmp = tList->node[pos];

	for(i = pos; i < tList->length - 1; i++)
	{
		tList->node[i] = tList->node[i+1];
	}

	tList->length--;

	return tmp;
}
