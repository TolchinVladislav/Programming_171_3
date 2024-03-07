#include <iostream>

using namespace std;

// Дано натуральное число n. Выведите все числа от 1 до n.
void recursion (int n);

void recursion (int n) {
    if (n == 1) {
        cout << n << " ";
        return;
    };
    
    recursion (n-1);
    cout << n << " ";
}

int main() {
    
    int n = 0;
    
    cout << " Input n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << " n is not natural" << endl;
        return 0;
    }

    recursion (n);
    
    return 0;
}
