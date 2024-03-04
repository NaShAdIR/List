#include <stdio.h>
#include "list.h"

#define VOIDP(pointer) (void*)pointer
#define FN_TYPE(return_type, arg_1, arg_2, pointer) \
               (return_type (*)(arg_1, arg_2))pointer
    

internal int
add(int a, int b)
{    
    return a + b;
}


internal void 
dataHendler(List data)
{
    int (*fn)(int, int);
    fn = FN_TYPE(
        int,
        int,
        int,
        data.get(&data, 0)
    );

    printf("%p %p\n", VOIDP(fn), VOIDP(add));
    printf("%d\n", fn(1, 1));
}


int main(void)
{
    List data;

    int a = 0;
    int b = 111;
    
    init(&data);
    data.append(&data, &a);
    data.append(&data, VOIDP(add));
    data.append(&data, &b);
    data.remove(&data, 0);
    
    dataHendler(data);
    
    return 0;
}

