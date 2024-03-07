#include <iostream>
#include <vector>
#include <ctime>

//Задана последовательность из 1000 целых чисел.
//Переставить элементы последовательности таким образом, чтобы они располагались в порядке возрастания.

using namespace std;

void quicksort(vector <int> &ar, int end, int begin) {
    int i = end;
    int k = begin;
    int buf = 0;
    
    int mid = ar[(end +begin)/2];
    
    while (i <= k) {
        while (ar[i] < mid)
            i = i + 1;
        while (ar[k] > mid)
            k = k - 1;
        
        if (i <= k) {
            buf = ar[i];
            ar[i] = ar[k];
            ar[k] = buf;
            
            i = i + 1;
            k = k - 1;
        }
    }
    
    if (end < k)
        quicksort(ar, end, k);
    
    if (i < begin)
        quicksort(ar, i, begin);
    
    
}

int main() {
    int n = 1000;
    vector <int> arr(n);
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%5000 + 1;
        cout << "Index: " << i+1  << ": " << arr[i] << endl;
    }
    
    cout << endl;
    cout << "Sorted" << endl;
    
    quicksort(arr, 0, n-1);
    
    for (int i = 0; i < n; i++) {
        cout << "Index " << i+1 << ": " << arr[i] << endl;
    }
 
    return 0;
}
