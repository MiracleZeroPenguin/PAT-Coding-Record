/*
 * @Author: Miracle
 * @Date: 2021-09-09
 * @Description: 后序中序建树
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

/**
 * @description: 在中序遍历中找到val所在位置
 * @param {int} inStart
 * @param {int} inEnd
 * @param {int} val
 * @return {int}
 */
int search(vector<int>in,int inStart,int inEnd,int val){
  for(int i=inStart;i<=inEnd;i++){
    if(in[i]==val){
      return i;
    }
  }
  return -1;
}

/**
 * @description: 后序中序建树的递归
 * @param {int} inStart 前序开始的地方
 * @param {int} inEnd 前序结束的地方
 * @return {node*} 根节点
 */
node* recursive_in_post(vector<int> in,vector<int> post,int inStart,int inEnd,int* pIndex){
  if(inStart>inEnd){
    return NULL;
  }
  node* root=newNode(post[*pIndex]);
  (*pIndex)--;
  if(inStart==inEnd){
    return root;
  }
  int inIndex=search(in,inStart,inEnd,root->val);
  root->right=recursive_in_post(in,post,inIndex+1,inEnd,pIndex);
  root->left=recursive_in_post(in,post,inStart,inIndex-1,pIndex);
  return root;
}

/**
 * @description: 后序中序建树入口
 * @param {vector<int>} in 中序遍历
 * @param {vector<int>} post 后序遍历
 * @return {node*} 树的根节点
 */
node* buildTree_in_post(vector<int> in,vector<int> post){
  int pIndex=in.size()-1;
  return recursive_in_post(in,post,0,in.size()-1,&pIndex);
}

int main(){
  vector<int>inorder={4,8,2,5,1,6,3,7};
  vector<int>postorder={8,4,5,2,6,7,3,1};
  node* root=buildTree_in_post(inorder,postorder);
}

// preorder: root, left, right
// inorder: left root right
// postorder: left right root
