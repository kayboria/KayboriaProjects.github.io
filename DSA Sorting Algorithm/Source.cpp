#include <iostream>

#include <fstream>

#include <iomanip>

#include <string>

/*
Abdulaziz Tawfik Othman	A20EC4004
Abdullah Mohammed Moqbel	A20EC4006
Husam Hasan Rageh	A20EC4026
Mohammed Adham Mohammed Nooraldeen Tawfik	A20EC4040
Completion Date: 12/5/2021 5:36PM
*/

using namespace std;

/*_-_-_-__-_-_-_-_-_{GYM MEMBERS}-_-_-_-_-_-_-_-_-*/
struct Gymnastic {

    string Name;
    float Weight;
    float Length;
    string bodyShape;
    int mms;
    string gender;

};

int binary_search(int search_key, int array_size,
    const int array[]) {
    bool found = false;
    int index = -1; //-1 means record not found
    int MIDDLE, LEFT = 0, RIGHT = array_size - 1;
    while ((LEFT <= RIGHT) && (!found)) {
        MIDDLE = (LEFT + RIGHT) / 2; // Get middle index
        if (array[MIDDLE] == search_key) {
            index = MIDDLE;
            found = true;
        }
        else if (array[MIDDLE] > search_key)

            RIGHT = MIDDLE - 1; // search is focused
          // on the left side of list
        else
            LEFT = MIDDLE + 1; // search is focused
          // on the right side of the list

    } //end while
    return index;
}

/*#############################[SORTING ALGORITHMS]###############################################*/
/*----------------------------[GENERAL SWAP FUNCTION CALLED ONCE NEEDED]-------------------------*/
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/*----------------------------[Selection Sort To Sort Names]-------------------------*/
void SelectionSortAscending(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the maximum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found maximum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
void SelectionSortDescending(int arr[], int n) {
    int i, j, max_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        max_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] > arr[max_idx])
                max_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[max_idx], &arr[i]);
    }
}
/*----------------------------[Bubble Sort To Sort Lengths]-------------------------*/
void bubbleSortAscending(int arr[], int n) {
    int i, j, * xp, * yp, temp;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);

            }

}
void bubbleSortDescending(int arr[], int n) {
    int i, j, * xp, * yp, temp;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) {
                xp = &arr[j];
                yp = &arr[j + 1];
                temp = *xp;
                *xp = *yp;
                *yp = temp;
            }

}
/*----------------------------[Merge Sort To Sort Weight]-------------------------*/
void mergeB(int arr[], int p, int q, int r) {
    //cout << endl << "p" << p << "q" << q << "r" << r;

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    //cout << n1;
    int n2 = r - q;
    //cout << n2;

    int* L = new int[n1], * M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    //cout << endl << i << " " << j << " " << k;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] > M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        //cout << endl << arr[k];
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    //cout << endl << n1 << " " << i;
    while (i < n1) {
        arr[k] = L[i];
        i++;

        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        //cout << endl << arr[k];
        k++;
    }
}
void mergeA(int arr[], int p, int q, int r) {
    //cout << endl << "p" << p << "q" << q << "r" << r;

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    //cout << n1;
    int n2 = r - q;
    //cout << n2;

    int* L = new int[n1], * M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    //cout << endl << i << " " << j << " " << k;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        //cout << endl << arr[k];
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    //cout << endl << n1 << " " << i;
    while (i < n1) {
        arr[k] = L[i];
        i++;

        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        //cout << endl << arr[k];
        k++;
    }
}
void mergeSortAscending(int arr[], int l, int r) {
    if (l < r) {

        // m is the point where the array is divided into two subarrays

        int m = l + (r - l) / 2;

        mergeSortAscending(arr, l, m);

        mergeSortAscending(arr, m + 1, r);

        // Merge the sorted subarrays
        mergeA(arr, l, m, r);
    }

}
void mergeSortDescending(int arr[], int l, int r) {
    if (l < r) {

        // m is the point where the array is divided into two subarrays

        int m = l + (r - l) / 2;

        mergeSortDescending(arr, l, m);

        mergeSortDescending(arr, m + 1, r);

        // Merge the sorted subarrays
        mergeB(arr, l, m, r);
    }

}

