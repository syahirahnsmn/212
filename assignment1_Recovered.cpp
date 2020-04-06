#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void selectionSort(int S[], int n)
{
    int minId, temp, j;
    int counter=0;
    //Sorting array
    counter=2;
    for(int i=0;i<n-1;i++){
        counter+=3;
        minId=i; //track minimum index
        counter+=1;
        counter+=3;
        for(j=i+1;j<n;j++){
            counter+=3;
            counter+=3;
            if(S[j]<S[minId]){
                minId=j; //when adjacent element is smaller, replace its index as minimum index
                counter+=1;
            }

        }
        temp=S[i];
        counter+=2;
        S[i]=S[minId]; //update current element to the front
        counter+=3;
        S[minId]=temp; //update minimum index to temp (the current element)
        counter+=2;

    }
    cout<<"\n\nPrimitive Operations: "<<counter<<endl;
}

void minmaxArr(int S[],int n)
{
	int max , min;

    // Get the minimum and the maximum
    if (n == 1)
	  {
	    max = S[1];
	    min = S[1];
	  }
  	else
  	  {
	    //initialize min and max if there are more than one elements
	  	if (S[1] > S[2])
		  {
	      	max = S[1];
	      	min = S[2];
		  }
	  	else
		  {
			max = S[2];
	      	min = S[1];
	  	  }

		//searching the maximum number in the array
		for (int i = 3; i<n; i++)
		  {
	    	if (S[i] > max)
	    		max = S[i];
		  }

		//searching the minimum number in the array
		for (int i = 3; i<n; i++)
		  {
		  	if (S[i] <  min)
	    		min = S[i];
		  }

      }
      cout<<"\nThe maximum number in this array is:"<<max;
      cout<<"\nThe minimum number in this array is:"<<min;
      cout<<endl;

}
void readingArr(int S[], int n)
{
    int i;
    for (i=0;i<n;i++){
        S[i] = 1+ rand() % 100; //insert random number into array
            cout<<S[i]<<" ";
    }
}
void printArr(int S[], int n)
{
    for (int i=0;i<n;i++){
            cout<<S[i]<<" ";
    }
}


int main()
{
    int i, n;
    int menu;

    cout<<"\n\n\t\t-ALGORITHM ANALYSIS BY EXPERIMENTAL & THEORETICAL METHOD-\n\n"
            <<"\n\n\t\tMENU:\n\n"
            <<"\t\t1 - O(n)\n\n"
            <<"\t\t2 - O(n^2)\n\n"
            <<"\t\t3 - Exit\n\n"
            <<"\t\t";
        cin>>menu;
        cout<<"\n\n\t\t";
        system("pause");
        system("cls");
    switch(menu)
    {
    case 1:
        {
            /*PART 1 - HAJAR*/
                cout<<"\n\nTHIS ALGORITHM IS TO FIND THE MINIMUM AND THE MAXIMUM NUMBER IN THE ARRAY\n\n"
                    <<"\nPlease insert your array size (suggested value 1000 - 10000):\n\n\t\t";
                cin>>n;
                int S[n];
                cout<<"\nRandom number generated of size " <<n<< ":\n"
                    <<"----------------------------------\n\n";


                // Start time
                auto t1 = chrono::high_resolution_clock::now();
                readingArr(S, n); //read random generated number into array
                minmaxArr(S, n);
                // Finish time
                auto t2 = chrono::high_resolution_clock::now();

                // Calculate runtime (Finish time - start time)
                auto runtime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();

                cout << "\n\nRuntime = " << runtime << " nanoseconds";
                cout<<"\n\n\t\t";
                system("pause");
                system("cls");
                break;
        }
    case 2:
        {
            /*PART 2 - SYAHIRAH*/
             cout<<"\n\n\t\t-THIS IS SORTING ALGORITHM USING SELECTION METHOD-\n\n\n"
                    <<"\nPlease insert your array size (suggested value 1000 - 10000):\n\n";
                cin>>n;

                int S[n];
                cout<<"\nRandom number generated of size " <<n<< ":\n"
                    <<"----------------------------------\n\n";
                readingArr(S, n); //read random generated number into array
                 // Start time
                auto t1 = chrono::high_resolution_clock::now();

                // !!! Call your algorithm/function here !!
                selectionSort(S, n); //sorting array

                    cout<<"\n\nSorted array:\n"
                        <<"---------------------------------\n"<<endl;
                        //call function printArr
                    printArr(S, n);

                // Finish time
                auto t2 = chrono::high_resolution_clock::now();

                // Calculate runtime (Finish time - start time)
                auto runtime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();


                cout << "\n\nRuntime = " << runtime << " nanoseconds";

                cout<<"\n\n\t\t";

                system("pause");
                system("cls");

                cout<<endl;
                break;
        }
        case 3:
            break;
       default:
        break;
    }

    return 0;
}
