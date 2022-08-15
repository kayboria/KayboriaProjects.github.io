// C++ implementation of Best - Fit algorithm
#include<bits/stdc++.h>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

// Function to allocate memory to blocks as per Best fit
// algorithm
void NextWorstFit(int blockSize[], int m, int processSize[], int n, int ConstblockSize[], bool worst)
{
    // Stores block id of the block allocated to a
    // process
    int allocation[n], j = 0;

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        // Find the Worst fit block for current process
        if (worst)
        {
            int wstIdx = -1;
            for (int j=0; j<m; j++)
            {
                if (blockSize[j] >= processSize[i])
                {
                    if (wstIdx == -1)
                        wstIdx = j;
                    else if (blockSize[wstIdx] < blockSize[j])
                        wstIdx = j;
                }
            }
            if (wstIdx != -1)
            {
                // allocate block j to p[i] process
                allocation[i] = wstIdx;
    
                // Reduce available memory in this block.
                blockSize[wstIdx] -= processSize[i];
            }
        
        }else 
        {
           while (j < m) {

			if (blockSize[j] >= processSize[i]) {

				// allocate block j to p[i] process
				allocation[i] = j;

				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break;
			}

			// mod m will help in traversing the blocks from
			// starting block after we reach the end.
			j = (j + 1) % m;
		}
        }

        // If we could find a block for current process
    
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
    cout << "\n[1] Next-fit";
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

    int ConstblockSize[] = {6,5,7,10,2,6,10,5,7,2 };
    int blockSize[] = { 6,5,7,10,2,6,10,5,7, };
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

        NextWorstFit(blockSize, m, processSize, n, ConstblockSize, worst);
        cout << "Continue (y/n)? ";
        cin >> loop;
    }



    return 0;
}



