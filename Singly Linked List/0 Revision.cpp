#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};
void insert1(node *& head,int value){
    node*n=new node;
    n->data=value;
if(head==nullptr){
head=n;
head->next=nullptr;
return;
}
n->next=head;
head=n;
}
void insert2(node*& head,int value){
    node*n=new node();
     n->data=value;
    if(head==nullptr){
    n->next=nullptr;
    head=n;
    return;
    }
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
    n->next=nullptr;
}
void print(const node* head){           //Using constant because here head will never be modified , its just printing
if(head==nullptr){
    cout<<"List is empty"<<endl;
    return;
}
const node*temp=head;
while(temp!=nullptr){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
int main(){
    node* head=nullptr;
    insert1(head,10);
    insert2(head,20);
    insert2(head,30);
    insert1(head,5);
    print(head);
    return 0;
}