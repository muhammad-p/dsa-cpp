#include<iostream>
#include<vector>
void insertionSort(std::vector<int> &nums, int low, int high)
{
    if(low>=high) 
        return;
    for(int i=low+1; i>0 && nums[i]<nums[i-1];i--)
        std::swap(nums[i],nums[i-1]);
    insertionSort(nums, low+1, high);
}
int main()
{
    std::vector<int> nums = {0, 11, 982, 33, 1, -212, 212, 22, 3, 1, 0, 1, 2};
    insertionSort(nums, 0, nums.size() - 1);
    for (int x : nums)
        std::cout << x << " ";
    return 0;
}