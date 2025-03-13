#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        data=this->data;
        next=this->next;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* y = new Node(arr[0],nullptr);
    cout<<y;

    return 0;
}