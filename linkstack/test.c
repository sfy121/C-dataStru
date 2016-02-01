#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkstack.h"

typedef struct _Teacher{
	char* name;
	int age;
}Teacher;

int main()
{
	LinkStack* stack = NULL;
	Teacher t1, t2, t3;
	Teacher*  tmpTeacher = NULL; 	
	int i = 0, length = 0;

	t1.age = 11;
	t1.name = "tbf001";

	t2.age = 12;
	t2.name = "tbf002";

	t3.age = 13;
	t3.name = "tbf003";

	stack = LinkStack_Create();

	LinkStack_Push(stack, &t1);
	LinkStack_Push(stack, &t2);
	LinkStack_Push(stack, &t3);

	length = LinkStack_Size(stack);
	printf("stack_length:%d\n", length);

	tmpTeacher = (Teacher *)LinkStack_Top(stack);
	printf("%s is %d\n", tmpTeacher->name, tmpTeacher->age);
	for(i = 0; i < length; i++)
	{
		tmpTeacher = (Teacher *)LinkStack_Pop(stack);	
		printf("%s is %d\n", tmpTeacher->name, tmpTeacher->age);
	}

	LinkStack_Destroy(stack);
	return 0;
}
