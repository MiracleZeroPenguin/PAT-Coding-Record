/*
 * @Author: Miracle
 * @LastEditTime: 2021-09-09
 * @Description: 树的后序遍历（postorder: left right root）
 */
#include <bits/stdc++.h>

using namespace std;
struct node{
  struct node *left;
  struct node *right;
  int val;
};

node* newNode(int val){
  node* n=(node*)malloc(sizeof(node));
  n->val=val;
  n->left=NULL;
  n->right=NULL;
  return n;
}

void getPostOrder(node* root,vector<int>& Trans){
  if(root->left!=NULL){
    getPostOrder(root->left,Trans);
  }
  if(root->right!=NULL){
    getPostOrder(root->right,Trans);
  }
  Trans.push_back(root->val);
}

int main(){
  node* root;
  vector<int>trans=vector<int>();
  getPostOrder(root,trans);
  for(int i=0;i<trans.size();i++){
    cout<<trans[i]<<" ";
  }
}