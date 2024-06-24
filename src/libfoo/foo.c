#include "foo.h"
#include "sub_module_a.h"
#include "common.h"

int foo(int a)
{
    printf("%s %d\n", __FUNCTION__, a);
    common_func();
    sub_module_a_func();
    return 0;
}