#include <stdio.h>
#include <string.h>

typedef struct
{
    int data;
    struct linkNode *nextPtr;
}linkNode;

int main()
{
    int count,num;

    linkNode *head;
    linkNode *Ptr;

    scanf("%d",&count);

    head=malloc(sizeof(linkNode));

    Ptr = head;


    for(int i=0;i<count;i++)
    {
        scanf("%d",&num);

        Ptr->data = num;

        Ptr->nextPtr=malloc(sizeof(linkNode));

        Ptr=Ptr->nextPtr;
    }


}
