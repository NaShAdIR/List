#include "list.h"


Node* 
getNode(
    List* instance, 
    int index
)
{
    if (index < 0 || index > instance->length - 1)
    {
        return 0x0;
    }
    Node* node = instance->rootNode;
    while (node->index != index)
    {
        node = node->next;
    }
    return node;
}


void 
__restructuring(
    List* instance,
    int index, 
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


void _del(List* instance, Node* node)
{
    if (node->next)
    {
        __restructuring(
            instance,
            node->index,
            node->next
        );
        Node* tempNode = node;
        while (tempNode->next)
        {
            tempNode->next->index--;
            tempNode = tempNode->next;
        }
    }
    else
    {
        __restructuring(
            instance,
            node->index,
            0x0
        );
    }
    instance->length--;
    free(node);
}


void 
delete(
    List* instance, 
    int index
)
{
    Node* node = getNode(instance, index);
    if (node)
    {
        _del(instance, node);
    }
}


void 
insert(
    List* instance,
    void* elementP, 
    int index
)
{

}


_Bool
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

        return false;
    }

    Node* lastNode = getNode(
        instance, 
        instance->length - 1
    );
    Node* newNode = malloc(sizeof(Node));
    if (newNode)
    {
        newNode->elementP = elementP;
        newNode->index = (lastNode->index + 1);
        newNode->next = 0x0;

        lastNode->next = newNode;
        instance->length++;

        return true;
    }

    return false;
}


void* 
get(List* instance, int index)
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

