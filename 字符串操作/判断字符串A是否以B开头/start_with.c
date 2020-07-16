#include <stdio.h>
#include <string.h>

//也可以改成返回 bool 类型的数据,这里返回的是 path.

char* path_startswith(const char *path, const char *prefix) {

        if ((path[0] == '/') != (prefix[0] == '/'))
                return NULL;

        for (;;) {
                size_t a, b;

                path += strspn(path, "/");
                prefix += strspn(prefix, "/");

                if (*prefix == 0)
                        return (char*) path;

                if (*path == 0)
                        return NULL;

                a = strcspn(path, "/");
                b = strcspn(prefix, "/");

                if (a != b)
                        return NULL;

                if (memcmp(path, prefix, a) != 0)
                        return NULL;

                path += a;
                prefix += b;
        }
}

int main(void)
{
	printf("%d\n",(unsigned long)path_startswith("/sys/class/","/sys"));
	printf("%d\n",(unsigned long)path_startswith("/sys/class/","/bus"));	
	return 1;
}

