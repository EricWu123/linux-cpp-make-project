#include "module_a.h"

int module_a_func()
{
    printf("%s\n", __FUNCTION__);
    common_func();
    return 0;
}