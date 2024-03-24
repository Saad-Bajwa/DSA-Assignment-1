#include <iostream>
using namespace std;
class Node{
    private:
        int data;
        Node* next;
    public:
        Node();
        void SetData(int val);
        void SetNext(Node *adr);
        int GetData();
        Node* GetNext();
};
Node::Node(){
    next = nullptr;
}
void Node::SetData(int val){
    data = val;
}
void Node::SetNext(Node *adr){
    next = adr;
}
int Node::GetData(){
    return data;
}
Node* Node::GetNext(){
    return next;
}

class CircularList{
    private:
        Node *head;
        Node *tail;
    public:
        CircularList();
        void InsertAtHead(int val);
        void InsertAtTail(int val);
        void DeleteAtHead();
        void DeleteAtTail();
        ~CircularList();
};
CircularList :: CircularList(){
    head = nullptr;
    tail = nullptr;
}
void CircularList::InsertAtHead(int val){
    Node *newNode = new Node;
    newNode->SetData(val);
    if(head == nullptr){
        newNode->SetNext(newNode);
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->SetNext(head);
        tail->SetNext(newNode);
        head = newNode;
    }
}
void CircularList::InsertAtTail(int val){
    Node *newNode = new Node;
    newNode->SetData(val);
    if(head == nullptr){
        newNode->SetNext(newNode);
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->SetNext(head);
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void CircularList::DeleteAtTail(){
    if(head == nullptr){
        cout << "List is empty!!!" << endl; 
        return;
    }
    if(head == tail){
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *current = head;
    while(current->GetNext() != tail){
        current = current->GetNext();
    }
    current->SetNext(head);
    delete tail;
    tail = current;
}
void CircularList::DeleteAtHead(){
    if(head == nullptr){
        cout << "List is empty!!!" << endl; 
        return;
    }
    Node *temp = head;
    if(temp == tail){
        delete temp;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *current = head->GetNext();
    delete temp;
    head = current;
    tail->SetNext(head);
}
int main(){

}