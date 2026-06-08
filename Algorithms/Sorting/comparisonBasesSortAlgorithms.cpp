#include <bits/stdc++.h>
std::vector<int> bubbleSort(std::vector<int> nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
            if (nums[j] > nums[j + 1])
                std::swap(nums[j], nums[j + 1]);
    }
    return nums;
}
std::vector<int> selectionSort(std::vector<int> nums)
{

    for (int i = 0; i < nums.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < nums.size(); j++)
            if (nums[minIndex] > nums[j])
                minIndex = j;
        std::swap(nums[minIndex], nums[i]);
    }

    return nums;
}

std::vector<int> insertionSort(std::vector<int> nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--)
            std::swap(nums[j], nums[j - 1]);
    }
    return nums;
}

void merge(std::vector<int> &nums, int low, int mid, int high)
{
    std::vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
        if (nums[left] < nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);

    while (left <= mid)
        temp.push_back(nums[left++]);
    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = 0; i < temp.size(); i++)
        nums[i + low] = temp[i];
}
void mergeSort(std::vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
int pivotIndex_lomuto(std::vector<int> &nums, int low, int high)
{
    int i=low-1;
    int pivot=nums[high];
    for (int j = low; j<high; j++)
        if(nums[j]<pivot)
        {
            i++;
            std::swap(nums[i],nums[j]);
        }
        std::swap(nums[i+1], nums[high]);
        return i+1;
    
}
int pivotIndex_hoare(std::vector<int> &nums, int low, int high)
{
    int mid = low + (high - low) / 2;
    if (nums[low] > nums[mid])
        std::swap(nums[low], nums[mid]);
    if (nums[low] > nums[high])
        std::swap(nums[low], nums[high]);
    if (nums[mid] > nums[high])
        std::swap(nums[high], nums[mid]);

    
    std::swap(nums[mid],nums[low]);// moving pivot to lowest position to keep it out of the way during scan
        int pivot = nums[low];
        int i = low, j = high;
    while (i < j)
    {
        while (nums[i] <= pivot && i < high)
            i++;
        while (nums[j] > pivot && j > low)
            j--;
        if (i < j)
            std::swap(nums[i], nums[j]);
    }
    std::swap(nums[j], nums[low]);
    return j;
}
void quickSort(std::vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int pIndex = pivotIndex_hoare(nums, low, high);
    quickSort(nums, low, pIndex - 1);
    quickSort(nums, pIndex + 1, high);
}

int binarySearch(std::vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < nums[mid])
            right = mid - 1;
        else if (target > nums[mid])
            left = mid + 1;
        else 
            return mid;
    }
    return -1;
}
int main()
{
    std::vector<int> arr = {9, 6, 3, 4, 2, 1, 8, 0, 7, -1, 7869, 321, 5, -9910, -9909};
    quickSort(arr, 0, arr.size() - 1);
    for (int &x : arr)
        std::cout << x << " ";
    std::cout << "\n\n";
   // std:: cout<< std::is_sorted(arr.begin(),arr.end());
    std::cout << binarySearch(arr, -9910)<<"\n";
    return 0;
}