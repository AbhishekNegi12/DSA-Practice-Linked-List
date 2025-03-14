#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    public:
        Node(int data, Node* next, Node* prev){
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    public:
        Node(int data){
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

Node* ArrayToLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    // Node* back = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

int lengthLL(Node* head){
    Node* temp = head;
    int count =0;
    while(temp!= nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* insertionBeforeHead(Node* head,int x){

    //edge cases
    if(head == nullptr){
        return new Node(x);
    }

    Node* temp = new Node(x);
    head->prev = temp;
    temp->next = head;
    head = temp;

    return head;
}

Node* insertionBeforeTail(Node* head,int x){

    //edge cases
    if(head == nullptr){
        return new Node(x);
    }
    if(head->next == nullptr){
        Node* temp = new Node(x);
        head->prev = temp;
        temp->next = head;
        head = temp;

        return head;
    }

    Node* temp = head;    
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* nodeToInsert = new Node(x,temp,temp->prev);
    temp->prev->next = nodeToInsert;
    temp->prev = nodeToInsert;

    return head;

}

Node* insertion(Node* head, int x, int k){
    int len = lengthLL(head);

    //edge cases    
    if(head == nullptr){
        return new Node(x);
    }
    if(head->next == nullptr){
        Node* temp = new Node(x);
        head->prev = temp;
        temp->next = head;
        head = temp;

        return head;
    }
    if(k > len){
        cout<<"Enter a valid position to inserted"<<endl;
        return nullptr;
    }
    if(k==1) return insertionBeforeHead(head,x);
    if(k==len) return insertionBeforeTail(head,x);

    Node* temp = head;
    for(int i=1 ;i<k-1;i++){
        temp = temp->next;
    }
    Node* nodeToInsert = new Node(x,temp->next,temp);
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;

    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    vector<int>arr = {1, 12, 3, 56, 2, 36};
    // vector<int>arr = {1};

    // Node* head = new Node(arr[0],nullptr,nullptr);
    Node* head = ArrayToLL(arr);
    cout<<"Printing Doubly LL : ";
    printLL(head);

    // int x;
    // cout<<"\nEnter value to be inserted : ";
    // cin>>x;
    // head = insertionBeforeHead(head,x);
    // cout<<"Printing Doubly LL after insertion before head : ";
    // printLL(head);

    // int x;
    // cout<<"\nEnter value to be inserted : ";
    // cin>>x;
    // head = insertionBeforeTail(head,x);    
    // cout<<"Printing Doubly LL after insertion before tail : ";
    // printLL(head);

    int x,k;
    cout<<"\nEnter the position to be inserted and value : ";
    cin>>k>>x;    
    head = insertion(head,x,k);
    cout<<"Printing Doubly LL after insertion : ";
    printLL(head);

    return 0;
}