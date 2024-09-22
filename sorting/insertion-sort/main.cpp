class Solution
{
public:
    // Function to sort the array using Insertion Sort
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        // Iterate through the array starting from the second element
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i]; // Store current element
            int j = i - 1;      // Initialize index for comparison

            // Shift elements greater than temp to the right
            for (; j >= 0; j--)
            {
                if (nums[j] > temp)
                {
                    nums[j + 1] = nums[j]; // Shift element
                }
                else
                {
                    break; // Found correct position for temp
                }
            }

            // Insert temp at its correct position
            nums[j + 1] = temp;
        }

        return nums;
    }
};