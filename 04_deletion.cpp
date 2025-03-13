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
Node * DeleteHead(Node* head){
    if(head == nullptr){
        return head;
    }
    // if(head->next == nullptr){
    //     return nullptr;
    // }
    Node* temp = head;
    head = head->next;
    // free(temp);
    delete temp;

    return head;
}

Node* DeleteTail(Node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }

    Node* temp = head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    // free(temp->next);
    delete temp->next;
    temp->next = nullptr;

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

Node* DeleteNode(Node* head, int k) {
    int len = length(head);

    if (k > len) {
        cout << "Can't delete as k exceeds list length." << endl;
        return head;
    }

    if (k == 1) return DeleteHead(head);
    if (k == len) return DeleteTail(head);

    Node* temp = head;
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}


int main(){
    
    vector<int> arr = {1,2,3,4,12,96,100};
    Node* head = ArrToLL(arr);

    cout<<"Prinitng LL : ";
    printLL(head);

    int res = length(head);
    cout<<"\nPrinitng LL length : "<<res<<endl;

    // int x;
    // cout<<"\nEnter the data to be delete : ";
    // cin>>x;
    // head = DeleteHead(head);
    // cout<<"Prinitng LL : ";
    // printLL(head);

    int x,k;
    cout<<"\nEnter the data to be delete and value of k : ";
    cin>>x>>k;
    head = DeleteNode(head,k);
    cout<<"Prinitng LL : ";
    printLL(head);

    return 0;
}