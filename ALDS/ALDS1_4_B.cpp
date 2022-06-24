#include<stdio.h>
int num[1000010];
int main(void){
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    scanf("%d",&q);
    int sum = 0;
    for(int i=0;i<q;i++){
        int temp;
        scanf("%d",&temp);
        int left = 0;
        int right = n;
        int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(num[mid] == temp){
                sum++;
                break;
            }
            else if(num[mid] < temp){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}