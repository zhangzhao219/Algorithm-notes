#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int origin[N];
int tempOri[N];
int changed[N];
int n;
bool issame(int A[],int B[]){
    for(int i=1;i<=n;i++){
        if(A[i] != B[i]){
            return false;
        }
    }
    return true;
}
bool insertsort(){
    bool flag = false;
    for(int i=2;i<=n;i++){
        if(i != 2 && issame(tempOri,changed)){
            flag = true;
        }
        sort(tempOri,tempOri + i + 1);
        if(flag == true){
            return true;
        }
    }
    return false;
}
void downAdjust(int low,int high){
    int i = low;
    int j = 2 * i;
    while(j <= high){
        if(j+1 <= high && tempOri[j+1] > tempOri[j]){
            j = j + 1;
        }
        if(tempOri[j] > tempOri[i]){
            swap(tempOri[j],tempOri[i]);
            i = j;
            j = i * 2;
        }
        else{
            break;
        }
    }
}
void showArray(int a[]){
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
        if(i == n){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return;
}
void heapSort(){
    bool flag = false;
    for(int i=n/2;i>=1;i--){
        downAdjust(i,n);
    }
    for(int i=n;i > 1;i--){
        if(i != n && issame(tempOri,changed)){
            flag = true;
        }
        swap(tempOri[1],tempOri[i]);
        downAdjust(1,i-1);
        if(flag == true){
            showArray(tempOri);
            return;
        }
    }
}
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&origin[i]);
        tempOri[i] = origin[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&changed[i]);
    }
    if(insertsort()){
        printf("Insertion Sort\n");
        showArray(tempOri);
    }
    else{
        printf("Heap Sort\n");
        for(int i=1;i<=N;i++){
            tempOri[i] = origin[i];
        }
        heapSort();
    }
    return 0;
}