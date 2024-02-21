#include <iostream>
#include <vector>
#include <ctime>


//по убыванию одномерный массив случайных целых чисел, находящихся в интервале {0,100}.

using namespace std;


int main() {
    
    int n = 10;
    int max = 0;
    int buf = 0;
    vector <int> arr(n);
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%101;
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < n-1; i++){
        max = i;
        for (int j = i; j < n; j++){
            if (arr[j] > arr[max]){
                max = j;
            }
        }
        buf = arr[i];
        arr[i] = arr[max];
        arr[max] = buf;
        
    }
        
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "Sorted" << endl;
    
    return 0;
}
