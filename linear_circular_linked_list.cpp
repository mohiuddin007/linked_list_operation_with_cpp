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

void makeCycle (Node* &head, int pos){
    Node* temp = head;
    Node* startNode;
    int count = 1;

    while(temp->Next != NULL){
        if(count == pos) startNode == temp;
        temp = temp->Next;
        count++;
    }

    temp->Next = startNode;
}

int main(){

    Node* head = NULL;
    
    int value, position;
    insertAtTail(head, 14);
    insertAtTail(head, 25);
    insertAtTail(head, 33);
    insertAtTail(head, 47);
    display(head);
   
    cout<<"Enter the position to make cycle: "<<endl;
    cin>>position;
    makeCycle(head, position);
    
    display(head);

    return 0;
}
