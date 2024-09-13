class Solution
{
public:
    int findPivot(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int n = nums.size();
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (s == e)
            {
                return s;
            }

            if (mid + 1 < n && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
            {
                return mid - 1;
            }
            else if (nums[s] <= nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }

    int binarySearch(vector<int> &nums, int s, int e, int target)
    {
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int pivotIndex = findPivot(nums);
        int ans = -1;

        if (target >= nums[0] && target <= nums[pivotIndex])
        {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else
        {
            ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
        }
        return ans;
    }
};