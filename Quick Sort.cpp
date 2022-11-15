#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort(int input[], int size) {


    quickSort(input, 0, size - 1);

}

int main(){
  int length;
  cout<<" Enter the size of the array = ";
  cin >> length;
  int* input = new int[length];
  cout<<" Enter the elements : ";
  for(int i=0; i < length; i++)
    cin >> input[i];
  quickSort(input, length);
  cout<<"\n Sorted array : ";
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  delete[] input;
  cout<<"\n\n This program was made by  Lavanya Narang IT-B 71 \n\n";

}

