#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[],int start,int end,int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node* bulidTree(int preorder[],int inorder[],int start,int end){
    static int idx = 4;

    if(start > end) return NULL;

    int curr = preorder[idx];
    idx--;
    Node* node = new Node(curr);

    if(start == end) return node;

    int pos = search(inorder,start,end,curr);
    node->right = bulidTree(preorder,inorder,pos+1,end);
    node->left = bulidTree(preorder,inorder,start,pos-1);
    return node;

}

void inorderPrint(Node* root){
    if(root==NULL){return;}
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){

    //      1
    //    /   \
    //   2      3
    //  / \    / \
    // 4   5  6   7

    int preorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    // build tree
    Node* node = bulidTree(preorder, inorder,0,4);
    inorderPrint(node);

    return 0;
}
