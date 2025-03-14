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

Node* deletionAtHead(Node* head){

    //edge cases
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* temp = head;
    
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}

Node* deletionAtTail(Node* head){

    //edge cases
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    // Node* nodeToDelete = temp;
    // nodeToDelete->prev->next = nullptr;
    // nodeToDelete->prev = nullptr;
    // delete nodeToDelete;

    return head;

}
Node* deletion(Node* head,int k){
    int len = lengthLL(head);

    //edge cases
    if(k > len){
        cout<<"Enter a valid position to delete"<<endl;
        return nullptr;
    }
    if(k==1) return deletionAtHead(head);
    if(k==len) return deletionAtTail(head);
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    for(int i=1 ;i<k-1;i++){
        temp = temp->next;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;

    nodeToDelete->next = nullptr;
    nodeToDelete->prev = nullptr;
    delete nodeToDelete;

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
    // vector<int>arr = {1, 12, 3, 56, 2, 36};
    vector<int>arr = {1,13};

    // Node* head = new Node(arr[0],nullptr,nullptr);
    Node* head = ArrayToLL(arr);
    cout<<"Printing Doubly LL : ";
    printLL(head);

    // head = deletionAtHead(head);
    // cout<<"\nPrinting Doubly LL after deletion at head : ";
    // printLL(head);

    // head = deletionAtTail(head);
    // cout<<"\nPrinting Doubly LL after deletion at tail : ";
    // printLL(head);

    int k;
    cout<<"\nEnter the position to be deleted : ";
    cin>>k;
    head = deletion(head,k);
    cout<<"Printing Doubly LL after deletion : ";
    printLL(head);

    return 0;
}