//1012 The Best Rank 
//StudentID  C  M  E  A
//在分数相同的情况下，排名也要相同
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct best{
  int rank,index;
};

struct student{  
  string ID;
  int score[4],rank[4];
  struct best bestRank;
};
int flag=-1;
bool cmp(student student1,student student2){
  if(student1.score[flag]>student2.score[flag]){
    return true;
  }
  return false;
}

string course[4]={"C","M","E","A"};

int main(){
  int N,M;
  cin>>N>>M;
  struct student students[2005];
  // vector<struct student>students=vector<struct student>(N);
  for(int i=0;i<N;i++){
    string ID;
    cin>>students[i].ID;
    cin>>students[i].score[0]>>students[i].score[1]>>students[i].score[2];
    students[i].score[3]=(students[i].score[0]+students[i].score[1]+students[i].score[2])/3;
  }

  for(flag=0;flag<4;flag++){
    sort(students,students+N,cmp);
    students[0].rank[flag]=1;
    for(int i=1;i<N;i++){
      if(students[i].score[flag]==students[i-1].score[flag]){
        students[i].rank[flag]=students[i-1].rank[flag];
      }else{
        students[i].rank[flag]=i+1;
      }
    }
  }

  unordered_map<string,int>stuMap=unordered_map<string,int>();//ID->index in students
  for(int i=0;i<N;i++){
    stuMap[students[i].ID]=i;
    //3>0>1>2
    students[i].bestRank.index=3;
    students[i].bestRank.rank=students[i].rank[3];
    for(int j=0;j<3;j++){
      if(students[i].rank[j]<students[i].bestRank.rank){
        students[i].bestRank.index=j;
        students[i].bestRank.rank=students[i].rank[j];
      }
    }
  }
  
  for(int i=0;i<M;i++){
    string ID;
    cin>>ID;
    if(stuMap.find(ID)==stuMap.end()){
      cout<<"N/A";
    }else{
      cout<<students[stuMap[ID]].bestRank.rank<<" "<<course[students[stuMap[ID]].bestRank.index];
    }
    if(i!=M-1){
      cout<<endl;
    }
  }

}