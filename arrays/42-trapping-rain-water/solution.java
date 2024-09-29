class Solution {

    public static void findLeftMax(int arr[], int lMaxArr[]) {
            int max = arr[0];
            lMaxArr[0] = arr[0];
            for(int i = 1; i<arr.length; i++) {
                if(arr[i] > max) {
                    lMaxArr[i] = arr[i];
                    max = arr[i];
                }
                else {
                    lMaxArr[i] = max;
                }
            }
        }
    
        public static void findRightMax(int arr[], int rMaxArr[]) {
            int max = arr[arr.length-1];
            rMaxArr[arr.length-1] = arr[arr.length-1];
            for(int i = arr.length-2; i>=0; i--) {
                if(arr[i] > max) {
                    rMaxArr[i] = arr[i];
                    max = arr[i];
                }
                else {
                    rMaxArr[i] = max;
                }
            }
        }
    
        public int trap(int[] arr) {
            int lMaxArr[] = new int[arr.length];
            int rMaxArr[] = new int[arr.length];
            findLeftMax(arr, lMaxArr);
            findRightMax(arr, rMaxArr);
            int waterArray[] = new int[arr.length];
            for(int i = 0; i<waterArray.length; i++) {
                waterArray[i] = Math.min(lMaxArr[i], rMaxArr[i]);
            }
    
            int trappedWater = 0;
            if(waterArray.length <= 2) {
                return trappedWater;
            }
    
            for(int i = 0; i<arr.length; i++) {
                trappedWater += (waterArray[i] - arr[i]);
            }
            return trappedWater;
        }
    }