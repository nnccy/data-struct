#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node*  next;

}Lnode,*Node;



Node create ()  //����һ������
{
    Node p1,last,head;
    head = (Node) malloc(sizeof(Lnode));
    last = head;
    int num = 0;
    scanf("%d",&num);
    while(num != -1)
    {
        p1 = (Node) malloc(sizeof(Lnode));

        p1->data = num;
        last->next = p1;
        last =last->next;
//        if(head == NULL)
//        {
//            head = p1;
//            last = p1;
//        }
//        else
//        {
//            last->next = p1;
//            last = p1;
//
//        }

    scanf("%d",&num);
    }
    if(head)
        last->next = NULL;
    else
        printf("û�д���");

return head;
}

void printall(Node head)  //��ӡ������
{
    Node x ;
    x = head->next;


    while(x!=NULL)
    {
        printf("%d\n",x -> data);
        x = x->next;
    }
}

Node returnp(Node head,int k)  //����һ��λ���ϵĽڵ�
{
    Node p1;
    int i = 0;
    p1 = head->next;
    while(i<k && p1->next != NULL)
    {
        p1 = p1->next;
        i++;

    }
    if(i == k)
    {
        return p1;

    }
    else
    {
        return NULL;
    }

}

Node deletep(Node head,int k)  //ɾ��ָ��λ�ýڵ�
{

    Node p1,p2;
    if (k == 0)
    {
        p1 = head->next;
        head->next = p1 ->next;
        free(p1);
        return head;
    }

    p2 = returnp(head,k-1);
    p1 = p2->next;
    if (p2 == NULL)
    {
        printf("������");
        return NULL;


    }
    else if (p1 == NULL)
    {
        printf("������");
        return NULL;

    }

    else
    {
        p2->next = p1->next;
        free(p1);
        return head;

    }




}

Node insert(Node head ,int k ,int s) //����ָ��λ�ýڵ�
{
    Node p1;
    p1 = (Node)malloc (sizeof(Lnode));
    if(k==0)
    {

        p1->next = head ->next;
        p1->data = s;
        head->next = p1;
    }
    else
    {
         Node p2,p3;
         p2 = head->next;
         p3 = p2->next;
        int i = 1;
        while(i<k && p3 != NULL)
        {
            p2 = p2->next;
            p3=p3->next;
            i++;
        }
        if (i == k)
        {
            p1->data = s;
            p2->next = p1;
            p1->next = p3;

        }
        else
        {
            printf("��Χ����");

        }


    }

    return head;
}




Node delete(Node head,int num) //ɾ��һ��ֵΪnum�Ľڵ�
{

    Node p1;
    Node p2;
    p1 = head->next;
    p2 = p1->next;
    if (p1==NULL)
    {
        printf("û��Ҫɾ���Ľڵ�\n");

    }

    if(p1->data==num)
    {
        head->next = p2;
        free(p1);

    }
    else
    {
        while(p2->data!=num && p2->next != NULL)
                //ֻҪһ�������㣬Ϊ0����
        {

            p1 = p1->next;
            p2 = p2->next;

        }
        if(p2->data == num)
        {
            p1->next = p2->next;
            free(p2);
            printf("ɾ����һ���ڵ�\n");
        }
        else
        {
            printf("û�д˽ڵ�\n");
        }

    }

    return head;
}



int main()
{

    Node head = NULL;
    head = create();
    printall(head);

    //Node p;
    //p = returnp(head,4);
    // printf("%d",p->data);

    //head = deletep(head,0);
    //printall(head);


//    head = delete(head,0);
//    printall(head);


    head = insert(head ,2,5);
    printall(head);

    return 0;
}




