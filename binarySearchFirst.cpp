
/*Given sorted array in decreasing order. Find first occurrence of given key.*/

#include <iostream>
using namespace std;
int findFirstOcurrence(int a[],int l,int h,int target)
{
		if(l>h)
			return -1;
		int m = l+(h-l)/2;
		if(a[m] == target) {
			if(m==0||a[m-1]>a[m])
				return m;
			else
				h = m-1;
		} else if(a[m] <target)
			h = m-1;
		else
			l = m + 1;
		return findFirstOcurrence(a,l,h,target);
	
	
}
int main() {
	// your code goes here
	int arr[12] = {10,9,9,9};
	cout<<findFirstOcurrence(arr,0,1,9);
	return 0;
}
