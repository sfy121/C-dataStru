#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;
/*
 * typedef struct _tag_CircleListNode CircleListNode;
 * struct _tag_CircleListNode
 * {
 * 	CircleListNode* next;
 * 	};
 * 	*/
typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode * next;
}CircleListNode;

CircleList* CircleList_Create();

void List_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//add

//根据结点的值 进行数据的删除
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* list);

CircleListNode* CircleList_Current(CircleList* list);

//游标指向2号位置 
//把2号位置返回出来,同时让游标下移到3号位置
CircleListNode* CircleList_Next(CircleList* list);

#endif
