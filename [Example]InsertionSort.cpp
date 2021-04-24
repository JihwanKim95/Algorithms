// InsertionSort without Swap 

#include <iostream>

using namespace std;

template<typename Type>
void Insertion_Sort_Without_Swap(Type* _array, int _n)
{
    for(int i = 1; i < _n; i++)
    {
        Type tmp = _array[i];
        for(int j = i; j > 0; j--)
        {
            if(_array[j-1] > tmp)
                _array[j] = _array[j-1];
            else 
            {
                _array[j] = tmp;
                break;
            }   
        }
        if(_array[0] > tmp)
        {
            _array[0] = tmp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int arr[10] = {0, 30, 4, 5, 8, 2, 1, 9, 10, 6};
    Insertion_Sort_Without_Swap(arr, 10);

    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
}