#include "test.hpp"

#include <iostream>
#include <cstdlib>


// int read(char *buf, int n) {
//     int readChars = 4;
//     int copiedChars = 0;
//     int buf4[4];

//     while(copiedChars < n && readChars == 4) {
//         readChars = read4(buf4);

//         for(int i = 0; i < readChars; i++) {
//             if(copiedChars == n) {
//                 return copiecChars;
//             }
//             buf[copiedChars] = buf4[i];
//             copiedChars++;
//         }
//     }
//     return copiedChars;
// }

void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] < pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	
	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}

int main()
{
    int arr[] = {2, 1, 3, 6, 5, 4, 7};
    int n = 7;
	quickSort(arr, 0 , n-1);
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < n; i++){
		cout<< arr[i]<<"\t";
	}
	
}