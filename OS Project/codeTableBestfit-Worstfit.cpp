// C++ implementation of Best - Fit algorithm
#include<bits/stdc++.h>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

// Function to allocate memory to blocks as per Best fit
// algorithm
void bestFit(int blockSize[], int m, int processSize[], int n, int ConstblockSize[], bool worst)
{
    // Stores block id of the block allocated to a
    // process
    int allocation[n];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
         for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                if (worst == true)
                {
                    if (blockSize[bestIdx] <= blockSize[j])
                        bestIdx = j;
                } else
                    if (blockSize[bestIdx] >= blockSize[j])
                        bestIdx = j;
            }
        }

        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\n<<< [Menu of Tables] >>>\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Table" << (i + 1) << " " << ConstblockSize[i] << " Seats.";
        cout << endl;
    }

    cout << right << setw(100) << "\n<<< [Reserved Tables] >>>\n\n";
    cout << "\nReservation #.\tPeople Booked\tTable No.\tSeats Available\n";
    for (int i = 0; i < n; i++)
    {
        if (processSize[i] == 0)
        {
            continue;
        }
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";

        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";

        cout << "\t\t" << ConstblockSize[allocation[i]];
        cout << endl;


    }
}


void BANNER(int& c)
{
    cout << "\n\n<<< [Table Reservation System] >>>\n\n";
    cout << "\n[1] Best-fit";
    cout << "\n[2] Worst-fit ";

    cout << "\n\nSelect: ";
    cin >> c;






}

// Driver code
int main()
{
    int c;
    char loop = 'y';
    bool worst = false;

    BANNER(c);

    if (c == 2)
    {
        worst = true;
    }

    int ConstblockSize[] = { 5, 2,5 };
    int blockSize[] = { 5, 2,5 };
    int processSize[] = { 0,0,0,0,0,0,0,0,0,0 };
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    int reserno;
    while (loop == 'y' || loop == 'Y')
    {
        cout << "\nHow Many reservations: ";
        cin >> reserno;
        for (int i = 0; i < reserno; i++)
        {

            cout << "[ #" << (i + 1) << " ]" << "Enter Number of People: ";
            cin >> processSize[i];
        }

        bestFit(blockSize, m, processSize, n, ConstblockSize, worst);
        cout << "Continue (y/n)? ";
        cin >> loop;
    }



    return 0;
}



