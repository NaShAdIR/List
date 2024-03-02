#include "list.h"


internal Node*
getNode(
    List* instance, 
    int64 index
)
{
    Node* node = instance->rootNode;    
    if (index < 0 || index > instance->length - 1)
    {
        return 0x0;
    }
    while (node->index != index)
    {
        node = node->next;
    }

    return node;
}


internal void
restructuring(
    List* instance,
    int64 index,
    void* value
)
{
    Node* previous = getNode(instance, (index - 1));
    if (previous)
    {
        previous->next = value;
    }
    else
    {
        instance->rootNode = value;
    }
}


internal void
del(List* instance, Node* node)
{
    if (node->next)
    {
        Node* tempNode = node;
        restructuring(
            instance,
            node->index,
            node->next
        );
        while (tempNode->next)
        {
            tempNode->next->index--;
            tempNode = tempNode->next;
        }
    }
    else
    {
        restructuring(
            instance,
            node->index,
            0x0
        );
    }
    instance->length--;
    free(node);
}


internal void
delete(
    List* instance, 
    int64 index
)
{
    Node* node = getNode(instance, index);
    if (node)
    {
        del(instance, node);
    }
}


internal void
insert(
    List* instance,
    void* elementP, 
    int64 index
)
{

}


internal _Bool
append(
    List* instance, 
    void* elementP
)
{
    if (!instance->rootNode)
    {
        instance->rootNode = malloc(sizeof(Node));
        if (instance->rootNode)
        {
            instance->rootNode->elementP = elementP;
            instance->rootNode->index = 0x0;
            instance->rootNode->next = 0x0;
            instance->length++;

            return true;
        }
    }
    else
    {
        Node* lastNode = getNode(instance, instance->length - 1);
        Node* newNode = malloc(sizeof(Node));
        if (newNode && lastNode)
        {
            newNode->elementP = elementP;
            newNode->index = (lastNode->index + 1);
            newNode->next = 0x0;

            lastNode->next = newNode;
            instance->length++;

            return true;
        }
        free(newNode);
    }
    
    return false;
}


internal void*
get(List* instance, int64 index)
{
    return getNode(instance, index)->elementP;
}


void 
init(List* instance)
{
    instance->length = 0x0;

    instance->delete = delete;
    instance->insert = insert;
    instance->append = append;
    instance->get = get;
}

