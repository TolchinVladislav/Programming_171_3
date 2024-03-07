#include <iostream>
#include "math.h"

//                                   ____      ____     ___   __    __             ____     ____
//      //\\  //\\    //\\   || //  ||        //   \\  || ||  ||    ||  |\\  ||   //   \\  ||
//     ||  \\//  ||  ||__||  ||//   ||___    ||        || //  ||    ||  ||\\ ||  ||        ||___
//     ||        ||  ||  ||  ||\\   ||       ||   ___  ||\\   ||    ||  || \\||  ||   ___  ||
//     ||        ||  ||  ||  || \\  ||___     \\___//  || ||   \\__//   ||  \\|   \\___//  ||___


using namespace std;
// Дано натуральное число n>1. Выведите все простые делители этого числа в порядке возрастания.
// Нельзя использовать массивы и циклы

void isPrime(int num, int k, int *check);
void primediveders (int n, int runner);
void doitagain (int n, int runner);

void primediveders (int n, int runner) {
    
    int pr = 0;
    
    if (runner*runner > n) {
        return;
    }
    
    if (n%runner == 0){
        isPrime(runner,2, &pr);
           if (pr == 1)
               cout << runner << " ";
    }
    primediveders(n, runner+1);
}

void doitagain (int n, int runner) {
    
    int pr = 0;
    
    if (runner*runner >= n) {
        return;
    }
      
    
    
    if (n%runner == 0){
        isPrime(n/runner,2, &pr);
           if (pr == 1)
               cout << n/runner << " ";
    }
    doitagain(n, runner+1);
}

void isPrime(int num, int k, int *check) {
    
   
    if (k == num) {
        *check = 1;
        return;
    }
        
    if (num%k == 0)
        return;
    
    isPrime(num, k+1, check);

    return;
}


int main() {
    
    int n = 0;
    int prime = 0;
    int buf = 0;
    
    
    cout << "Input n: ";
    cin >> n;
    
    if (n <= 1){
        cout << "n doesn't match with initial condition" << endl;
        return 0;
    }
    
    isPrime(n,2, &buf);
    if (buf == 1) {
        cout << n << " ";
        return 0;
    }
    
    primediveders(n,2);
    doitagain (n,2);
    
    return 0;
}
