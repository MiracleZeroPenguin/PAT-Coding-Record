#include<iostream>
using namespace std;
int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    long long a,b,c;
    cin>>a>>b>>c;
    if(a+b>c){
      cout<<"Case #"<<i+1<<": true"<<endl;
    }else{
      cout<<"Case #"<<i+1<<": false"<<endl;
    }
  }
}