/*#############################[OPERATIONAL FUNCTIONS]###############################################*/
void AvoidRetetition(int S[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (S[i] == S[j]) {
                srand((unsigned)time(0));
                int i;
                S[j] = (rand() % 6) + 1;

            }
        }
    }
}
void Display(int Sorted[], Gymnastic G[], int size, char id) {

    cout << endl << left << setw(10) << "NAME" << setw(8) << "WEIGHT" << setw(8) << "LENGTH" << setw(20) << "BODY TYPE" << "MEMBERSHIP" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (id == 'W')
                if (Sorted[i] == G[j].Weight) {
                    cout << left << setw(10) << G[j].Name <<
                        setw(8) << G[j].Weight << setw(8) <<
                        G[j].Length << setw(20) << G[j].bodyShape <<
                        G[j].mms << endl;

                    break;

                }
            if (id == 'L')
                if (Sorted[i] == G[j].Length) {
                    cout << left << setw(10) << G[j].Name <<
                        setw(8) << G[j].Weight << setw(8) <<
                        G[j].Length << setw(20) << G[j].bodyShape <<
                        G[j].mms << endl;

                }
            if (id == 'N')
                if ((char)Sorted[i] == G[j].Name[0]) {
                    cout << left << setw(10) << G[j].Name <<
                        setw(8) << G[j].Weight << setw(8) <<
                        G[j].Length << setw(20) << G[j].bodyShape <<
                        G[j].mms << endl;

                }
            if (id == 'M')
                if (Sorted[i] == G[j].mms) {
                    cout << left << setw(10) << G[j].Name <<
                        setw(8) << G[j].Weight << setw(8) <<
                        G[j].Length << setw(20) << G[j].bodyShape <<
                        G[j].mms << endl;

                }
        }

    }
}
void Sortweight(Gymnastic G[], int size, int direction, int donotdisplay = 0) {

    char id = 'W';
    cout << endl << "<<< Sorting By Weight >>>" << endl;

    int* Sorted = new int[size];

    for (int i = 0; i < size; i++) {
        Sorted[i] = G[i].Weight;
    }

    if (direction == 2) {

        mergeSortDescending(Sorted, 0, size - 1);
    }
    else {
        mergeSortAscending(Sorted, 0, size - 1);

    }

    AvoidRetetition(Sorted, size);
    if (donotdisplay != 1)
        Display(Sorted, G, size, id);
}
void Sortlength(Gymnastic G[], int size, int direction) {

    char id = 'L';
    cout << endl << "<<< Sorting By Length >>>" << endl;

    int* Sorted = new int[size];

    for (int i = 0; i < size; i++) {
        Sorted[i] = G[i].Length;
    }

    if (direction == 2) {

        bubbleSortDescending(Sorted, size);
    }
    else {
        bubbleSortAscending(Sorted, size);

    };
    AvoidRetetition(Sorted, size);
    Display(Sorted, G, size, id);

}
void SortName(Gymnastic G[], int size, int direction) {
    char id = 'N';

    cout << endl << "<<< Sorting By Name >>>" << endl;

    int* Sorted = new int[size];

    for (int i = 0; i < size; i++) {
        Sorted[i] = (int)G[i].Name[0];
    }

    if (direction == 2) {
        SelectionSortDescending(Sorted, size);
    }
    else {
        SelectionSortAscending(Sorted, size);

    }
    AvoidRetetition(Sorted, size);
    Display(Sorted, G, size, id);

}
void SortMembership(Gymnastic G[], int size, int direction) {
    char id = 'M';

    cout << endl << "<<< Sorting By Membership >>>" << endl;

    int* Sorted = new int[size];

    for (int i = 0; i < size; i++) {
        Sorted[i] = G[i].mms;
    }

    if (direction == 2) {
        SelectionSortDescending(Sorted, size);
    }
    else {
        SelectionSortAscending(Sorted, size);

    }
    AvoidRetetition(Sorted, size);
    Display(Sorted, G, size, id);
}
/*###########################################################################################*/

Gymnastic Addmembers() {
    cout << "----------------------[You Are Sorting]--------------------" << endl;
    cout << "<< < Sorting Process > >>" << endl;
    Gymnastic N;
    cout << "-----------[Enter New Member Info Following The Pattern]-----------" << endl;
    cout << "Name.  Gender. Length. Weight. BodyType.   Membership." << endl;
    if (!(cin >> N.Name >> N.gender >> N.Length >> N.Weight >> N.bodyShape >> N.mms)) {
        cout << endl << "[!]________[! Warning: Breaking Violation !]________[!]" << endl;
        Addmembers();
    }
    return N;




}

int Banner() {
    int t;
    cout << "--------------" << endl;
    cout << "[1]_ MEMBER. " << endl;
    cout << "[2]_ ADMINISTRATOR. " << endl;
    cout << "--------------" << endl;
    cout << endl << "I'm a/an >> ";
    cin >> t;
    return t;
}

