#include <iostream>

using namespace std;

void merge(int a[], int si, int mid, int ei)
{
    int size3 = ei - si + 1 ;
    int ans[size3];
    int i = si, j= mid+1;
    for(int k = 0; k<size3; k++)
    {
        if(i==mid+1)
        {
            ans[k] = a[j++];
            continue;
        }
        if(j==ei+1)
        {
            ans[k] = a[i++];
            continue;
        }
        if(a[i] < a[j])
        {
            ans[k] = a[i];
            i++;
        }
        else
        {
            ans[k] = a[j];
            j++;
        }

    }

    for(int x = 0, y = si; y<=ei  ; x++,y++)
    {
         a[y] = ans[x];
    }

}


void merge_sort(int a[], int si, int ei)
{
    if(si>=ei)
    {
         return;
    }
    int mid = (si+ei)/2;
    merge_sort(a,si,mid);
    merge_sort(a,mid+1,ei);
    merge(a,si,mid,ei);
}


void mergeSort(int input[], int size){

    merge_sort(input,0,size-1);

}

int main() {
  int length;
  cout<<" Enter the size of the array = ";
  cin >> length;
  int* input = new int[length];
  cout<<" Enter the elements : ";
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  cout<<"\n Sorted array : ";
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  delete[] input;
  cout<<"\n\n This program was made by Lavanya Narang IT-B 71\n\n";
}
