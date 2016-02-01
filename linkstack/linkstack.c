#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStack
{
	LinkListNode node;
	void* item;
}TLinkStack;

LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	int len = LinkStack_Size(stack);
	if(len > 0)
		LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack)
{
	while(LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
}

int LinkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	TLinkStack *tmp = NULL;

	tmp = (TLinkStack *)malloc(sizeof(TLinkStack));
	tmp->item = item;

	ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
	if(ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", ret);
		free(tmp);
		return ret;
	}

	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStack* tmp = NULL;	
	void* item = NULL;

	tmp = (TLinkStack *)LinkList_Delete(stack, 0);
	if(tmp == NULL)
	{
		printf("func LinkStact_Delete() err \n");
		return NULL;
	}

	item = tmp->item;
	return item;
}

void* LinkStack_Top(LinkStack* stack)
{
	TLinkStack* tmp = NULL;
	void* item = NULL;

	tmp = (TLinkStack *)LinkList_Get(stack, 0);
	if(tmp == NULL)
	{
		printf("func LinkList_Get err \n");
		return NULL;
	}
	item = tmp->item;
	return item;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}
