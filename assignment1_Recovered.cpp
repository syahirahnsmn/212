#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

void selectionSort(int S[], int n)
{
    int minId, temp, j;
    int counter=0;
    //Sorting array
    counter+=3;
    for(int i=0;i<n-1;i++){
        minId=i; //track minimum index
        counter+=1;
        counter+=3;
        for(j=i+1;j<n;j++){

            counter+=3;
            if(S[j]<S[minId]){
                minId=j; //when adjacent element is smaller, replace its index as minimum index
                counter+=1;
            }
            counter+=3;
        }
        temp=S[i];
        counter+=2;
        S[i]=S[minId]; //update current element to the front
        counter+=3;
        S[minId]=temp; //update minimum index to temp (the current element)
        counter+=2;
    counter+=4;
    }
    cout<<"\n\nPrimitive Operations: "<<counter<<endl;
}

void minmaxArr(int S[],int n,int& min, int& max)
{
    // Get the minimum and the maximum
    int counter=0;
    counter=+1;
    if (n == 1){
	    max = S[1];
	    min = S[1];
	    counter+=4;
	  }
  	else{
	    //initialize min and max if there are more than one elements
	    counter+=3;
	  	if (S[1] > S[2]){
	      	max = S[1];
	      	min = S[2];
	      	counter+=4;
		  }
	  	else{
			max = S[2];
	      	min = S[1];
	      	counter+=4;
	  	  }
        //searching the maximum number in the array
        counter+=2;
		for (int i = 3; i<n; i++){
                //counter+=2;
	    	if (S[i] > max){
	    		max = S[i];
                counter+=2;
            }
            counter+=3;
		  }

		//searching the minimum number in the array
		counter+=2;
		for (int i = 3; i<n; i++){
            counter+=2;
		  	if (S[i] <  min)
	    		min = S[i];
                counter+=2;
		  }
		  counter+=3;
      }

      cout<<"\n\nPrimitive Operations: "<<counter<<endl;
}

void readingArr(int S[], int n)
{
    int i;
    srand (time(NULL));
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
                cout<<"\n\n\t\t-THIS ALGORITHM FINDS THE MINIMUM AND THE MAXIMUM NUMBER IN THE ARRAY-\n\n"
                    <<"\n\t\tPlease insert your array size (suggested value 2000 - 12000):\n\n\t\t";
                cin>>n;
                int S[n];
                cout<<"\n\t\tRandom number generated of size " <<n<< ":\n"
                    <<"\t\t----------------------------------\n\n\t\t";
                readingArr(S, n);
                int min,max;

                 // Start time
                auto t1 = chrono::high_resolution_clock::now();
                minmaxArr(S, n, min, max);
                // Finish time
                auto t2 = chrono::high_resolution_clock::now();
                // Calculate runtime (Finish time - start time)
                double runtime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();

                cout<<"\n\n\t\tThe maximum number in this array is:"<<max;
                cout<<"\n\t\tThe minimum number in this array is:"<<min;
                cout<<endl;

                 cout << "\n\nRuntime = " << fixed << runtime/1000000000 << setprecision(7) << " seconds";

                cout<<"\n\n\t\t";

                system("pause");
                system("cls");


                break;
        }
    case 2:
        {
            /*PART 2 - SYAHIRAH*/
             cout<<"\n\n\t\t-THIS IS SORTING ALGORITHM USING SELECTION METHOD-\n\n\n"
                    <<"\nPlease insert your array size (suggested value 2000 - 12000):\n\n";
                cin>>n;

                int S[n];
                cout<<"\nRandom number generated of size " <<n<< ":\n"
                    <<"----------------------------------\n\n";
                 //read random generated number into array
                 // Start time
                auto starttime = chrono::high_resolution_clock::now();
                readingArr(S, n);
                // !!! Call your algorithm/function here !!
                selectionSort(S, n); //sorting array


                // Finish time
                auto endtime = chrono::high_resolution_clock::now();

                // Calculate runtime (Finish time - start time)
                double runtime = chrono::duration_cast<chrono::nanoseconds>(endtime - starttime).count();
                 cout<<"\n\nSorted array:\n"
                        <<"---------------------------------\n"<<endl;
                        //call function printArr

                printArr(S, n);

                cout << "\n\nRuntime = " << fixed << runtime/1000000000 << setprecision(7) << " seconds";

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
