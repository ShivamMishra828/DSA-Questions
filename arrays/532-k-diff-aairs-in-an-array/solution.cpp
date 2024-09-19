class Solution
{
public:
    bool binarySearch(int s, int e, int target, vector<int> &nums)
    {
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                return true;
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
        return false;
    }

    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int ans = 0;

        while (i < nums.size() - 1)
        {
            int target = k + nums[i];
            if (binarySearch(i + 1, nums.size() - 1, target, nums))
            {
                ans++;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
            i++;
        }
        return ans;
    }
};