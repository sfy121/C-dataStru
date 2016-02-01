#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

#include "seqlist.h"

typedef struct _Teacher
{
	char name[32];
	int age;
}Teacher;

int main()
{
	int ret = 0, i = 0;
	SeqList* list = NULL;
	Teacher* tmp = NULL;

	Teacher t1, t2, t3;
	t1.age = 31;
	strcpy(t1.name, "tbf1");
	t2.age = 32;
	strcpy(t2.name, "tbf2");
	t3.age = 33;
	strcpy(t3.name, "tbf3");

	list = SeqList_Create(10);	

	SeqList_Insert(list, (SeqListNode *)&t1, 0);
	SeqList_Insert(list, (SeqListNode *)&t2, 0);
	SeqList_Insert(list, (SeqListNode *)&t3, 1);

	for(i = 0; i < SeqList_Length(list); i++)
	{
		tmp = (Teacher *)SeqList_Get(list, i);
		if(tmp != NULL)
		{
			printf("%s is %d\n", tmp->name, tmp->age);
		}
	}

	SeqList_Destroy(list);

	return 0;
}
