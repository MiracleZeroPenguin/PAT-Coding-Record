#include<iostream>
using namespace std;
bool checkRight(string s){
  // right=left*mid
  int index=0;
  int left=0,mid=0,right=0;
  while(index<s.length()&&s[index]=='A'){
    left++;
    index++;
  }
  if(index<s.length()&&s[index]!='P'){
    return false;
  }
  index++;
  while(index<s.length()&&s[index]=='A'){
    mid++;
    index++;
  }
  if(index<s.length()&&s[index]!='T'){
    return false;
  }
  index++;
  while(index<s.length()&&s[index]=='A'){
    right++;
    index++;
  }
  if(index!=s.length()){
    return false;
  }
  if(right!=left*mid||mid==0){
    return false;
  }
  return true;

}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    cout<<(checkRight(s)?"YES":"NO");
    if(i!=n-1){
      cout<<"\n";
    }
  }
}