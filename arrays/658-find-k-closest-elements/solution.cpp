class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int i = 0;
        int j = arr.size() - 1;
        vector<int> ans;
        while (j - i >= k)
        {
            if ((x - arr[i]) > (arr[j] - x))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        for (int m = i; m <= j; m++)
        {
            ans.push_back(arr[m]);
        }

        return ans;
    }
};