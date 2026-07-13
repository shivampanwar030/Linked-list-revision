#include <iostream>
using namespace std;

class node{
public:
int data;
node*prev;
node*next;
node(){}
node(int x):data(x){}
};

void insert1(node *& head,int value){
    node*n=new node();
    n->data=value;
    n->prev=nullptr;
    if(head==nullptr){
    n->next=nullptr;
    head=n;
    return;
    }
    head->prev=n;
    n->next=head;
    head=n;
}

void insert2(node *& head,int value){
    node*n=new node;
    n->data=value;
    n->next=nullptr;
    if(head==nullptr){
        n->prev=nullptr;
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void remove(node *& head,int key){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->data==key){
        node*temp=head;
        head=head->next;
        if(head!=nullptr){
        head->prev=nullptr;
        }
        delete temp;
        temp=nullptr;
        return;
    }
    node*curr=head;
    while(curr!=nullptr && curr->data!=key){
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<"There is no such element in the list"<<endl;
        return;
    }
    curr->prev->next=curr->next;
    if(curr->next!=nullptr){
    curr->next->prev=curr->prev;
    }
    delete curr;
    curr=nullptr;
}

void print(node*& head){
node*curr=head;
while(curr!=nullptr){
    cout<<curr->data<<" ";
    curr=curr->next;
}
}
int main() {
    node * head=nullptr;
    insert1(head,1);
    insert2(head,2);
    insert2(head,3);
    insert2(head,4);
    insert2(head,5);
    cout<<"Before removing: ";
    print(head);
    remove(head,3);
    cout<<endl<<"After removing 3: ";
    print(head);
    return 0;
}
