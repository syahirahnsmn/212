#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void selectionSort(int S[], int n)
{
    int minId, temp, j;

    //Sorting array
    for(int i=1;i<=n;i++){
        minId=i; //track minimum index
        for(j=i+1;j<n+1;j++){
            if(S[j]<S[minId]){
                minId=j; //when adjacent element is smaller, replace its index as minimum index
            }

        }
        temp=S[i];
        S[i]=S[minId]; //update current element to the front
        S[minId]=temp; //update minimum index to temp (the current
    }
}

void readingArr(int S[], int n)
{
    int i;
    for (i=1;i<=n;i++){
        S[i] = 1+ rand() % 100; //insert random number into array
        if(i<n)
            cout<<S[i]<<", ";
        else
            cout<<S[i]<<". ";
    }
}
void printArr(int S[], int n)
{
    for (int i=1;i<=n;i++){
        if(i<n)
            cout<<S[i]<<", ";
        else
            cout<<S[i]<<". ";
    }
}

void calcRunTime()
{
    // Start time
    auto t1 = chrono::high_resolution_clock::now();

    // !!! Call your algorithm/function here !!!

    // Finish time
    auto t2 = chrono::high_resolution_clock::now();

    // Calculate runtime (Finish time - start time)
    auto runtime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();

    cout << "Runtime = " << runtime;
}

int main()
{
    int i, n;
    int menu1, menu2;

    while(menu1!=3)
    {
        cout<<"\n\n\t\tMENU:\n\n"
            <<"\t\t1 - Experimental\n\n"
            <<"\t\t2 - Theoretical\n\n"
            <<"\t\t3 - Exit\n\n"
            <<"\t\t";
        cin>>menu1;
        cout<<"\n\n\t\t";
        system("pause");
        system("cls");

        switch(menu1)
        {
        case 1:
            cout<<"\n\n\t\tWHICH ALGORITHM WOULD YOU WANT TO RUN?\n\n"
                <<"\t\t1 - O(n)\n\n"
                <<"\t\t2 - O(n^2)\n\n"
                <<"\t\t";
            cin>>menu2;
            cout<<"\n\n\t\t";
            system("pause");
            system("cls");

            if(menu2 == 1){
                    /*PART 1 - HAJAR*/
            }

            else if(menu2 == 2){
                cout<<"\n\n\t\tTHIS IS SORTING ALGORITHM USING INSERTION METHOD\n\n"
                    <<"\n\t\tPlease insert your array size (suggested value 1000 - 10000):\n\n\t\t";
                cin>>n;

                int S[n];
                cout<<"\n\t\tRandom number generated of size " <<n<< ":\n"
                    <<"\t\t----------------------------------\n\n\t\t";

                 // Start time
                auto t1 = chrono::high_resolution_clock::now();

                // !!! Call your algorithm/function here !!!
                readingArr(S, n); //read random generated number into array
                selectionSort(S, n); //sorting array
                    cout<<"\n\n\t\tSorted array:\n"
                        <<"\t\t----------------------------------\n\t\t"<<endl;
                    cout<<"\t\t";
                    //call function printArr
                    printArr(S, n);

                // Finish time
                auto t2 = chrono::high_resolution_clock::now();

                // Calculate runtime (Finish time - start time)
                auto runtime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();


                cout << "\n\nRuntime = " << runtime;

                cout<<"\n\n\t\t";

                system("pause");
                system("cls");

                cout<<endl;
            }
        break;

        default:
            break;
        }
    }

    return 0;
}

