#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int input,ans;
    cin>>input;
    ans=0;
    while(input!=1){
        if(input%2==0){
            input=input/2;
        }else{
            input=(3*input+1)/2;
        }
        ans++;
    }
    cout<<ans;
}
