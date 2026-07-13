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
void remove(node *& head,int key){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    else if(head->data==key){
        node*temp=head;
        head=head->next;
        delete temp;
        return;
    }
    node*curr=head;
    node*prev=nullptr;
    while(curr!=nullptr && curr->data!=key){
        prev=curr;
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<"There is no such element in the list"<<endl;
        return;
    }
    prev->next=curr->next;
    delete curr;
    curr=nullptr;
    cout<<"Element "<<key<<" sucessfully deleted"<<endl;
}
void print(node*& head){
    node*temp=head;
    if(temp==nullptr){
        cout<<"List is empty!!!"<<endl;
        return;
    }
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main(){
    node*head=nullptr;
    insert1(head,30);
    insert1(head,20);
    insert1(head,10);
    cout<<"Before deleting: "<<endl;
    print(head);
    cout<<endl<<endl;
    remove(head,20);
    cout<<"After deleting"<<endl;
    print(head);
    return 0;
}