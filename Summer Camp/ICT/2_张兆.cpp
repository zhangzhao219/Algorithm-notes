#include <bits/stdc++.h>
using namespace std;
int N,K;
struct node{
    int data;
    node* next;
};
int num[100];
int main(void){
    scanf("%d %d",&N,&K);
    int t;
    int index = 0; // 存储实际的数字
    for(int i=0;i<N;i++){
        // 在读取的时候直接将等于K的数删除
        scanf("%d",&t);
        if(t != K){
            num[index] = t;
            index++;
        }
    }
    // 倒序建立链表
    node* head;
    head->next = NULL;
    for(int i=0;i<index;i++){
        node* p = new node;
        p->data = num[i];
        p->next = head->next;
        head->next = p;
    }
    // 正序输出
    // 链表为空则输出空行
    if(head->next == NULL){
        printf("\n");
    }
    // 链表不为空则正常输出整个链表
    else{
        while(head->next != NULL){
            head = head->next;
            printf("%d ",head->data);
            // 输出整个链表
        }
    }
    return 0;
}

/*
5 6
2 6 7 6 9
*/
