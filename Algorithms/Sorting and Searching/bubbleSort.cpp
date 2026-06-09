#include <bits/stdc++.h>
#define endl char(10)

using namespace std;

typedef long long ll;

vector<int> bubbleSort(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool didSwap = 0; // optimizing
        for (int j = 0; j < n - 1 - i; j++)
            if (nums[j] > nums[j + 1])
            {
                didSwap = 1;
                swap(nums[j], nums[j + 1]);
            }
        cout<<"runs\n";
        if (!didSwap)
            break;
        
    }
    return nums;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> ans = bubbleSort({1,2,3,4,5,6,7});
    for (int x : ans)
        cout << x << " ";

    return 0;
}