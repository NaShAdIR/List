#include <stdio.h>
#include "list.h"


static int
add(int a, int b)
{
    return a + b;
}


int main(void)
{
    int a = 0;
    int b = 111;

    List data;
    init(&data);

    data.append(&data, &a);
    data.append(&data, add);
    data.append(&data, &b);
    data.remove(&data, 0);

    int (*fn)(int, int) = data.get(&data, 0);
    printf("%p %p\n", fn, add);

    return 0;
}

