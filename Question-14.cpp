#include<iostream>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
    public:
        Node();
        void SetData(int val);
        void SetNext(Node* adr);
        int GetData();
        Node* GetNext();
};
Node:: Node(){
    next = nullptr;
}
void Node::SetData(int val){
    data = val;
}
void Node::SetNext(Node* adr){
    next = adr;
}
int Node::GetData(){
    return data;
}
Node* Node::GetNext(){
    return next;
}

class List{
    private:
        Node *head;
        Node *tail;
    public:
        List();
        void InsertInAscend(int val);
        void Display();
        ~List();
};
List::List(){
    head = nullptr;
    tail = nullptr;
}
void List::InsertInAscend(int val){
    Node *newNode = new Node;
    newNode->SetData(val);
    if(head == nullptr || head->GetData() >= val){
        newNode->SetNext(head);
        head = newNode;
        if(tail == nullptr){
            tail = newNode;
        }
        return;
    }
    Node *temp = head;
    while(temp->GetNext() != nullptr && temp->GetNext()->GetData() <= val){
        temp = temp->GetNext();
    }
    newNode->SetNext(temp->GetNext());
    temp->SetNext(newNode);
    if(newNode == nullptr){
        tail = newNode;
    }
}
void List::Display(){
    Node * temp  = head;
    while (temp != nullptr){
        cout << temp->GetData() << " " ;
        temp = temp->GetNext();
    }
    cout << endl;
}
List::~List(){
    Node *temp = head;
    while(temp!=nullptr){
        Node *current = temp->GetNext();
        delete temp;
        temp = current;
    }
}
int main(){
    List list;
    list.InsertInAscend(3);
    list.InsertInAscend(17);
    list.InsertInAscend(28);
    list.InsertInAscend(18);
    list.InsertInAscend(20);
    list.Display();
}