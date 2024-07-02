#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int l = start;
    int r = end;
    int x = nums[start];
    while (start < end)
    {
        while (start < end && nums[end] > x)
        {
            end--;
        }
        nums[start] = nums[end];
        while (start < end && nums[start] <= x)
        {
            start++;
        }
        nums[end] = nums[start];
    }
    nums[start] = x;
    quicksort(nums, l, start - 1);
    quicksort(nums, start + 1, r);
    return;
}

int main()
{
    vector<int> nums = {1, 2, 5, 4, 7, 8, 4, 5, 6, 3, 2, 5, 6, 9, 8, 5, 6, 4, 1, 2, 3, 5, 4, 1, 2, 5, 6, 3, 2};
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    quicksort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}