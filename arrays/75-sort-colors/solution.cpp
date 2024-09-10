class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i = 0;
        int j = arr.size()-1;
        int index = 0;

        while(index <= j) {
            if(arr[index] == 0) {
                swap(arr[index], arr[i]);
                index++;
                i++;
            }
            else if(arr[index] == 2) {
                swap(arr[index], arr[j]);
                j--;
            }
            else {
                index++;
            }
        }
    }
};