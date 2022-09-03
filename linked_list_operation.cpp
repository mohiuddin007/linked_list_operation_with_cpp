#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int value;
    Node *Next;

    Node(int val){
        value = val;
        Next=NULL;
    }
};

struct Test{
    int position[1000];
};

void display(Node* n){
    while(n != NULL){
        cout<<n->value;
        if(n->Next != NULL) cout<<" -> ";
        n = n->Next;
    }
    cout<<endl<<endl;
}


void insertAtTail(Node* &head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head=newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=newNode;
}

void deletionAtHead(Node* &head){
    Node* temp = head;
    if(temp != NULL){
        head = temp->Next;
        delete temp;
        cout<<"Successfully Deleted!"<<endl;
    } else {
        cout<<"There is no value in the linked list"<<endl;
    }
}

void insertionAtSpecificPosition(Node* &head, int pos, int val){
    int i = 0;
    Node* temp = head;
    while (i<pos-2)
    {
        temp=temp->Next;
        i++;
    }
    Node* newNode = new Node(val);
    newNode->Next=temp->Next;
    temp->Next=newNode;
    
}

int main(){
    Node* head = NULL;
    int value, position;

    insertAtTail(head, 14);
    insertAtTail(head, 25);
    insertAtTail(head, 33);
    insertAtTail(head, 47);
    display(head);

    insertionAtSpecificPosition(head, 4, 40);
    display(head);
    
    deletionAtHead(head);
    display(head);
    
    return 0;
}

