#include <iostream>
using namespace std;
int partition(int arr[], int low, int high){
  //setting pivot to value at last index for this algo, but couldve chosen any index's value
  int pivot = arr[high];
  
  int i = (low - 1); //want an index counter starting before low
  //i holds the next spot that a value less than pivot can be placed 
  //j holds the index that will travel the whole array up to pivot

  for (int j = low; j < high; j++){
    //if current element smaller than the pivot
    //increment i and swap j and i
    if (arr[j] < pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  //swap the pivot with i+1 so as to place pivot right in the spot where everything to the right of it is greater and everything less than it is less than
  swap(arr[i + 1], arr[high]);
  return (i+1); // the index of pivot
}

void quickSort(int arr[], int low, int high){
  if (low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  
  int arr[4] = {4, 1, 8, 3};
  //low = first index, high = last index
  quickSort(arr, 0, 3);
  for (int i = 0; i < 4; i++){
    cout << arr[i] << " ";
  }  


}