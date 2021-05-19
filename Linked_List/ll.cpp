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
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);    
    if(head==NULL){
        head = n;        
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }    
    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key) return true;
        temp=temp->next;
    }
    return false;
}

void deleteAthead(node* &head){
    node* todelete = head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAthead(head);
        return;
    }

    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

// Iterative method
node* reverese(node* &head){
    node* prev=NULL;
    node* current=head;
    node* nextPtr;
    while(current!=NULL){
        nextPtr=current->next;
        current->next=prev;

        prev=current;
        current=nextPtr;        
    }
    return prev;
}

// Recursive Method
node* revereseRecursive(node* &head){

    if(head==NULL || head->next==NULL) return head;
    node* newHead = revereseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

node* reversek(node* &head,int k) {
    node* prev=NULL;
    node*curr = head;
    node* nextPtr;
    
    int count=0;
    while(curr!=NULL&& count<k) {
        nextPtr = curr->next;
        curr->next=prev;

        prev=curr;
        curr = nextPtr;
        count++;
    }

    if(nextPtr!=NULL) head->next = reversek(nextPtr,k);
    return prev;

}

// Floyed's algorithm
bool detectCysle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);
    fast = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;                    
    }
    slow->next =NULL;
}

int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
   
    display(head);

    // node* newHead = revereseRecursive(head);
    // node* newHead = reverese(head);
    int k=2;
    node* newHead = reversek(head,3);

    display(newHead);

    return 0;
}