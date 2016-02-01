#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "seqqueue.h"

typedef struct _Student
{
	char* name;
	int age;
}Student;

int main()
{
	int i = 0, len = 0;
	Student s1, s2, s3;
	Student* tmpStudent = NULL;
	SeqQueue* queue = NULL;

	queue = SeqQueue_Create(5);

	s1.name = "tbf001";
	s1.age = 101;

	s2.name = "tbf002";
	s2.age = 102;

	s3.name = "tbf003";
	s3.age = 103;

	SeqQueue_Append(queue, &s1);
	SeqQueue_Append(queue, &s2);
	SeqQueue_Append(queue, &s3);	

	len = SeqQueue_Length(queue);
	printf("capacity is %d,and len is %d\n", SeqQueue_Capacity(queue), len);

	for(i = 0; i < len; i++)
	{
		tmpStudent = SeqQueue_Retrieve(queue);	
		printf("%s is %d\n", tmpStudent->name, tmpStudent->age);
	}

	printf("len is %d now\n", SeqQueue_Length(queue));

	SeqQueue_Clear(queue);
	SeqQueue_Destroy(queue);

	return 0;
}
