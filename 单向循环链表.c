#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *next;//前驱和后继

}DNode,*DLinklist;

//函数声明
DNode *InitLink();
void display(DNode* first);
DNode * InsertLink(DNode * head,int elem,int data);
DNode * ModifyLink(DNode *first,int elem,int data);
DNode * DeleteLink(DNode *first,int elem);
int SearchLink(DNode *first,int data);


//主函数
int main(){
    DNode *head=InitLink();//初始化链表
    display(head);
    head=InsertLink(head,2,11);//插入第2个结点值为11
    display(head);
}

//初始化函数
DNode * InitLink(){
    DNode* head = (DNode*)malloc(sizeof(DNode));
    if(NULL == head) {
        printf("分配头结点空间失败，程序终止！\n");
        return 0;
    }
    DNode *temp=head;
    temp->next=NULL;
    for (int i = 1; i < 6; i++)
	{
		DNode* a = (DNode*)malloc(sizeof(DNode));
		a->data = i;
		a->next = head;  
		temp->next=a;
		temp = temp->next;
	}

    return head;

}
//打印循链表
void display(DNode *head){
    printf("打印单链表:\n");
    DNode* temp=head;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next!=head) {
        temp=temp->next;
        printf("[%d] ",temp->data);
    }
    printf("\n");
}

//链表插入元素
DNode * InsertLink(DNode * head,int elem,int data){
    //判断传入参数
    if (elem<1&&head==NULL)
    {
        printf("传入的参数有误或链表为空，请检查！！\n");
        exit(-1);
    }
    DNode *temp=head;//传入链表
    //判断插入的位置
    for (int i = 1; i < elem; i++)
    {
        temp=temp->next;
    }
    //插入操作
    DNode *a =(DNode*)malloc(sizeof(DNode));
    a->data=data;
    a->next=temp->next;
    temp->next=a;
    printf("操作：插入成功！\n");
    return head;

}

