#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    public:
        Node(int data,Node*next){
            this->data = data;
            this->next = next;
        }
};

Node* ArrToLL(vector<int>arr){
    Node* head = new Node(arr[0],nullptr);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
} 

Node* insertatHead(int x, Node* head){
    // Node* temp = new Node(x,head);
    // return temp ;

    // or
    return new Node(x,head);
}

Node* insertAtTail(Node* head,int x){
    if(head == nullptr){
        return new Node(x,nullptr);
    }
    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* nodeToInsert = new Node(x,nullptr);
    temp->next = nodeToInsert;
    
    return head;
}

Node* insertAtPosition(Node* head, int x, int k){
    int len = length(head);

    if(k > len+1 || k<1){
        cout<<"Can't insert this node\n";
        return nullptr;
    }
    if(k == 1 && head == nullptr) return insertatHead(x,head);
    if(k == len+1) return insertAtTail(head,x);
    
    Node*temp = head;
    for(int i=1;i<k-1;i++){
        temp = temp->next;
    }
    Node* nodeToInsert = new Node(x,nullptr);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    return head;
}
int main(){
    
    vector<int> arr = {1,2,3,4,12,96,100};
    Node* head = ArrToLL(arr);

    cout<<"Prinitng LL : ";
    printLL(head);

    // int res = length(head);
    // cout<<"\nPrinitng LL length : "<<res<<endl;

    // cout<<"Inserting at head\n";
    // int x=0;
    // cout<<"Enter data to be inserted at head : ";
    // cin>>x;
    // head = insertatHead(x,head);
    // cout<<"Prinitng LL : ";
    // printLL(head);

    // cout<<"\nInserting at Tail\n";
    // int x=0;
    // cout<<"Enter data to be inserted at tail : ";
    // cin>>x;
    // head = insertAtTail(head,x);
    // cout<<"Prinitng LL : ";
    // printLL(head);

    cout<<"\nInserting at any position\n";
    int x=0,k=0;
    cout<<"Enter data to be inserted and the position : ";
    cin>>x>>k;
    head = insertAtPosition(head,x,k);
    cout<<"Prinitng LL : ";
    printLL(head);


    return 0;
}