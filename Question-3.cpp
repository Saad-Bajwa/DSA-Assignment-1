#include<iostream>
using namespace std;
int main(){
    int array[5];
    for(int i=0; i<5; i++){
        cout << "Enter the value at " << i+1 << " position : ";
        cin >> array[i];
    }
    cout << "Values in reverse orders are : " << endl;
    for(int i=4; i>=0; i--){
        cout << array[i] << endl;
    }
}