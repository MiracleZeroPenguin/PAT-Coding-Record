#include<iostream>
#include<vector>
#include<regex>
using namespace std;
typedef struct student{
  string name;
  string code;
  int score;
}Student;
int main(){
  int n;
  cin>>n;
  Student minStu,maxStu;
  cin>>minStu.name>>minStu.code>>minStu.score;
  maxStu.name=minStu.name;
  maxStu.code=minStu.code;
  maxStu.score=minStu.score;
  for(int i=1;i<n;i++){
    string name,code;
    int score;
    cin>>name>>code>>score;
    if(score>maxStu.score){
      maxStu.name=name;
      maxStu.code=code;
      maxStu.score=score;
    }
    if(score<minStu.score){
      minStu.name=name;
      minStu.code=code;
      minStu.score=score;
    }
  }
  cout<<maxStu.name<<" "<<maxStu.code<<endl;
  cout<<minStu.name<<" "<<minStu.code;

  
}