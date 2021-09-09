//1015 Reversible Primes
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num){
  if(num==1)return false;
  for(int i=2;i<=sqrt(num);i++){
    if(num%i==0)
      return false;
  }
  return true;
}

int reverse(int num,int radix){ 
  int ans=0;
  while(num!=0){
    ans=ans*radix+num%radix;
    num=num/radix;
  }
  return ans;
}

int main(){
  int N,D;
  cin>>N;
  while(N>=0){
    cin>>D;
    if(!isPrime(N))cout<<"No"<<endl;
    else{
      if(isPrime(reverse(N,D))){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }
    cin>>N;
  }
}