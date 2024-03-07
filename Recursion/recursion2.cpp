#include <iostream>

using namespace std;
//Даны два целых числа A и В.
//Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае


void recursion (int a, int b);
void recursion2 (int a, int b);

void recursion (int a, int b) {
    if (a == b) {
        cout << b << " ";
        return;
    };
    
    recursion (a, b-1);
    cout << b << " ";
}

void recursion2 (int a, int b) {
    if (a == b) {
        cout << b << " ";
        return;
    };
    
    recursion2 (a, b+1);
    cout << b << " ";
}

int main() {
    
    int a = 0;
    int b = 0;
    
    cout << " input a: ";
    cin >> a;
    
    cout << " input b: ";
    cin >> b;
    
    if (a < b){
        recursion (a,b);
    } else {
        recursion2 (a,b);
    }
    
    return 0;
}
