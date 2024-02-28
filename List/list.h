#ifndef _LIST_
#define _LIST_

#include <malloc.h>

#define true  0x1
#define false 0x0
#define internal static


typedef struct
Node
{
    void* elementP;
    int index;

    struct Node* next;

} Node;


typedef struct
List
{
    Node* rootNode;
    int length;

    void (*delete)(struct List*, int index);
    void* (*get)(struct List*, int index);
    void (*insert)(struct List*, void* elementP, int index);
    _Bool (*append)(struct List*, void* elementP);

} List;


void init(List* list);


#endif
