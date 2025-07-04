/*Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct
Examples :
Input: nums = [1,2,3,4]
Output: false
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true*/

class Solution {
  bool containsDuplicate(List<int> nums) {
    for (int i = 0; i < nums.length - 1; i++) {
      for (int j = i + 1; j < nums.length; j++) {
        if (nums[i] == nums[j]) return true;
      }
    }
    return false;
  }
}

void main() {
  List<int> arr = [1, 2, 3, 4];
  Solution solution = Solution();

  print(solution.containsDuplicate(arr));
}
