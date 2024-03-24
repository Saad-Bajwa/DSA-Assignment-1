#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
    private :
        int data;
        Node* next;
    public :
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
        void InsertAtEnd(int val);
        void Display();
        vector<pair<int,int>> CountOccurence();
        ~List();
};
List::List(){
    head = nullptr;
    tail = nullptr;
}
vector<pair<int,int>> List::CountOccurence(){
    unordered_map<int,int> counts;
    Node *current = head;
    while(current!= nullptr){
        counts[current->GetData()]++;
        current = current->GetNext();
    }
    vector<pair<int,int>> result;
    for(const auto& pair: counts){
        result.push_back(pair);
    }
    return result;
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
int main(){
    List list;
    for(int i=0; i<12; i++){
        int val;
        cout << "Enter the value in the list : " ;
        cin >> val;
        list.InsertAtEnd(val);
    }
    vector<pair<int,int>> result = list.CountOccurence();
    for(const auto& pair:result){
        cout << pair.first << "\t\t" << pair.second << endl;
    }
}