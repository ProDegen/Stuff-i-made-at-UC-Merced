#include <iostream>
using namespace std;  
int main() {
    string str1 = "";
    string str2 = "";
    int loop = 0;
    cout << "enter a string: " << endl;
    cin >> str1;
    str2 = str1;
    cout << "enter a number of times: " << endl;
    cin >> loop;
    for (int i = 0; i<loop-1;i++){
        str1.append(str2);
    }
    cout << str1 << endl;
    return 0;
}