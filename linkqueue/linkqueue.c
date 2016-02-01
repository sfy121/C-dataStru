#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"
#include "linkqueue.h"

typedef struct _tag_LinkQueueNode
{
	LinkListNode node;
	void* item;
}TLinkQueueNode;

LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue* queue)
{
	while(LinkList_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
}

int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	TLinkQueueNode* tmp = NULL;

	tmp = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if(tmp == NULL)
	{
		return -1;
	}

	tmp->item = item;

	ret = LinkList_Insert(queue, (LinkListNode *)tmp, LinkList_Length(queue));
	if(ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", ret);
		free(tmp);
		return ret;
	}

	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueueNode* tmp = NULL;
	void* item = NULL;

	tmp = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if(tmp == NULL)
	{
		return NULL;
	}

	item = tmp->item;
	free(tmp);

	return item;
}

void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueueNode* tmp = NULL;
	void* item = NULL;

	tmp = (TLinkQueueNode *)LinkList_Get(queue, 0);
	if(tmp == NULL)
	{
		return NULL;
	}

	item = tmp->item;

	return item;
}

int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}
