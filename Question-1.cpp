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
        Node* GetClone();
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
Node* Node::GetClone(){
    Node *newNode = new Node;
    newNode->SetData(data);
    newNode->SetNext(nullptr);
    return newNode;
}

class List{
    private:
        Node *head;
        Node *tail;
    public:
        List();
        void InsertAtEnd(int val);
        void Display();
        Node* GetHead();
        ~List();
};
List::List(){
    head = nullptr;
    tail = nullptr;
}
Node* List::GetHead(){
    return head;
}
void List::InsertAtEnd(int val){
    Node *newNode = new Node;
    newNode->SetData(val);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void List::Display(){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->GetData() << " " ;
        temp = temp->GetNext();
    }
    cout << endl;
}
List::~List(){
    Node *current = head;
    while(current != nullptr){
        Node* temp = current->GetNext();
        delete current;
        current = temp;
    }
}
void Concatenate(Node *h1, Node* h2){
    if(h2==nullptr){
        return;
    }
    else{
        Node *current = h1;
        while(current->GetNext() != nullptr){
            current = current->GetNext();
        }
        Node *temp = h2;
        while(temp != nullptr){
            Node* newNode = temp->GetClone();
            if(h1 == nullptr){
                h1 = newNode;
                current = newNode;
            }
            else{
                current->SetNext(newNode);
                current = newNode;
            }
            temp = temp->GetNext();
        }
    }
}
int main(){
    cout << "<-------------Lists before concatenation------------->" << endl;
    List l1;
    l1.InsertAtEnd(2);
    l1.InsertAtEnd(3);
    l1.InsertAtEnd(1);
    l1.Display();
    List l2;
    l2.InsertAtEnd(4);
    l2.InsertAtEnd(5);
    l2.Display();
    cout << "<-------------Lists after concatenation------------->" << endl;
    Concatenate(l1.GetHead(),l2.GetHead());
    l1.Display();
    l2.Display();
}

