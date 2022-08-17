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

void printReverse(Node* head)
{
    if (head == NULL)
    return;
 
    printReverse(head->Next);
 
    cout << head->value << " ";
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

void insertAtHead(Node* &head, int val){
    //s1: new node creation
    Node* newNode = new Node(val);
    //s2: update of newNode->next
    newNode->Next = head;
    //s3: update of head
    head = newNode;
}

int countLength(Node* &head){
    int count=0;
    Node* temp = head;
    while(temp != NULL){
        temp=temp->Next;
        count++;
    }
    return count;
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

int searchByValueUnique(Node* &head, int key){
    Node* temp = head;
    int count = 1;
     if(temp == NULL){
        return -1;
    }
    while(temp->value != key){
        if(temp->Next == NULL){
            return -1;
        }
        temp=temp->Next;
        count++;
    }

    return count;
}

void searchByValueDuplicate(Node* &head, int key){
    Node* temp = head;
    int size;
    size=countLength(head);
    int position[size+1], k=1;
    int count= 1;
    int flag=0;
    
    while(temp != NULL){
        if(temp->value == key){
            // cout<<count<<" ";
            position[k] = count;
            k++;
            flag=1;
        }
        temp=temp->Next;
        count++;
    }
    cout<<endl;
    if(flag = 0) cout<<"The searched value is not yet in this list"<<endl;
    else{
        position[0]=k;
        cout<<" the value is found at position: ";
        for(int i=1; i<position[0]; i++){
            cout<<position[i];
            if(i<position[0]-1)cout<<",";
        }
    }
}

Test searchByValueDuplicateReturn(Node* &head, int key){
 Node* temp = head;
    Test T;
    int k=1;
    int count= 1;
    
    while(temp != NULL){
        if(temp->value == key){
            // cout<<count<<" ";
            T.position[k] = count;
            k++;
        }
        temp=temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void searchByValueUnique(Node* &head, int searchValue, int value){
    ///step 1: search the positon of the search value
    int position;
    position = searchByValueUnique(head, searchValue);
    //step 2: insert the value at the position + 1;
    insertionAtSpecificPosition(head, position+1, value);
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

void deletionAtTail(Node* &head){
     Node* temp = head;
    if(temp != NULL && temp->Next != NULL){
        while (temp->Next->Next != NULL){
           temp = temp->Next;
        }
        Node* delNode = temp->Next;
        temp->Next=NULL;
        delete delNode;
        cout<<"successfully delete from tail"<<endl;
    } else {
        //head i null
        if(temp == NULL) cout<<"There is no value in the linked list"<<endl;
        //head is tail
        else deletionAtHead(head); 
    }
}

void deletionAtSpecificPosition(Node* &head, int position){
    Node* temp = head;
    if(temp != NULL && position <= countLength(head)){
        if(position == 1){
            deletionAtHead(head);
        } else if(position == countLength(head)){
            deletionAtTail(head);
        } else{
            int i = 1;
            while (i<position-1){
                temp = temp->Next;
                i++;
            }
            Node* delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
      
    } else {
        //position is out of range
        if(position>countLength(head)){
            cout<<"Position out of Bound";
        } else{
            cout<<"There is no value in the linked list"<<endl;
        }
        //ll is null
    }
    
}

void deletionByValueUniqueList(Node* &head, int value){
    int position;
    //find the position of the value
    position = searchByValueUnique(head, value);
    if(position == -1){
        cout<<"Value not found in the linked list!";
        
    } else {
        //delete the node at the position
        deletionAtSpecificPosition(head, position);
    }
}

Node* reverseNonRecursive (Node* &head){
    Node* prev = NULL;
    Node* current = head;
    if(head==NULL){
        cout<<"the linked list is empty"<<endl;
        return head;
    }
    Node* next = head->Next;

    while(true){
        current->Next = prev;
        prev=current;
        current = next;
        if(current == NULL) break;
        next = next->Next;
    }
   return prev;
}

Node* reverseRecursive(Node* &head){
    //base call
    if(head == NULL || head->Next == NULL){
        if(head == NULL) cout<<"the linked list is empty"<<endl;
        return head;
    }
    //recursive call
    Node* newHead = reverseRecursive(head->Next);
    newHead->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

int findMid (Node* &head) {
    //case 1: head empty 
    if(head == NULL){
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->Next != NULL){
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
}

int main(){
    
    Node* head = NULL;
    
    int value, position;
    cout<<"Choice 1: Insertion at Head"<< endl 
    <<"Choice 2: Insertion at Tail" << endl 
    << "Choice 3: insertion at certain position"<<endl
    << "Choice 4: Search a value (unique list)"<<endl
    << "Choice 5: Search a value (Duplication enabled list)"<<endl
    << "Choice 6: Search a value (Duplication enabled list return)"<<endl
    << "Choice 7: Insertion after a specific value (Unique list)"<<endl
    << "Choice 8: Deletion at head"<<endl
    << "Choice 9: Deletion at Tail"<<endl
    << "Choice 10: Deletion at Specific position"<<endl
    << "Choice 11: Deletion Value(unique list)"<<endl
    << "Choice 12: Reverse a linked list (Non Recursive)"<<endl
    << "Choice 13: Reverse a linked list (Recursive)"<<endl
    << "Choice 14: Finding the mid (slow fast pointer method)"<<endl
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
            cout<<"Enter the Desired Position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout<<"Enter the value: ";
            cin>>value;
            position = searchByValueUnique(head, value);
            if(position != -1){
                cout<<"The number is at position "<<position<<endl;
            } else {
                cout<<"The number is yet in the list"<<endl;
            }
            break;
        case 5:
            cout<<"Enter the value: ";
            cin>>value;
            searchByValueDuplicate(head, value);
            break;
        case 6:
            cout<<"Enter the value: ";
            cin>>value;
            Test T;
            T=searchByValueDuplicateReturn(head, value);
            if(T.position[0] == 1){
                cout<<"The searched value is not yet in this list"<<endl;
            } else {
                int size = T.position[0];
                cout<<"The searched value is found at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout<<T.position[i];
                    if(i<size-1) cout<<", ";
                }
                cout<<endl;
            }
            break;
        case 7:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: ";
            cin>>value;
            searchByValueUnique(head, searchValue, value);
            break;
        case 8:
            deletionAtHead(head);
            break;
        case 9:
            deletionAtTail(head);
            break;
        case 10:
            cout<<"Enter the desired position: ";
            cin>>position; 
            if(head == NULL){
                cout<<"There is no value in the linked list"<<endl;
                break;
            }
            deletionAtSpecificPosition(head, position);
            cout<<endl;
            display(head);
            break;
        case 11:
            int delValue;
            cout<<"Enter the value to delete: ";
            cin>>delValue; 
            deletionByValueUniqueList(head, delValue);
            cout<<endl;
            display(head);
            break;
        case 12:
            head = reverseNonRecursive(head);
            display(head);
            break;
        case 13:
            head = reverseRecursive(head);
            display(head);
            break;
        case 14:
            int midVal;
            midVal = findMid(head);
            if(midVal == -1) 
                cout<<"The LL is empty" <<endl;
            else 
                cout<<"mid value is: "<<midVal<<endl;
            break;
        default:
            break;
        }        
        cout<<"Next Choice: ";
        cin>>choice;
    }
    cout<<"linked list: ";  
    display(head);
    cout<<endl<<"reverse linked list: ";
    printReverse(head);
    cout<<endl<<"length of the list: "<<countLength(head);

    return 0;
}
