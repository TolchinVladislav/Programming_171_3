#include <iostream>

using namespace std;

//Дано натуральное число N. Вычислите сумму его цифр.

int summ (int n);

int summ (int n) {
    if (n == 0)
        return 0;
    
    return summ ((int) n/10 ) + n%10;
}

int main() {
    
    int n = 0;
    
    cout << "Input n: ";
    cin >> n;
    
    if (n <=0 ){
        cout << "n is not natural" << endl;
        return 0;
    }
    
    cout << "Sum of number digits n: " << summ(n) << endl;
  
    return 0;
}
