#include "sdt.h"

namespace tsssdk
{
unsigned int gen_random()
{
    static char flag = 0;
    if (!flag)
    {
        srand(time(NULL));
        flag = 1;
    }

    unsigned int r = rand();
    return ++r;
}
}