int AdminsBanner(int& d, int& c) {

    int attempt = 0, loop = 1, o;
    while (loop) {
        int o;
        string p, u;
        cout << "<< < Authantication > >>" << endl;
        cout << "username: ";
        cin >> u;
        cout << "password: ";
        cin >> p;
        if (u == "Admin" && p == "12pm") {
            loop = 0;
        }
        else
            cout << endl << "Invalid Credentials" << endl << endl;
        attempt++;
        if (attempt == 3) {
            exit(1);
        }
    }

    cout << endl << endl << "<<< Operations >>>" << "\n" <<
        "[1] Sort" << "\n" <<
        "[2] Add a Member" << "\n" <<
        "[3] (*)View  Members" << "\n" <<
        "[4] (*)Delete a Member" << "\n" <<
        "[5] (*)Edit a Member" << "\n" <<
        "[6] (*)Extend Membership" << "\n" <<
        "[0] Exit" << "\n" <<


        "Option : ";
    cin >> o;
    if (o == 1) {
        cout << endl << "----------------------[You Are Sorting]--------------------" << endl;
        cout << "<<< Sorting Process >>>" << "\n" <<
            "[1] By name" << "\n" <<
            "[2] By weight" << "\n" <<
            "[3] By length" << "\n" <<
            "[4] By membership" << "\n" <<
            "[0] EXIT" << "\n" <<
            "Option : ";
        cin >> c;

        if (c == 0) {
            return o;
        }
        if (c > 4 || c < 0) {

            cout << endl << "[!]________[! Warning: Breaking Violation !]________[!]" << endl;
            AdminsBanner(d, c);
        }

        cout << endl;
        cout << "<< Directions >>" << endl;
        cout << "[1] Ascending" << endl;
        cout << "[2] Descending" << endl;
        cout << endl;
        cout << "Option: ";
        cin >> d;
        if (d > 2 || d < 0) {
            cout << endl << "[!]________[! Warning: Breaking Violation !]________[!]" << endl;
            AdminsBanner(d, c);
        }
    }


    return o;

}
void MemberBanner(Gymnastic G[], int size) {
    int o;
    int i = 0;
    unsigned int idx;
    string name;
    bool found = false;
    int* Sorted = new int[size];

    cout << endl << "<< < Login > >>" << endl;
    cout << "Enter Your name: ";
    cin >> name;

    for (; i < size; i++) {
        if (G[i].Name == name) {
            cout << endl << "[Welcome " << name << "]";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "USER NOT FOUND" << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        Sorted[i] = G[i].Weight;
    }
    mergeSortAscending(Sorted, 0, size - 1);
    AvoidRetetition(Sorted, size);
    while (1) {
        cout << endl << "<< <  Searching.. > >>" << endl << endl;
        cout << "[1] My Rank (LowerIsBetter)" << endl;
        cout << "[2] Remaining Subscription" << endl;
        cout << "[0] EXIT" << endl;
        cout << endl;
        cout << "Option: ";
        cin >> o;
        if (o == 0) {
            exit(1);
        }
        if (o == 1) {

            int weight = G[i].Weight;

            idx = binary_search(weight, size, Sorted);
            cout << endl << "[=] YOUR RANK IS " << idx + 1 << " ACCORDING TO YOU CURRENT WEIGHT." << endl;
        }
        if (o == 2) {
            srand((unsigned)time(0));
            cout << endl << "[=] " << name << "'s " << "Subscription Ends After: " << G[i].mms << " Months and " << (rand() % 30) + 1 << " Days" << endl;
        }
    }

}

int countMembers() {
    ifstream read;
    read.open("Input.txt");
    if (read.fail()) {
        cout << "CAN'T READ FROM FILE" << endl;
        cout << "EXITING SYSTEM.." << endl;
        exit(1);
    }

    int number_of_members = 0;
    string line;
    while (std::getline(read, line)) {
        ++number_of_members;
    }
    return number_of_members;
}
void read(Gymnastic G[]) {
    ifstream read;
    int length, weight, membership;
    string Name, gender, bodyshape;
    int i = 0;

    read.open("Input.txt");
    if (read.fail()) {
        cout << "CAN'T READ FROM FILE" << endl;
        cout << "EXITING SYSTEM.." << endl;
        exit(1);
    }

    while (read >> Name >> gender >> length >> weight >> bodyshape >> membership) {

        Gymnastic NewGymnastic;
        NewGymnastic.Name = Name;
        NewGymnastic.gender = gender;
        NewGymnastic.Length = length;
        NewGymnastic.bodyShape = bodyshape;
        NewGymnastic.mms = membership;
        NewGymnastic.Weight = weight;
        G[i] = NewGymnastic;
        i++;

    }

}

int main() {

    char letter;
    int c, d, r, t, o;
    int size = countMembers();
    Gymnastic* G = new Gymnastic[size];
    cout << "[+] JOIN OUR ULTIMATE GYM AND GAIN MUSCLES ;O)[+]" << endl;
    cout << endl << "(*) = under maintenance " << endl;

    read(G);
    t = Banner();

    if (t == 2) {

        while (1) {
            o = AdminsBanner(d, c);
            if (o == 0)
            {
                exit(1);
            }
            if (o == 1) {
                switch (c) {
                case 1:
                    SortName(G, size, d);
                    break;
                case 2:
                    Sortweight(G, size, d);
                    break;
                case 3:
                    Sortlength(G, size, d);

                    break;
                case 4:
                    SortMembership(G, size, d);
                    break;
                default:
                    cout << endl << "[!]________[! Warning: Breaking Violation !]________[!]" << endl;
                    break;
                }
            }
            if (o == 2)
            {

                Gymnastic* Temp = new Gymnastic[size + 1];
                Temp = G;
                Temp[size] = Addmembers();
                delete[] G;
                Gymnastic* G = new Gymnastic[size + 1];
                G = Temp;
                delete[] Temp;

            }

        }
    }
    if (t == 1) {
        MemberBanner(G, size);

    }

}