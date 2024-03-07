#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Написать программу, сортирующую по возрастанию первый столбец двумерного массива целых чисел.
// Использовать быструю сортировку
// Массив создать из случайных чисел, расположенных в интервале {5,61}

void quicksort(vector <vector <int> > &ar, int end, int begin) {
    int i = end;
    int k = begin;
    int buf = 0;
    
    int mid = ar[(end +begin)/2][0];
    
    while (i <= k) {
        while (ar[i][0] < mid)
            i = i + 1;
        while (ar[k][0] > mid)
            k = k - 1;
        
        if (i <= k) {
            buf = ar[i][0];
            ar[i][0] = ar[k][0];
            ar[k][0] = buf;
            
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
    vector <vector <int> > mat (n,  vector <int> (2));
    
    srand(time(0));
       
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            mat[i][j] = rand()%57 + 5;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    quicksort(mat,0,n-1);
    
    cout << endl;
    cout << "Sorted" << endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}
