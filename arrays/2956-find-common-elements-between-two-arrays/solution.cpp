class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        int firstArrCount = 0;
        int secondArrCount = 0;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    firstArrCount++;
                    break;
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = 0; j < nums1.size(); j++)
            {
                if (nums2[i] == nums1[j])
                {
                    secondArrCount++;
                    break;
                }
            }
        }

        ans.push_back(firstArrCount);
        ans.push_back(secondArrCount);

        return ans;
    }
};