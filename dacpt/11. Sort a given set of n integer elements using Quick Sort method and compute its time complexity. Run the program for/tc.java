/*  Sort a given set of n integer elements using Quick Sort method and compute its time complexity. Run the program for
varied values of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus non graph sheet. The
elements can be read from a file or can be generated using the random number generator. Demonstrate using Java how the
divide and- conquer method works along with its time complexity analysis: worst case, average case and best case*/

import java.io.*;

class QuickSort
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the number of elements");
		int n=Integer.parseInt(br.readLine());
		int a[]=new int[n];
		System.out.println("Enter the elements");
		for(int i=0;i<n;i++)
		{
			a[i]=Integer.parseInt(br.readLine());
		}
		System.out.println("The unsorted elements are");
		for(int i=0;i<n;i++)
		{
			System.out.println(a[i]);
		}
		QuickSort ob=new QuickSort();
		ob.sort(a,0,n-1);
		System.out.println("The sorted elements are");
		for(int i=0;i<n;i++)
		{
			System.out.println(a[i]);
		}
	}
	void sort(int a[],int l,int r)
	{
		if(l<r)
		{
			int pi=partition(a,l,r);
			sort(a,l,pi-1);
			sort(a,pi+1,r);
		}
	}
	int partition(int a[],int l,int r)
	{
		int pivot=a[r];
		int i=l-1;
		for(int j=l;j<r;j++)
		{
			if(a[j]<=pivot)
			{
				i++;
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		int temp=a[i+1];
		a[i+1]=a[r];
		a[r]=temp;
		return i+1;
	}
}
