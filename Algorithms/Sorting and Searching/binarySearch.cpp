#include <bits/stdc++.h>
#define endl char(10)

using namespace std;

typedef long long ll;

int binarySearch(vector<int> a, int target)
{
    int left = 0;
    int right = a.size() - 1;
    int mid;
    // int ans = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (target < a[mid])
            right = mid - 1;
        else if (target > a[mid])
            left = mid + 1;
        else if (target == a[mid])
        {
            return mid;
            // ans = mid;
            // right = mid - 1; //lower bound if duplicate exists
            // left=mid+1      //upper bound index if duplicate exists
        }
    }
    return -1;
}

// int countOccurrences(vector<int> &a,int n)
// {
//     int lb=binarySearch(a,n);
//     if(lb==-1) return 0;
//     int ub=binarySearch(a,n);
//     return lb+ub-1;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 11, 17, 19, 25, 26, 27, 29, 35, 55, 56, 57, 58, 59};

    int index = binarySearch(arr, 4);//if there are repeating elements, binary search returns lower bound index by default
    cout << index << "\n";

    // std::cout<<"Number of Occurrences of 4 in array: "<<countOccurrences(arr,4);

    return 0;
}