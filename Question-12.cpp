#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
};
void Rearranges(Node *list){
    if(list == nullptr || list->next == nullptr) {
        return;
    }

    Node *p = list;
    Node *q = list->next;
    int temp;

    while(q != nullptr) {
        temp = p->value;
        p->value = q->value;
        q->value = temp;

        p = q->next;
        q = p != nullptr ? p->next : nullptr;
    }
}
int main(){
//The contents of the list after the function completes execution would be: 2, 1, 4, 3, 6, 5, 7.   
}