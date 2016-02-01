#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "seqstack.h"

typedef struct _Student
{
	char* name;
	int age;
}Student;

void main()
{
	int i = 0;
	Student s1, s2, s3;	
	SeqStack* stack;
	Student* top;

	s1.name = "tbf1";
	s1.age = 101;

	s2.name = "tbf2";	
	s2.age = 102;

	s3.name = "tbf3";
	s3.age = 103;

	stack = SeqStack_Create(10);

	SeqStack_Push(stack, &s1);
	SeqStack_Push(stack, &s2);
	SeqStack_Push(stack, &s3);

	printf("len:%d\n", SeqStack_Size(stack));
	printf("capacity:%d\n", SeqStack_Capacity(stack));

	top = (Student *)SeqStack_Top(stack);
	printf("top:%s\n",top->name);

	while(SeqStack_Size(stack) > 0)
	{
		Student* tmp = NULL;
		tmp = SeqStack_Pop(stack);
		printf("%s is %d\n",tmp->name,tmp->age);
	}
	printf("after pop size is %d\n", SeqStack_Pop(stack));
	SeqStack_Destroy(stack);
}

