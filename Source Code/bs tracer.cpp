#include <iostream>
//https://replit.com/@JamesPapademas2/LemonchiffonZealousRouter
using namespace std;

// C++ code for binary search function
int binarySearch (int arr[], int size, int target)
{
  // Initialize low and high indices
  int low = 0;
  int high = size - 1;

  // Loop until low is less than or equal to high
  while (low <= high)
    {
      // Calculate the midpoint index
      int mid = (low + high) / 2;

      // Print out the current subarray and mark the midpoint with an asterisk
      cout << "Subarray: ";
      for (int i = low; i <= high; i++)
	{
	  if (i == mid)
	    {
	      cout << "*" << arr[i] << "* ";
	    }
	  else
	    {
	      cout << arr[i] << " ";
	    }
	}
      cout << endl;

      // Compare the target with the midpoint element
      if (target == arr[mid])
	{
	  // Target found, return the index
	  return mid;
	}
      else if (target < arr[mid])
	{
	  // Target is in the lower half, update high index
	  high = mid - 1;
	}
      else
	{
	  // Target is in the upper half, update low index
	  low = mid + 1;
	}
    }

  // Target not found, return -1
  return -1;
}

int main ()
{
  int a[] = { 1, 2, 3, 4, 5, 10, 11, 12, 13 };
  int len = sizeof (a) / sizeof (a[0]);	//get array length

  int result = binarySearch (a, len, 12);

  cout << (result == -1 ? "Not found" : "Found") << endl;

  return 0;
}
