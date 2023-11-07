#include <iostream> 

using namespace std; 

int findMissing(int arr[], int N) 
{ 
	int left = 0, right = N - 1; 
	while (left <= right) { 

		int mid = (left + right) / 2; 

		// If the middle element is not on
		// the middle index, then the missing element is mid + 1.
		if (arr[mid] != mid + 1 && arr[mid - 1] == mid) 
		{
            return mid + 1;          
        }

		// This case means that the missing element is
		// not to the left. So search the right.	
		if (arr[mid] == mid + 1) 
			left = mid + 1; 

		// This case means that the missing element is not
		// to the right. So search the left.
		else
			right = mid - 1; 
	} 

	// Will reach here if no missing element found.  
	return -1; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1,2,3,4,6,7,8}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	cout << "The missing element is: " << findMissing(arr, size); 
	return 0; 

}