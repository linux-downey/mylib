#include <stdio.h>
#include <stdlib.h>

//传入 16 进制字符串,返回 16 进制,第二个参数 end 指向字符串中第一个不能转换为数字的字符.

int main(void)
{
	char *ptr1 = "0x12345678";
	char *ptr2 = "2345hj67";
	char *ptr3 = "ji123455";
	char *end = NULL;
	printf("0x%x\n",strtoul(ptr1,&end,16));
	printf("end = %c\n",*end);
	printf("0x%x\n",strtoul(ptr2,&end,16));
	printf("end = %c\n",*end);
	printf("0x%x\n",strtoul(ptr3,&end,16));
	printf("end = %c\n",*end);

}


