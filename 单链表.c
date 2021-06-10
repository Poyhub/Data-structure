#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;

//函数声明
LNode * InitLink();
void display(LNode* first);
LNode * InsertLink(LNode *first,int elem,int data);
LNode * ModifyLink(LNode *first,int elem,int data);
LNode * DeleteLink(LNode *first,int elem);
int SearchLink(LNode *first,int data);

//主函数
int main() {
	LNode* first = InitLink();//初始化链表（1，2，3，4）
	display(first);//打印链表
    
    first=InsertLink(first,3,7);//插入第3个结点的值为7
    display(first);

    first=ModifyLink(first,3,77);//修改第3个结点的值为77
    display(first);

    SearchLink(first,77);//这里查找的是数值，不是位置
    SearchLink(first,70);

    first=DeleteLink(first,3);//删除第3个位置的结点
    display(first);
	return 0;
}

//初始化单链表
LNode *InitLink()
{
	LNode*first = (LNode*)malloc(sizeof(LNode));
     if(NULL == first) {
        printf("分配头结点空间失败，程序终止！\n");
        exit(-1);
    }
	LNode* temp = first;
    temp->next=NULL;
	for (int i = 1; i < 6; i++)
	{
		LNode* a = (LNode*)malloc(sizeof(LNode));
		a->data = i;
		a->next = NULL;
		temp->next=a;
		temp = temp->next;
	}
	return first;
}
//打印链表
void display(LNode *first){
    printf("打印单链表:\n");
    LNode* temp=first;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp=temp->next;
        printf("[%d] ",temp->data);
    }
    printf("\n");
}
//插入结点
LNode * InsertLink(LNode *first,int elem,int data){
    LNode * temp=first;
    //寻找插入点
    for (int i = 1; i < elem; i++)
    {
        temp=temp->next;
        if (temp==NULL)
        {
            printf("插入位置无效\n");
            return first;
        }
        
    }
    //为新结点申请空间
    LNode *new_Node=(LNode*)malloc(sizeof(LNode));
    new_Node->data=data;
    new_Node->next=temp->next;
    temp->next=new_Node;
    return first;
    

} 
//修改结点
LNode * ModifyLink(LNode *first,int elem,int data){
    LNode *temp=first;
    for (int i = 1; i < elem; i++)
    {
        temp=temp->next;
    }
    temp->next->data=data;
    return first;
    
}
//删除结点
LNode * DeleteLink(LNode *first,int elem){
    LNode * temp=first;
    for (int i = 1; i < elem; i++)
    {
        temp=temp->next;
    }
    LNode *del_Node=temp->next;
    temp->next=temp->next->next;
    free(del_Node);
    return(first);

}
//查找结点
int SearchLink(LNode *first,int data){
    int i=1;
    LNode *temp=first;
    while (temp->next)
    {
        temp=temp->next;
        if (temp->data==data)
        {
           printf("查找到第%d个元素的值：%d \n",i,temp->data);
           return 0;
        }
        ++i;
    }
    printf("对不起，没有找到该元素 ！\n");
}
//计算链表长度
