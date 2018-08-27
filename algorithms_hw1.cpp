//Frederick Chute 2016
//Computer Algorithms HW 1


#include <iostream>
#include<stdio.h>
#include <time.h>
#include <math.h>

using namespace std;

void merge(int* A, int p, int q, int r);
															//function prototype
															//is called in merge_Sort


void merge_Sort(int* A,  int p, int r)
															//A is the array to be sorted, p is the smallest element being sorted,
															//initially 0, and r is the largest element to be sorted, initially size-1
{
	if (p < r)
															//If p=r then the first and last elements are equal and the recursion stops

	{
		int q=   (p+r)/2;
															//q is in the middle of p and r, floor function is unnecessary
															//because of integer division
		merge_Sort(A, p, q);
		merge_Sort(A, q+1, r);
															//The function divides the sum of integers its passed in half
															//and then sends those halves to itself until it is left with
															//1-item sequences

		merge(A, p, q, r);
															//puts together 1-item sequences, then 2 item sequences, etc
															//till two n/2 sequences are put together and the n element array
															//is sorted.

	}
	else
	return;
}


void merge(int* A, int p, int q, int r)
															//This array starts by merging single elements into sorted arrays
															//and then sorts two element arrays till the entire array passed
															//to merge sort has been sorted

{
	int n1 = q-p+1;											//length from p to q
	int n2 = r-q;											//length from q+1 to r

	int* L= NULL;
	int* R= NULL;
															//pointers to contain dynamic arrays
	L = new int[n1+1];
	R = new int[n2+1];
															//uses new operaetor to declare dynamic arrays of sizes n1+1 and n2+1
															//the +1 is so they can contain sentinel values

	for (int i=0; i<n1; i++)
	{
		L[i]= A[p+i];
	}
															//Fills L[] with the p to q elements of A[]

	for (int j=0; j<n2; j++)
	{
		R[j]= A[q+j+1];
	}
															//Fills R[] with the q+1 to r elements of A[]

	L[n1]=999999;

	R[n2]=999999;
															//arbitrary sentinel values
	int i=0;

	int j=0;
															//increments to keep track of L[] and R[]
	for (int k=p; k<r+1; k++)
															//iterates the value of k from p to r, the length to be sorted
															//after which only the sentinel values will remain
	{

		if (L[i]<=R[j])
		{
			A[k]=L[i];
															//A[] points to the original array which needs to be sorted
			i= i+1;
		}
															//sets A[k] to L[i] and then increments i, so that if the loop hasn't ended
															//then L[i+1] will be compared to R[i]

		else
		{
			A[k]=R[j];

			j= j+1;
		}
															//Sets A[k] to R[j] if R[j]> L[i], then increments j so that the next
															//element of R[] will be compared again to L[i] if the loop hasn't
															//finished already.
	}


	delete [] L;
	delete [] R;
															//Delete these to free space back up again.
	return;

}


void insertion_(int* A, int r)								//uses insertion sort to sort r elements in A
{
															//insertion sort algorithm
															//j is set to 1 because that is the second element of the array
		for (int j=1; j<r; j++)
	{
		int key = A[j];										//put element j of A[] into key variable, which will be compared to the sorted
															//elements that come before it, initially only one element is before it so it is sorted.



		 int i=j-1;
															//A[i] will be the element before A[j]
															//on the first loop A[i] will be the first element in A[]

		while (i >= 0 && A[i] > key)
															//if i is -1 then then key is the smallest element of the array so far so it will be placed
															//in the first(0) position, and this iteration of the while loop is complete.
															//if A[i]<= key then the element is already sorted
		{
			A[i+1] = A [i];									//moves the ith element up since it's bigger

			i--;
															//decrements i to continue iterating the while loop until

		}

		A[i+1] = key;
															//The last iteration of the while loop occurred at i+1 so this is where key needs
															//to be placed to be properly sorted
	}


	return;
}



