#include <iostream>
using namespace std;

class node{
    public:
int data;
node* next;
node(){}
node(int x):data(x){}
};

void print(node*head){
if(head==nullptr){
    cout<<"List is empty!!"<<endl;
    return;
}
node*temp=head;
while(temp!=nullptr){
cout<<temp->data<<endl;
temp=temp->next;
}
}

int main() {
    node* head=nullptr;
    node*n1=new node();
    node*n2=new node;
    node*n3=new node(30);
    head=n1;
    head->data=10;
    head->next=n2;
    n2->data=20;
    n2->next=n3;
    n3->next=nullptr;
    print(head);
    return 0;
}