#include <iostream>
#include <vector>
using namespace std;

class ArrayProblem1
{
public:
    static bool firstLast6(vector<int> &array)
    {
        if (array[0] == 6 || array[array.size() - 1] == 6)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 6};
    cout << ArrayProblem1::firstLast6(arr) << endl;
    arr = {3, 2, 4, 5};
    cout << ArrayProblem1::firstLast6(arr) << endl;
    arr = {6, 3, 2};
    cout << ArrayProblem1::firstLast6(arr) << endl;
}