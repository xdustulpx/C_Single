#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    double item;// 存储数据的成员
    struct node *next;// 指向下一个结点的指针
}liste;
// 创建一个长度为len的链表，并返回头结点指针
liste* creatnode(int len){
    // 创建头结点，并让temp指向它
    liste* head=malloc(sizeof(struct node));
    liste* temp=head;
    // 输入第一个结点的数据，指针next初始化为NULL
    scanf("%lf",&temp->item);
    temp->next=NULL;
    // 循环创建len-1个结点，并将其链接到链表尾部
    int i;
    for(i=1;i<len;i++){
        // 创建新的结点p，并输入数据
        liste* p=malloc(sizeof(struct node));
        scanf("%lf",&p->item);
        // 将p链接到链表尾部
        temp->next=p;
        temp=p;
    }
    // 链表尾部结点指针next赋值为NULL
    temp->next=NULL;
    return head;
}
// 遍历链表并打印结点的数据
void printNode(liste* p){
    while(p!=NULL){
        // 如果p不是链表尾结点，则打印结点数据和箭头符号
        if(p->next!=NULL){
            printf("%lf->",p->item);
            p=p->next;
        }
        // 如果p是链表尾结点，则只打印结点数据
        else{
            printf("%lf\n",p->item);
            p=p->next;
        }
    }
}
int main(){
    int len = 0;
    printf("请输入数字的个数：\n");
    scanf("%d", &len);
    printf("请输入数字：\n");
    liste* p = creatnode(len); // 创建长度为len的链表p
    printNode(p); // 打印链表结点的数据
    liste* head = malloc(sizeof(struct node)); // 创建新结点head
    printf("请输入要插入的头结点数据：\n");
    scanf("%lf", &head->item); // 输入head结点的数据
    head->next = p; // 将head结点插入到链表p的开头
    p = head; // 更新链表头指针
    printNode(p); // 打印更新后的链表结点的数据
    return EXIT_SUCCESS;
}
