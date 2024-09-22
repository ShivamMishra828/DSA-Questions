class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        int s = 1, e, mid, ans;
        sort(position.begin(), position.end());
        int n = position.size();
        e = position[n - 1] - position[0];

        while (s <= e)
        {
            mid = s + (e - s) / 2;
            int count = 1, force = position[0];
            for (int i = 1; i < n; i++)
            {
                if (force + mid <= position[i])
                {
                    count++;
                    force = position[i];
                }
            }

            if (count < m)
            {
                e = mid - 1;
            }
            else
            {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
};