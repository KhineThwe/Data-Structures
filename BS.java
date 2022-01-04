import java.util.Scanner;  // Import the Scanner class
//Recursive implementation of Binary Search with JAVA
public class BS {
	//return -1 if element is not present in arr && return index if element is present
    int binarySearch(int arr[],int low,int high,int key) {
    	if(high>=1) {
    	//to find the middle of array
    	int mid=(low+high)/2;
    	
    	//If the element is present in middle
    	//return middle
    	if(key==arr[mid]) {
    		return mid;
    	}
    	//If element is smaller than middle element
    	//element can present in left side of array
    	else if(key<arr[mid]) {
    		//change high to mid-1
    		return binarySearch(arr, low, mid-1, key);
    	}else {
    		//If element is greater than middle element
        	//element can present in right side of array
    		//change low to mid+1
    		return binarySearch(arr, mid+1, high, key);
    	}
    	}
       else {
    		return -1;
    	}
    
    }
	public static void main(String[] args)  {
	   BS bs=new BS();
	   Scanner sc=new Scanner(System.in);
	   System.out.print("Enter number of elements that you want to store: ");
	   //reading the number of elements 
	   int arrSize=sc.nextInt();
	   int arr[]=new int[arrSize];
	   System.out.print("Enter elements of array: ");
	   for(int i=0;i<arrSize;i++) {
		   //reading array elements from the user
		   arr[i]=sc.nextInt();//1 2 3 4 
	   }
	   for(int i=0;i<arrSize;i++) {
		   System.out.print("Elements of array are : "+arr[i]+"\n");
	   }
	   System.out.print("Enter elements that you want to search: ");
	   //reading element to search
	   int key=sc.nextInt();
	   int low=0;
	   int high=arrSize-1;
	   int result=bs.binarySearch(arr, low, high, key);
	   System.out.print(result);
	   if(result==-1) {
		   System.out.print("Element is not present in this array");
	   }else {
		   System.out.print("Element is present at index "+result);
	   }
	   
   }
}
