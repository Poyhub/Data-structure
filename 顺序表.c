#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE	10

typedef struct SqlList {
	int* head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
	int* elem;//储存空间得基地址
	int length;//当前长度
	int size;//记录顺序表分配的存储容量
}SqlList;

/*初始化顺序表*/
SqlList InitList() {
	SqlList s;
	s.head = (int*)malloc(MAXSIZE * sizeof(int));//构造一个空的顺序表，动态申请存储空间

	//判断申请是否成功
	if (!s.head) {
		printf("内存空间申请失败！\n");
		exit(0);
	}
	s.length = 0;//空表的长度初始化为0
	s.size = MAXSIZE;//空表的初始存储空间为10
	return s;
}

/*顺序表插入元素*/
SqlList addList(SqlList *s,int elem,int add){
	//判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
    if (add>s->length+1||add<0) {
        printf("插入位置有问题\n");
		exit(0);
    }
    //做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
    if (s->length==s->size) {
        s->head=(int *)realloc(s->head, (s->size+1)*sizeof(int));
        if (!s->head) {
            printf("存储分配失败\n");
			exit(0);
        }
        s->size+=1;
    } 
    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    for (int i=s->length-1; i>=add-1; i--) {
        s->head[i+1]=s->head[i];
    }
    //后移完成后，直接将所需插入元素，添加到顺序表的相应位置
    s->head[add-1]=elem;
    //由于添加了元素，所以长度+1
    s->length++;
}
/*删除顺序表得指定元素*/
SqlList DelList(SqlList *s,int elem){
	//判断删除本身是否存在问题（如果删除元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者删除的位置本身不存在，程序作为提示并自动退出）
    if (elem>s->length+1||elem<1) {
        printf("删除得位置有问题\n");
		exit(0);
    }
	for (int i = elem; i <= s->length; i++)
	{
		s->head[i-1]=s->head[i];	
	}
	s->length--;
	

}
//查找函数，其中，num表示要查找的数据元素的值【查值的位置】。
SqlList SearchList(SqlList *s,int num){
	int status=0;
	int elems=0;
	for (int i = 0; i < s->length; i++)
	{
		if (s->head[i]==num)
		{	
			status=1;
			elems=i;
		}

	}
	if (status==1)
	{
			printf("查找结果：\n");
			printf("已查找到该元素！该元素值为：s.head[%d]=%d\n",elems,s->head[elems]);
			printf("\n");
	}
	else
	{
			printf("查找结果：\n");
			printf("未查找到该元素！\n");
	}
	
	
}
/*修改当前顺序表*/
SqlList AmendList(SqlList *s,int elem,int num){
	if (elem>s->length+1||elem<0)
	{
		printf("修改得位置有问题\n");
		exit(0);
	}
	for (int i = 0; i < s->length; i++)
	{
		if (i==elem-1)
		{
			s->head[i]=num;
			printf("修改成功！当前最新值为：s.head[%d]=%d\n",i,s->head[i]);

		}
		
	}
	
	
}
/*销毁顺序表*/
SqlList DestoryList(SqlList *s){
	if (s->elem)
	{
		free(s->head);
	}

	
}
/*打印当前顺序表*/
int display(SqlList *s) {
	printf("顺序表中存储的元素分别是：\n");
	for (int i = 0; i < s->length; i++) {
		printf("s.head[%d]=%d \n", i, s->head[i]);
	}
	printf("\n");
}
//主函数
int main() {
	//初始化顺序表
	SqlList s = InitList();
	//向顺序表中添加元素
    for (int i=0; i<10; i++) {
        s.head[i]=i;
        s.length++;
    }
	printf("%d\n",s.length);
	display(&s);//打印顺序表
	addList(&s,15,6);//向第6个元素添加17
	printf("%d\n",s.length);
	display(&s);//打印顺序表
	DelList(&s,3);//删除第3个元素
	printf("%d\n",s.length);
	display(&s);//打印顺序表
	SearchList(&s,15);
	AmendList(&s,4,11);
	display(&s);//打印顺序表
	DestoryList(&s);

	return 0;

}