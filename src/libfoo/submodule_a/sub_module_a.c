#include "sub_module_a.h"

int sub_module_a_func()
{
    printf("%s\n", __FUNCTION__);
    common_func();
    return 0;
}