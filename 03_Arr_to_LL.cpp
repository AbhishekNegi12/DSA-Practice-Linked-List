#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    public:
        Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }
};

Node* ArrToLL(vector<int>&arr){
    Node* head = new Node(arr[0],nullptr);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr);
        mover->next = temp;
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

int lengthLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}

bool searchLL(Node* head, int x){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == x){
            return true;
            break;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,12,96,100};
    Node* head = ArrToLL(arr);
    // cout<<head->data;
    // cout<<head->next;
    printLL(head);
    // cout<<"\nLength of LL : "<<lengthLL(head)<<endl;
    int x;
    cout<<"\nEnter the data to be searched : ";
    cin>>x;
    cout<<x<<" is present : "<<searchLL(head,x);
    return 0;
}