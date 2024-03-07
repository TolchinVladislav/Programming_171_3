#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {50,100}.
//Использовать быструю сортировку

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
    int n = 10;
    vector <int> arr(n);
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%51 + 50;
        cout << arr[i] << " ";
    }
    
    cout << endl;
    cout << "Sorted" << endl;
    
    quicksort(arr, 0, n-1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}
