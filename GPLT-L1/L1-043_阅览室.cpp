#include <bits/stdc++.h>
using namespace std;

struct Book{
    int num;
    char kind;
    int hour;
    int minute;
}book1[10010],book2[10010];
bool cmp(Book a,Book b){
    if(a.num != b.num){
        return a.num < b.num;
    }
    else if(a.hour != b.hour){
        return a.hour < b.hour;
    }
    return a.minute < b.minute;
}
int cal(int hour1,int minute1,int hour2,int minute2){
    if(minute2 >= minute1){
        return (hour2-hour1)*60 + minute2-minute1;
    }
    else{
        return (hour2-hour1-1)*60 + minute2 - minute1 + 60;
    }
}
int main(void){
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<sum;i++){
        int number = 0;
        int tempnum,temphour,tempminute;
        char tempkind;
        while(1){
            scanf("%d %c %d:%d",&tempnum,&tempkind,&temphour,&tempminute);
            if(tempnum == 0){
                break;
            }
            else{
                book1[number].num = tempnum;
                book1[number].kind = tempkind;
                book1[number].hour = temphour;
                book1[number].minute = tempminute;
                number++;
            }
        }
        sort(book1,book1+number,cmp);
        // printf("1\n");
        // for(int j=0;j<number;j++){
        //     printf("%d %c %d:%d\n",book1[j].num,book1[j].kind,book1[j].hour,book1[j].minute);
        // }

        int count = 0;
        for(int j=0;j<number-1;j++){
            if(book1[j].num == book1[j+1].num && book1[j].kind == 'S' && book1[j+1].kind == 'E'){
                book2[count++] = book1[j];
                book2[count++] = book1[j+1];
            }
        }
        if(count == 0){
            printf("0 0\n");
        }
        else{
            int sumcal = 0;
            int countcal = count / 2;
            for(int j=0;j<count;j+=2){
                sumcal += cal(book2[j].hour,book2[j].minute,book2[j+1].hour,book2[j+1].minute);
            }
            double temp = double(sumcal) / double(countcal);
            printf("%d %.0f\n",countcal,round(temp));
        }
        
    }
    return 0;
}