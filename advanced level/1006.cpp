//1006 Sign In and Sign Out
//之前一直在纠结cpp没有split函数的问题，现在觉得自己是个蠢蛋
//scanf不就可以自带格式化输入吗
#include<iostream>
#include<climits>
using namespace std;

int main(){
  int num;
  cin>>num;
  string ID1,ID2;
  int in_time=INT_MAX,out_time=INT_MIN;
  for(int i=0;i<num;i++){
    int time;
    string input_ID;
    int HH,MM,SS;
    cin>>input_ID;
    scanf("%d:%d:%d",&HH,&MM,&SS);
    time=HH*3600+MM*60+SS;
    if(time<in_time){
      in_time=time;
      ID1=input_ID;
    }
    scanf("%d:%d:%d",&HH,&MM,&SS);
    time=HH*3600+MM*60+SS;
    if(time>out_time){
      out_time=time;
      ID2=input_ID;
    }
  }
  cout<<ID1<<" "<<ID2;
}