#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n = new node(val);  

    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }

    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }    
    temp->next = n;  
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);    
    if(head==NULL){
        insertAtHead(head,val);        
        return;
    }

    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }    
    temp->next = n;
    n->next = head;
}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);        
    cout<<endl;
}

void deleteAthead(node* &head){
    node* todelete = head;
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }    
    temp->next = head->next;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int pos){

    if(pos==1){
        deleteAthead(head);
        return;
    }
    if(head->next==NULL){
        deleteAthead(head);
        return;
    }

    node* temp=head;
    int count=1;

    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main(){

    node* head1=NULL;
    
    int arr1[]={1,2,3,4};
    
    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }
   
    display(head1);
    insertAtHead(head1,5);
    display(head1);

    deletion(head1,1);
    display(head1);

    
    return 0;
}