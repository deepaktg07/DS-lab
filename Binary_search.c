#include<stdio.h>
int binarysearch(int arr[],int x,int low,int high) 
{
	if(high>=low)   
	{
		int mid=low+(high-low)/2; 
		if(arr[mid]==x)  
			return mid;  //if element=arr[mid] element if found at mid
		else if(arr[mid]>x)  
			return binarysearch(arr,x,low,mid-1);  // if element is less than mid value seacrh element from low to mid-1
		else 
			return binarysearch(arr,x,mid+1,high); //else search element from mid+1 to high
	}
	return -1; 
}

int main(void)  

{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; //initializing array 
	int n=sizeof(arr)/sizeof(arr[0]); //to find size of the array
	int x;
	printf("Enter value between 1 to 15:");
	scanf("%d",&x);         //reading x value
	int result=binarysearch(arr,x,0,n-1); //low=0 high=n-1
	if(result==-1)
		printf("Value not found"); //if element is not found
	else
		printf("Required value is found at  %d",result); //print the index of the array where the element is found

}
