#include <bits/stdc++.h>
using namespace std;
int N,M;
double G[1010][1010];
bool sex[1010];
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&N,&M);
    memset(sex,false,sizeof(sex));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            G[i][j] = 0.0;
        }
    }
    for(int i=0;i<M;i++){
        int tempsum;
        scanf("%d",&tempsum);
        vector<int> temp;
        for(int j=0;j<tempsum;j++){
            string tempstring;
            cin >> tempstring;
            int sign = 0;
            if(tempstring[0] == '-'){
                sign = 1;
                tempstring.erase(0,1);
            }
            int t = stoi(tempstring);
            if(sign == 1){
                sex[t] = true;
            }
            temp.push_back(t);
        }
        for(int j=0;j<temp.size();j++){
            for(int k=0;k<temp.size();k++){
                if((j != k) && (sex[temp[j]] != sex[temp[k]])){
                    G[temp[j]][temp[k]] += 1.0 / temp.size();
                }
            }
        }
    }
    int A,B;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%.2f ",G[i][j]);
        }
        printf("\n");
    }
    string As;
    string Bs;
    cin >> As >> Bs;
    if(As[0] == '-'){
        As.erase(0,1);
    }
    else if(Bs[0] == '-'){
        Bs.erase(0,1);
    }
    int ai = stoi(As);
    int bi = stoi(Bs);
    vector<int> Asv;
    vector<int> Bsv;
    double Amax = 0.0;
    double Bmax = 0.0;
    for(int i=0;i<N;i++){
        if(sex[i] != sex[ai] && G[i][ai] > Amax){
            Amax = G[i][ai];
            Asv.clear();
            Asv.push_back(i);
        }
        else if(sex[i] != sex[ai] && G[i][ai] == Amax){
            Asv.push_back(i);
        }
        if(sex[i] != sex[bi] && G[i][bi] > Bmax){
            Bmax = G[i][bi];
            Bsv.clear();
            Bsv.push_back(i);
        }
        else if(sex[i] != sex[bi] && G[i][bi] == Bmax){
            Bsv.push_back(i);
        }
    }
    sort(Asv.begin(),Asv.end());
    sort(Bsv.begin(),Bsv.end());
    int sign = 0;
    for(int i=0;i<Asv.size();i++){
        if(Asv[i] == bi){
            sign++;
            break;
        }
    }
    for(int i=0;i<Bsv.size();i++){
        if(Bsv[i] == ai){
            sign++;
            break;
        }
    }
    if(sign == 2){
        if(sex[ai] == false){
            printf("%d -%d\n",ai,bi);
        }
        else{
            printf("-%d %d\n",ai,bi);
        }
    }
    else{
        if(sex[ai] == false){
            for(int i=0;i<Asv.size();i++){
                printf("%d -%d\n",ai,Asv[i]);
            }
            for(int i=0;i<Bsv.size();i++){
                printf("-%d %d\n",bi,Bsv[i]);
            }
        }
        else{
            for(int i=0;i<Asv.size();i++){
                printf("-%d %d\n",ai,Asv[i]);
            }
            for(int i=0;i<Bsv.size();i++){
                printf("%d -%d\n",bi,Bsv[i]);
            }
        }
    }
    return 0;
}