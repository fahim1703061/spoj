#include <bits/stdc++.h>

using namespace std;

long long int l = 100000000;
long long int count1= 0;
//int prime[(l/32)+1];
int prime[(100000000/32)+1];
void siv(long long int n);
bool check(int n,int pos);
int  setflag(int n,int pos);

int main()
{
    siv(l);
    for(int i = 2; i<=l; i++){
        if(check(prime[i>>5], i & 31) == 0){
            count1++;
            if(count1%100 == 1){
                cout<<i<<endl;
            }
        }
    }

}

void siv(long long int n)
{
    long long int sqrtn = sqrt(n);
    prime[0]=setflag(prime[0],1);
    for(int i = 4; i<=n;i+=2){
        prime[i>>5]= setflag(prime[i>>5],i & 31);
    }
    for(int i = 3; i<=sqrtn; i++){
        if(check(prime[i>>5], i & 31) == 0){
            for(int j = i*i; j<=n; j+=(i<<1)){
                prime[j>>5] = setflag(prime[j>>5], j&31);
            }
        }
    }
}
bool check(int n,int pos)
{
    return n & (1<<pos);
}

int setflag(int n, int pos)
{
    return n = n | (1<<pos);

}
