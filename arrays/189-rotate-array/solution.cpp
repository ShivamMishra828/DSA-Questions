class Solution
{
public:
    void rotate(vector<int> &arr, int key)
    {
        int size = arr.size();
        vector<int> ans(size);
        for (int index = 0; index < size; index++)
        {
            int newIndex = (index + key) % size;
            ans[newIndex] = arr[index];
        }

        arr = ans;
    }
};