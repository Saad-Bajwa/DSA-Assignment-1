#include <iostream>
using namespace std;
class Node
{
private:
    int object;
    Node *next;
    Node *previous;

public:
    int GetObject();
    void SetObject(int data);
    Node *GetNext();
    void SetNext(Node *nextNode);
    Node *GetPrevious();
    void SetPrevious(Node *prevNode);
};
void Node::SetObject(int data){
    object = data;
}
void Node::SetNext(Node *nextNode){
    next = nextNode;
}void Node::SetPrevious(Node *prevNode){
    previous = prevNode;
}
int Node::GetObject(){
    return object;
}
Node* Node::GetNext(){
    return next;
}
Node* Node::GetPrevious(){
    return previous;
}

class DoublyList{
    private:
        Node *head;
        Node *tail;
    public:
        DoublyList();
        void InsertAtHead(int val);
        void InsertAtTail(int val);
        void DeleteNode(int val);
        void PrintList();
        ~DoublyList();
};
DoublyList::DoublyList(){
    head = nullptr;
    tail = nullptr;
}
void DoublyList::InsertAtTail(int val){
    Node* newNode = new Node;
    newNode->SetObject(val);
    newNode->SetNext(nullptr);
    newNode->SetPrevious(nullptr);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->SetPrevious(tail);
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void DoublyList::InsertAtHead(int val){
    Node* newNode = new Node;
    newNode->SetObject(val);
    newNode->SetNext(nullptr);
    newNode->SetPrevious(nullptr);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->SetNext(head);
        head->SetPrevious(newNode);
        head = newNode;
    }
}
void DoublyList::DeleteNode(int val){
    Node *temp = head;
    while(temp!=nullptr){
        if(temp->GetObject() == val){
            if(temp == head){
                head = temp->GetNext();
                if(head!=nullptr){
                    head->SetPrevious(nullptr);
                }
            }
            else if(temp == tail){
                tail = temp->GetPrevious();
                if(tail!=nullptr){
                    tail->SetNext(nullptr);
                }
            }
            else{
                temp->GetNext()->SetPrevious(temp->GetPrevious());
                temp->GetPrevious()->SetNext(temp->GetNext());
            }
            delete temp;
            return;
        }
        temp = temp->GetNext();
    }
    cout << "Value doesnot found" << endl;
}
void DoublyList::PrintList(){
    Node *temp = head;
    while(temp!= nullptr){
        cout << temp->GetObject() << " " ;
        temp = temp->GetNext();
    }
    cout << endl;
}
DoublyList::~DoublyList(){
    Node* temp;
    while(head!=nullptr){
        temp = head->GetNext();
        delete head;
        head = temp;
    }
}
int main()
{
    DoublyList list1;
    list1.InsertAtTail(2);
    list1.InsertAtTail(3);
    list1.InsertAtHead(5);
    list1.InsertAtHead(8);
    list1.DeleteNode(5);
    list1.PrintList();
}