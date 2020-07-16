#include <stdio.h>
#include <string.h>

#include "list.h"

LIST_HEAD(mhead);

struct foo{
	struct list_head entry;
	int x;
};

struct bar{
	struct list_head entry;
	int y;
};

int main(void)
{
	struct foo *pos;
	struct foo foo1={.x = 111};
	struct foo foo2={.x = 222};
	
	list_add_tail(&foo1.entry,&mhead);
	list_add_tail(&foo2.entry,&mhead);

	list_for_each_entry(pos,&mhead,entry){
		printf("%d\n",pos->x);
	}
	return 1;
}


