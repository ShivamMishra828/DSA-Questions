class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> brr;
        sort(arr.begin(), arr.end());

        int count = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                count++;
            }
            else
            {
                brr.push_back(count);
                count = 1;
            }
        }
        brr.push_back(count);

        sort(brr.begin(), brr.end());

        for (int i = 0; i < brr.size() - 1; i++)
        {
            if (brr[i] == brr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};