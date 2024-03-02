#ifndef _LIST_
#define _LIST_

#include <malloc.h>

#define true  0x1
#define false 0x0
#define internal static

#define int64 __int64
#define int8  __int8


typedef struct
Node
{
    void* elementP;
    int64 index;

    struct Node* next;

} Node;


typedef struct
List
{
    Node* rootNode;
    int64 length;

    void (*delete)(struct List*, int64 index);
    void* (*get)(struct List*, int64 index);
    void (*insert)(struct List*, void* elementP, int64 index);
    _Bool (*append)(struct List*, void* elementP);

} List;


void init(List* list);


#endif
