#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
    };
void creat_list(struct s_list **headp,int *p);
int main()
{
    struct s_list *head=NULL,*p;
    int s[]={1,2,3,4,5,6,7,8,0};
    creat_list(&head,s);
    p=head;
    while(p){
        printf("%d\t",p->data);
        p=p->next;  }
    printf("\n");
    return 0;
}
void creat_list(struct s_list **headp,int *p)
{
    struct s_list*loc_head=NULL,*tail;
    struct s_list*temp;
    if(p[0]==0);
    else {
        loc_head=(struct s_list*)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        tail=loc_head;
        while(*p){
            temp=(struct s_list*)malloc(sizeof(struct s_list));
            temp->next=loc_head;
            loc_head=temp;
            loc_head->data = *p++; }
    tail->next=NULL; }
    *headp=loc_head;
}