void get_Input (int* A, int r)
															//puts input into array
															//A will contain input, r is number of integers to be input
{
	if (r<=20)
															//Users input their own integers if the size of array is <=20
	{
		for (int i=0; i<r; i++)
		{
			cin >> A[i];									//fills array with input from user
		}
	}

	else
		for (int i=0; i<r; i++)
	{

		A[i] = r-i;
															//fills array of size r in reverse sort, used for large(>20 element) arrays
															//A[0]=r, A[r]=1
	}


	return;
}


void print_Array (int *A,int r)
															//prints array
															//A is array to be printed, r is amount of elements in array
{
	if (r<=100)
															//Don't bother printing arrays greater than 100
	{

		for (int i=0; i<r; i++)
			{
				cout << A[i] << " ";
			}

		cout << endl;

	return;
	}

	else
		cout << "has greater than 100 elements so it is not being printed" << endl;
		return;
}

void copy_Input (int* A, int* B, int r)
															//Just puts values from the first array into the second array
{
	for (int i=0; i<r; i++)
	{
		B[i] = A[i];
	}
}

int main()
{

    int* input_Insertion = NULL;
	int* input_Merge = NULL;
															//pointers to hold the value of array containing input, for insertion




    int size;
															//variable to contain the amount of integers to sort

	cout << "Enter amount of integers to be sorted: ";
															//get size of array to be sorted from user input

    cin >> size;

    input_Insertion = new int[size];
	input_Merge = new int[size];
															//These will point to an array with size elements



	cout <<"Enter integers to be sorted: " <<endl;

	get_Input(input_Insertion,size);
															//fills input_ with size values, takes user input for <=20 size arrays
															//fills arrays in reverse sort order if size is greater>20


	cout <<"Integers to be sorted: ";

	print_Array (input_Insertion,size);
															//prints the size elements in array input_ to be sorted.  Used to print
															//small arrays, printing is skipped when sorting large(>100) arrays

	copy_Input (input_Insertion, input_Merge, size);
															//places the values of input_Insertion into input_Merge

	clock_t start_Insertion, end_Insertion;
	clock_t start_Merge, end_Merge;
															//start_Insertion will hold the time insertion sort started,
															//end_Time when it ended. Same for start_Merge and end_Merge
    double insertion_Time, merge_Time;
															//insertion_Time will contain the length of time insertion sort took
															//same for merge_Time.

	start_Insertion = clock();
															//take the time at the start of the insertion sort


	insertion_(input_Insertion,size);
															//uses insertion sort to sort the array of size size pointed to by
															//input_Insertion

	end_Insertion = clock();
															//take the time when insertion sort ended

    insertion_Time = (start_Insertion - end_Insertion) / CLOCKS_PER_SEC;
															//calculates length of time insertion sort took and places it in insertion_Time


	cout << "Time to insertion sort "<< size << " integers : ";
	cout << insertion_Time << " seconds."<< endl;
															//outputs length of time insertion sort took

	cout << "Insertion sorted integers: ";
	print_Array (input_Insertion,size);
															//prints insertion sorted array, skipped when sorting large (>100) arrays

	start_Merge = clock();
															//holds the time when merge_Sort is starting
	merge_Sort(input_Merge,0, size-1);
															//A[0] is the first element of the array to be sorted
															//so 0 is sent as P, A[size-1] is the last element of the array so
															//size-1 is sent as r

	end_Merge = clock();
															//holds the time when merge_Sort finished

	merge_Time = (start_Merge - end_Merge) / CLOCKS_PER_SEC;
															//calculates length of time merge sort took and places it in merge_Time

	cout << "Time taken to merge sort " << size << "integers : ";
	cout << merge_Time << " seconds." <<endl;
															//outputs the length of time merge sort took

	cout << "Merge sorted intgers: ";

	print_Array (input_Merge,size);
															//prints the merge sorted array, unless its greater than 100 elements
															//in which case printing is skipped

	delete [] input_Insertion;

	delete [] input_Merge;
															//We're done with these so free up the space


	system("PAUSE");										//pause to view program output
	return 0;												//end main function, end program
}
