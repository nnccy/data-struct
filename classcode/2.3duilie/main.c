#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
}*queue,lqueue;

typedef struct Qnode
{
    struct Node* front;
    struct Node* rear;
} *linkqueue;



void insert(linkqueue q,int a)
{
    queue p;
    p = (queue)malloc(sizeof(lqueue));
    p->data = a;
    p->next =NULL;
    q->rear->next = p;
    q->rear = p;      //���ⲽ֮ǰ��front��rear����һ���ַ
    //֮��q�ĵ�ַ�ı�

}
int delete (linkqueue q)
{
    int a;

    queue p;
    if (q->front == q->rear)
    {
        printf("����");

    }
    else
    {
        p = q->front->next;
        a = p->data;
        q->front->next = p->next;
        if(q->rear == p)
        {
            q->rear = q->front;
        }

        free(p);
    }


    return a;

}

struct Qnode creatqueue()
{
    struct Qnode q;
    q.front = q.rear= (queue)malloc(sizeof(lqueue));
    if(!(q.rear))
    printf("gege");
    q.front->next = NULL;



 return q;
}



int main()
{
//    queue p;
//    p = (queue)malloc(sizeof(lqueue));
    int a;
    struct Qnode q;
    q = creatqueue();
    insert(&q,2);

    insert(&q,3);
    a = delete(&q);
    a = delete(&q);
    a = delete(&q);
    printf("%d",a);
    //a = delete(&q);
    //printf("%d",a);
//    a = delete(&q);
//    printf("%d",a);
    return 0;
}
