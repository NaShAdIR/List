#include "list.h"


int add(int a, int b)
{
    return a + b;
}


int main(void)
{
    List data;
    init(&data);

    int a = 0;
    int b = 1;

    data.append(&data, &a);
    data.append(&data, add);
    data.append(&data, &b);
    
    data.delete(&data, 2);

    return 0;
}

