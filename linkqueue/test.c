#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"
#include "linkqueue.h"

typedef struct _Dog
{
	char* name;
	int age;
}Dog;

int main()
{
	int i = 0, len = 0;
	Dog g1, g2, g3;
	Dog* tmpDog = NULL;
	LinkQueue* queue = NULL;

	g1.name = "tea1";
	g1.age = 111;

	g2.name = "tea2";
	g2.age = 112;

	g3.name = "tea3";
	g3.age = 113;

	queue = LinkQueue_Create();

	LinkQueue_Append(queue, &g1);
	LinkQueue_Append(queue, &g2);
	LinkQueue_Append(queue, &g3);

	printf("len is %d\n", LinkQueue_Length(queue));

	while(LinkQueue_Length(queue))
	{
		tmpDog = LinkQueue_Retrieve(queue);
		printf("%s is %d\n", tmpDog->name, tmpDog->age);
	}

	LinkQueue_Destroy(queue);

	return 0;
}
