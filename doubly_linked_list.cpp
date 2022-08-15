#include<bits/stdc++.h>
using namespace std;

class DoublyNode{
public:
    int val;
    DoublyNode* Prev;
    DoublyNode* Next;

    DoublyNode(int val){
        this->val=val;
        Prev= NULL;
        Next = NULL;
    }
};

void display(DoublyNode* n){
    while(n != NULL){
        cout<<n->val;
        if(n->Next != NULL) cout<<" --> ";
        n = n->Next;
    }
    cout<<endl<<endl;
}

void reverseDisplay(DoublyNode* head){
    DoublyNode* temp = head;
     while(temp->Next != NULL){
        temp = temp->Next;
    }
    while(temp != NULL){
        cout<<temp->val;
        if(temp->Prev != NULL) cout<<" --> ";
        temp = temp->Prev;
    }
    cout<<endl<<endl;
}

int countLength(DoublyNode* &head){
    int count=0;
    DoublyNode* temp = head;
    while(temp != NULL){
        temp=temp->Next;
        count++;
    }
    return count;
}

void insertAtTail(DoublyNode* &head, int val){
    DoublyNode *newNode = new DoublyNode(val);

    if(head == NULL){
        head=newNode;
        return;
    }
    DoublyNode *temp = head;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=newNode;
    newNode->Prev = temp;
}

void insertAtHead(DoublyNode* &head, int val){
    //s1: new node creation
    DoublyNode* newNode = new DoublyNode(val);
    //s2: update of head->prev
    head->Prev= newNode;
    //s3: update of newNode->next
    newNode->Next = head;
    //s4: update of head
    head = newNode;
}

int main(){
    DoublyNode* head = NULL;
    
    int value, position;
    cout<<"Choice 1: Insertion at Head"<< endl 
    <<"Choice 2: Insertion at Tail" << endl 
    <<"Choice 3: Reverse Display" << endl 
    << "Choice 0: Exit"<<endl;
    int choice = 2;
    while(choice != 0){
        switch (choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head, value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head, value);
            break;
        case 3:
            reverseDisplay(head);
        default:
            break;
        }
        
        cout<<"Next Choice: ";
        cin>>choice;
    }
    cout<<"Doubly linked list: ";  
    display(head);
    cout<<endl<<"length of the list: "<<countLength(head)<<endl;

    return 0;
}