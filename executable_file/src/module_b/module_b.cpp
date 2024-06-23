#include "module_b.h"

char * module_b_func(int a)
{
    a++;
    printf("%s, a:%d\n", __FUNCTION__, a);
    return NULL;
}