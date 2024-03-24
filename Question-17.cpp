#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    int GetObject();
    void SetObject(int data);
    Node *GetNext();
    void SetNext(Node *nextNode);
    Node *GetPrevious();
    void SetPrevious(Node *prevNode);
};
void Node::SetObject(int data){
    data = data;
}
void Node::SetNext(Node *nextNode){
    next = nextNode;
}void Node::SetPrevious(Node *prevNode){
    prev = prevNode;
}
int Node::GetObject(){
    return data;
}
Node* Node::GetNext(){
    return next;
}
Node* Node::GetPrevious(){
    return prev;
}

class DoublyList{
    private:
        Node *head;
        Node *tail;
    public:
        DoublyList();
        void InsertNode(int val);
        void DeleteNode(int val);
        void PrintList();
        ~DoublyList();
};
DoublyList::DoublyList(){
    head = nullptr;
    tail = nullptr;
}
void DoublyList::InsertNode(int val){
    Node* newNode = new Node;
    newNode->SetObject(val);
    Node *temp = head;
    for(int i=0; i<3-1 && temp!=nullptr; i++){
        temp = temp->GetNext();
    }
    newNode->SetNext(temp->GetNext());
    newNode->SetPrevious(temp);
    temp->GetNext()->SetPrevious(newNode);
    temp->SetNext(newNode);
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
int main()
{
}