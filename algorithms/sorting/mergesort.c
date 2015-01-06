#include "mergesort.h"

void partition(int arr[],int low,int high){

	int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}

void mergeSort(int arr[],int low,int mid,int high){

	int i,m,k,l,temp[high-low];

	l=low;
	i=low;
	m=mid+1;

	/*
	Go through left and right halves and arrange them
	in the right order.
	Until left or right has reached its end.
	*/
	while((l<=mid)&&(m<=high)){

		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}
	/* Move all leftover values into temporary array */
	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=arr[k];
			i++;
		}
	}

	/* Move everything back into the original array */
	for(k=low;k<=high;k++){
		arr[k]=temp[k];
	}
}
