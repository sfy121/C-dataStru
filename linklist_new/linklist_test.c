#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"
typedef struct _Teacher
{
	LinkListNode node;
	char name[32];
	int age;
}Teacher;

int main()
{
	LinkList* list = NULL;
	Teacher* tmp = NULL;
	int i = 0;

	Teacher t1,t2,t3,t4;

	t1.age = 1;
	strcpy(t1.name,"tbf1");

	t2.age = 2;
	strcpy(t2.name,"tbf2");

	t3.age = 3;
	strcpy(t3.name,"tbf3");

	t4.age = 4;
	strcpy(t4.name,"tbf4");

	list = LinkList_Create();

	LinkList_Insert(list, (LinkListNode *)&t1, 0);
	LinkList_Insert(list, (LinkListNode *)&t2, 0);
	LinkList_Insert(list, (LinkListNode *)&t3, 1);
	LinkList_Insert(list, (LinkListNode *)&t4, 0);

	for(i = 0; i < LinkList_Length(list); i++)
	{
		tmp = (Teacher *)LinkList_Get(list, i); 

		if(tmp == NULL)
		{
			return -1;
		}

		printf("%s is %d\n",tmp->name, tmp->age);
	}

	LinkList_Destroy(list);

	return 0;
}

