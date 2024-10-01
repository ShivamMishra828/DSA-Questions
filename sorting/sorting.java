import java.util.Arrays;

public class sorting {

    public static void bubbleSort(int arr[]) {
        for(int i = 0; i<arr.length; i++) {
            int swap = 0;
            for(int j = 1; j<arr.length-i; j++) {
                if(arr[j-1] > arr[j]) {
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    swap++;
                }
            }
            if(swap == 0) {
                System.out.println("Array is already sorted.");
                break;
            }
        }
    }

    public static void selectionSort(int arr[]) {
        for(int i = 0; i<arr.length-1; i++) {
            int minPos = i;
            for(int j = i+1; j<arr.length; j++) {
                if(arr[minPos] > arr[j]) {
                    minPos = j;
                }
            }
            int temp = arr[minPos];
            arr[minPos] = arr[i];
            arr[i] = temp;
        }
    }

    public static void insertionSort(int arr[]) {
        for(int i = 1; i<arr.length; i++) {
            int curr = arr[i];
            int prev = i-1;
            while(prev >= 0 && arr[prev] > curr) {
                arr[prev+1] = arr[prev];
                prev--;
            }
            arr[prev+1] = curr;
        }
    }

    public static void printArray(int arr[]) {
        for(int i = 0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String args[]) {
        int arr[] = {5, 4, 1, 3, 2};
        System.out.print("Array before sorting:- ");
        printArray(arr);
        System.out.println();

        /*
        bubbleSort(arr);
        System.out.print("Array after sorting:- ");
        printArray(arr);
        */

        /*
         selectionSort(arr);
         System.out.print("Array after sorting:- ");
         printArray(arr);
        */

        /*
         insertionSort(arr);
         System.out.print("Array after sorting:- ");
         printArray(arr);
        */

        // Inbuilt Sort Method
        Arrays.sort(arr);
        System.out.print("After after sorting:- ");
        printArray(arr);
    }
}
