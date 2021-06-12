#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* create(int Array[],int size){
    node *p,*pre,*head;
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i=0;i<size;i++){
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}
void Print(node* head){
    node* p = head->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
int findnode(node* head,int num){
    int index = 0;
    node* p = head->next;
    while(p != NULL){
        index++;
        if(p->data == num){
            return index;
        }
        p = p->next;
    }
    return -1;
}
void insert(node* head,int pos,int x){
    node* p = head;
    for(int i=0;i<pos-1;i++){
        p = p->next;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}
void del(node* head,int pos){
    node* p = head->next;
    node* pre = head;
    for(int i=0;i<pos-1;i++){
        p = p->next;
        pre = pre->next;
    }
    pre->next = p->next;
    delete(p);
}
int main(void){
    freopen("../test.in","r",stdin);
    int a[1000];
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    node* head;
    head = create(a,N);
    Print(head);
    printf("\n");
    int index = findnode(head,10);
    printf("%d\n",index);
    insert(head,4,10);
    Print(head);
    printf("\n");
    del(head,4);
    Print(head);
    printf("\n");
    return 0;
}