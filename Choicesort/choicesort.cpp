#include <iostream>
#include <vector>
#include <ctime>

// по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {2,103}

using namespace std;


int main() {
    
    int n = 10;
    int min = 0;
    int buf = 0;
    vector <int> arr(n);
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%102 + 2;
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        buf = arr[i];
        arr[i] = arr[min];
        arr[min] = buf;
        
    }
        
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "Sorted" << endl;
    
    return 0;
}
