#include <SortingAlgorithm.hpp>
#include <vector>
#include <chrono>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace SortLibrary;

int main(int argc, char *argv[])
{
    vector<int> vectorNumber;

    for(int i = 0; i < argc; i++)
    {
         vectorNumber.push_back(atoi(argv[i])); // si memorizza dalla command-line
    }

    vectorNumber.erase(vectorNumber.begin()); // voglio solo dall'argomento 2 in poi

    double meanTimeElapsedMS = 0;
    double meanTimeElapsedBS = 0;

    for(int i = 0; i < vectorNumber.size(); i++)
    {
        int actualSize = vectorNumber[i];

        vector<int> v1(actualSize);
        vector<int> v2(actualSize);


        for(unsigned int j=0; j<actualSize; j++)
        {
            int val = rand() % 10000; //genero numeri casuali da 0 a 10000
            v1[j] = val;
            v2[j] = val;
        }

        //codice per calcolo tempi
        chrono::steady_clock::time_point MergeSort_begin = chrono::steady_clock::now();
        MergeSort(v1);
        chrono::steady_clock::time_point MergeSort_end = chrono::steady_clock::now();

        chrono::steady_clock::time_point BubbleSort_begin = chrono::steady_clock::now();
        BubbleSort(v2);
        chrono::steady_clock::time_point BubbleSort_end = chrono::steady_clock::now();

        double timeElapsedMS = chrono::duration_cast<chrono::microseconds>(MergeSort_end-MergeSort_begin).count();
        double timeElapsedBS = chrono::duration_cast<chrono::microseconds>(BubbleSort_end-BubbleSort_begin).count();

        meanTimeElapsedMS += timeElapsedMS;
        meanTimeElapsedBS += timeElapsedBS;
    }

    meanTimeElapsedMS /= vectorNumber.size();
    meanTimeElapsedBS /= vectorNumber.size();

    cout << "Il tempo medio per il MergeSort è pari a : " << meanTimeElapsedMS << endl;
    cout << "Il tempo medio per il BubbleSort è pari a : " << meanTimeElapsedBS << endl;

    cout << "\n" << "Si nota come per vettori piccoli il BubbleSort è più veloce mentre"
            " per vettori di dimensione maggiore il MergeSort è notevolmente più efficiente" << endl;

    return 0;
}
