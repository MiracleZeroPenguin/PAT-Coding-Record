#include <iostream>
using namespace std;
string zhongwen[10]={
  "ling","yi","er","san","si","wu","liu",
  "qi","ba","jiu"
};
int main(){
  string s;
  int tot=0;
  cin>>s;
  for(int i=0;i<s.length();i++){
    tot+=s[i]-'0';
  }
  s="";
  while(tot!=0){
    if(s==""){
      s=zhongwen[tot%10];
    }else{
      s=zhongwen[tot%10]+" "+s;
    }
    tot=tot/10;
  }
  cout<<s;
}