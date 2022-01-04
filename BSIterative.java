import java.util.Scanner;  // Import the Scanner class
//Iterative implementation of Binary Search with JAVA
public class BSIterative {
	//return -1 if element is not present in arr && return index if element is present
    int binarySearchIterative(int arr[],int key) {
    	int low=0;
    	int high=arr.length-1;
    	while(low<=high) {
    	//to find the middle of array
    	int mid=(low+high)/2;
    	
    	//If the element is present in middle
    	//return middle
    	if(arr[mid]==key) {
    		return mid;
    	}
    	//If element is smaller than middle element
    	//element can present in left side of array
    	else if(key<arr[mid]) {
    		//change high to mid-1
    		high=mid-1;
    	}else {
    		//If element is greater than middle element
        	//element can present in right side of array
    		//change low to mid+1
    		low=mid+1;
    	}
    	}
    	return -1;
    }
	public static void main(String[] args)  {
	   BSIterative bs=new BSIterative();
	   Scanner sc=new Scanner(System.in);
	   System.out.print("Enter number of elements that you want to store: ");
	   //reading the number of elements 
	   int arrSize=sc.nextInt();
	   int arr[]=new int[arrSize];
	   System.out.print("Enter elements of array: ");
	   for(int i=0;i<arrSize;i++) {
		   //reading array elements from the user
		   arr[i]=sc.nextInt();
	   }
	   System.out.print("Enter elements that you want to search: ");
	   //reading element to search
	   int key=sc.nextInt();
	   int result=bs.binarySearchIterative(arr,key);
	   if(result==-1) {
		   System.out.print("Element is not present in this array");
	   }else {
		   System.out.print("Element is present at index "+result);
	   }
	}
}
