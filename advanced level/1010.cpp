//1010 Radix 
//input： N1 N2 tag radix
//tag=1: radix for N1
//tag=2: radix for N2
//不用二分法过不了呜呜呜
//这是什么猥琐的测试

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long toTen(string s, long long radix){
  long long ans=0;
  for(int i=s.length()-1;i>=0;i--){
    long long t=isalpha(s[i])?s[i]-'a'+10:s[i]-'0';
    ans+=t*pow(radix,s.length()-1-i);
  }
  if(ans<0)return -1;
  return ans;
}

int main(){
  string N1,N2,tN;
  long long tag,radix,val;
  cin>>N1>>N2>>tag>>radix;
  if(tag==1){
    tN=N2;
    val=toTen(N1,radix);
  }else{
    tN=N1;
    val=toTen(N2,radix);
  }

  char maxElement=tN[0];
  for(int i=0;i<tN.size();i++){
    if(tN[i]>maxElement){
      maxElement=tN[i];
    }
  }
  long long low,high;
  low=isalpha(maxElement)?maxElement-'a'+10:maxElement-'0'+1;
  high=max(low,val);
  while(low<=high){
    long long mid=(low+high)/2;
    long long tmpVal=toTen(tN,mid);
    if(tmpVal==val){
      cout<<mid;
      return 0;
    }
    if(tmpVal<0||tmpVal>val){
      high=mid-1;
    }else{
      low=mid+1;
    }
  }
  cout<<"Impossible";
}