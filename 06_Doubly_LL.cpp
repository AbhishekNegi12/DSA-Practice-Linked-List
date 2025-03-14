//Array to LL
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

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int>arr = {1, 12, 3, 56, 2, 36};

    // Node* head = new Node(arr[0],nullptr,nullptr);
    Node* head = ArrayToLL(arr);
    cout<<"Printing Doubly LL : ";
    printLL(head);
    return 0;
}