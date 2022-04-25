// Merge Sorted Array



/*


ou are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. To accommodate this, 
nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.





Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.



Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].




Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

*







// With comments
// without any extra space

#include <iostream>
#include <vector>



using namespace std;
int main() {

  vector<int> nums1  = {1,2,3,0,0,0};
  int m =3;
  vector<int> nums2  = {2,5,6};
  int n=3;

  int arr1pointer = 0, arr2pointer = 0, findex=0;
        
  while(arr1pointer < m){
      cout << "Comparing arr1pointer vallue, array2pointer value    " << nums1[arr1pointer] <<" " << nums2[arr2pointer] << "\n"<<endl;
      if(nums1[arr1pointer] <= nums2[arr2pointer]){
          nums1[findex] = nums1[arr1pointer];
          ++findex;
          ++arr1pointer;
      }else{
          int temp = nums2[arr2pointer];
          nums2[arr2pointer] = nums1[findex];
          nums1[findex] = temp;
          ++findex;
          ++arr1pointer;
      }
    cout << "Updated nums1 array : " ;
    for(auto x:nums1){
      cout << x << " ";
    }
    cout << "\n\n";

    cout << "Updated nums2 array : " ;
    for(auto x:nums2){
      cout << x << " ";
    }
    cout << "\n\n";
    

    
    cout << "Array1 pointer and array2pointer     " << arr1pointer << " " << arr2pointer << "\n\n\n\n"<<endl;
  }
  
  // num2 is already sorted so just add the rest number in nums1
  while(arr2pointer < n){
      nums1[findex] = nums2[arr2pointer];
      ++findex;
      ++arr2pointer;
  }
  
  cout << "nums1 = ";
  for(int i=0; i<m+n; i++){
    cout << nums1[i] << " ";
  }
  cout << "\n\n\n\n\n";
}
