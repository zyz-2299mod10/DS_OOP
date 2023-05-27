#include <time.h>
#include "insertion.h"
#include "quick.h"
#include "radix.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "DS-OO Program3-Demo\n";
    srand(time(NULL));

    int randnum;
    cin >> randnum;
    cout << endl;

    vector<int> nums;
    bool printflag = false;

    if (randnum <= 0) {
        nums = { 168, 179, 208, 306, 93, 859, 984, 55, 9, 271, 33 };
        printflag = true;
    }
    else {
        for (int i = 0; i < randnum; i++) {
            nums.push_back(rand() % 999 + 1);
        }
        if (randnum <= 100) printflag = true;
    }


    if (printflag) {
        cout << "Before : ";
        for (auto n : nums) {
            cout << n << ",";
        }
        cout << endl;
    }

    double START, END;
    vector<int> sort1, sort2, sort3;

    
    /* insertion sort*/
    cout << "Insertion sort" << ":\n";
    START = clock();
    insertion insertion_(nums);
    sort1 = printflag ? insertion_.sort_print() : insertion_.sort();
    END = clock();
    cout << "sorting time : " << (END - START) / CLOCKS_PER_SEC << " s\n\n\n";
    

    /*quick sort*/
    cout << "Quick sort" << ":\n";
    if (printflag) {
        cout << "Before : ";
        for (auto n : nums) {
            cout << n << ",";
        }
        cout << endl;
    }
    START = clock();
    quick quick_(nums);
    sort2 = printflag ? quick_.sort_print() : quick_.sort();
    END = clock();
    cout << "sorting time : " << (END - START) / CLOCKS_PER_SEC << " s\n";
    sort1 == sort2 ? cout << "Correct!!\n\n\n" : cout << "Wrong!!\n\n\n";


    /* radix sort*/
    cout << "Radix sort" << ":\n";
    START = clock();
    radix radix_(nums);
    sort3 = printflag ? radix_.sort_print() : radix_.sort();
    END = clock();
    cout << "sorting time : " << (END - START) / CLOCKS_PER_SEC << " s\n";
    sort1 == sort3 ? cout << "Correct!!\n\n\n" : cout << "Wrong!!\n\n";

}

