class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        if (days > weights.size())
        {
            return -1;
        }
        int s = 0, e = 0, mid = 0, ans = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++)
        {
            s = max(s, weights[i]);
            e += weights[i];
        }

        while (s <= e)
        {
            mid = s + (e - s) / 2;
            int pages = 0, count = 1;
            for (int i = 0; i < n; i++)
            {
                pages += weights[i];
                if (pages > mid)
                {
                    count++;
                    pages = weights[i];
                }
            }

            if (count <= days)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};