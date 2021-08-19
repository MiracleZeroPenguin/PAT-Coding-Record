#include<iostream>
#include<map>
#include<vector>
#include<deque>
using namespace std;

vector<vector<string> >trans(0);
map<string,vector<string> >tree;//index:节点名称，value:儿子序列

void visit(string root,int level){
  if(trans.size()<=level){
    vector<string>tmp(1,root);
    trans.push_back(tmp);
  }else{
    trans[level].push_back(root);
  }
  for(int i=0;i<tree[root].size();i++){
    visit(tree[root][i],level+1);
  }
}

int main(){
  int N,M;
  cin>>N>>M;//N:结点个数，M:非叶节点个数
  for(int i=0;i<M;i++){
    string node_name;
    int son_num;
    cin>>node_name;
    cin>>son_num;
    for(int j=0;j<son_num;j++){
      string son_name;
      cin>>son_name;
      tree[node_name].push_back(son_name);
    }
  }
  string root="01";
  visit(root,0);
  for(int i=0;i<trans.size();i++){
    int num=0;
    for(int j=0;j<trans[i].size();j++){
      if(tree[trans[i][j]].size()==0){
        num++;
      }
    }
    if(i==0){
      cout<<num;
    }else{
      cout<<" "<<num;
    }
  }
}