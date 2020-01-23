#include <stdio.h>
#include <stdlib.h>
typedef struct node *link;
struct node{
    link next;
    int val;
};
typedef struct node2 *link2;
struct node2{
    link2 next;
    int val;
    int num;
};
link newnode(int val, link next){
    link x=malloc(sizeof(*x));
    if(x==NULL){
        return NULL;
    }
    x->val=val;
    x->next=next;
    return x;
}
link listinshead(link h,int val){
    h=newnode(val,h);
    return h;
}
link2 newnode2(int val, int num,link2 next){
    link2 x=malloc(sizeof(*x));
    if(x==NULL){
        return NULL;
    }
    x->val=val;
    x->next=next;
    x->num=num;
    return x;
}
link2 listinshead2(link2 h,int num,int val){
    link2 he;
    if (h==NULL){
        he=newnode2(val,num,NULL);
    }
    else {
        he = newnode2(val, num, he);
    }
    return he;
}
link2 comprimi(link head){
    link2 x2;
    link2 head2=NULL;
    link x1;
    int count=0;
    for(x1=head;x1!=NULL;x1=x1->next){
        if(x1->next!=NULL) {
            if (x1->val == x1->next->val) {
                count++;
            } else {
                head2 = listinshead2(head2, count + 1, x1->val);
                count = 0;
            }
        } else{
            head2 = listinshead2(head2, count, x1->val);
        }
    }
    return head2;
}
link2 listReverse(link2 x){
    link2 t, y=x, r=NULL;
    while (y!=NULL){
        t=y->next;
        y->next=r;
        r=y;
        y=t;
    }
    return r;
}
int main() {
    link head=NULL;
    link x;
    link2 head2=NULL;
    link2 x2;
    head=listinshead(head,5);
    head=listinshead(head,5);
    head=listinshead(head,5);
    head=listinshead(head,3);
    head=listinshead(head,2);
    head=listinshead(head,2);
    head=listinshead(head,3);
    head=listinshead(head,3);
    head=listinshead(head,3);
    head=listinshead(head,3);
   head2=comprimi(head);
   head2=listReverse(head2);
   for(x2=head2;x2!=NULL;x2=x2->next){
       printf("(%d,%d) ",x2->val, x2->num);
   }
    return 0;

}
