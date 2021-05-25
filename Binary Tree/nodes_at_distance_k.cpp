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

// case 1:
void printSubTreeNodes(Node* root,int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubTreeNodes(root->left,k-1);
    printSubTreeNodes(root->right,k-1);
}

//case 2:
int printNodesAtK(Node* root,Node* target,int k){
    if(root == NULL) return -1;
    if(root == target){
        printSubTreeNodes(root,k);
        return 0;
    }
    
    int dl = printNodesAtK(root->left,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }else{
            printSubTreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr = printNodesAtK(root->right,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }else{
            printSubTreeNodes(root->left,k-dl-2);
        }
        return 1+dr;
    }
    return -1;
}

int main(){

    //      1
    //    /   \
    //   2      3
    //  /        
    // 4          

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    printNodesAtK(root,root->left,1);
    cout<<endl;
    

    return 0;
}