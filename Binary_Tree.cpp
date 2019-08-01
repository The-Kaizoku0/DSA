#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node  
{ 
  int data; 
  node *left; 
  node *right; 
};

node* newNode(int data) 
{ 
  // Allocate memory for new node  
  node* temp = new node(); 
  
  // Assign data to this node 
  temp->data = data; 
  
  // Initialize left and right children as NULL 
  temp->left = NULL; 
  temp->right = NULL; 
  return temp; 
} 

void levelOrder(Node* node)
{
   queue<Node*> q;
   if(node==NULL)
   {
       return ;
   }
   q.push(node);
   while(!q.empty())
   {
       Node* t=q.front();
       cout << t->data << " ";
       if(t->left)
       {
           q.push(t->left);
       }
       if(t->right)
       {
           q.push(t->right);
       }
       q.pop();
   }
}
void printPostorder( Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder( Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder( Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  
int getSize(Node* node)
{
   if(node==NULL)
   {
       return 0;
   }
   return 1+getSize(node->left)+getSize(node->right); 
}
int findMax(struct node* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(findMax(root->left), findMax(root->right)));
    
// Your code goes here
}
// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(findMin(root->left), findMin(root->right)));
}
int height(Node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    return 1+ max(height(node->left),height(node->right));
}
int diameter(Node* node)
{
   if(node==NULL)
   {
       return 0;
   }
   return max(diameter(node->left), max(diameter(node->right),(1+height(node->left)+height(node->right))));
}
int main() 
{ 
  /*create root*/
  node *root = newNode(1);   
  /* following is the tree after above statement  
  
        1 
      /   \ 
     NULL  NULL   
  */
    
  
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  /* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root->left->left  = newNode(4); 
  /* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/ 
  return 0; 
}
