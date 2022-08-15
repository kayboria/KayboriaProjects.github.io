#include <iostream>
#include<iomanip>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define n 10          // n here is the number of processes, it's better to be a define value so 
                     // so all functions can access it easily
using namespace std;  // the standard name space for the iostream objects such as cout, cin etc.



//4 variables for to store avarage wait time
double avgWaitFCFS = 0;
double avgWaitSJN = 0;
double avgWaitSRT = 0;
double avgWaitRR = 0;
//4 variables for to store avarage Turn around time
double avgTurnFCFS = 0;
double avgTurnSJN = 0;
double avgTurnSRT = 0;
double avgTurnRR = 0;


// function for dislaying the values for each algorithm:

void display(char p[], int a[], int b[], int w[], int t[])
{

	// first making sure all going out in the right precesion:
	cout << fixed << setprecision(1);

	// displaying the banner in the top
	// like this:
	// Process     Arrival            Burst       Waiting         Turn-around

	cout  << setw(5) << left << "Process" << setw(12) << right << "Arrival"
		<< "\t" << setw(12) << right << "Burst" << setw(14) << right << "Waiting"
		<< "\t" << setw(14) << right << "Turn-around" << endl;


	//display Process, Arrival, Burst, Waiting and Turn-around
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << left << p[i] << setw(12) << right << a[i]
			<< "\t" << setw(12) << right << b[i] << setw(12) << right << w[i]
			<< "\t" << setw(12) << right << t[i] << endl;
	}
}



// variable for the SJN algorithm.
int ab;

// structure to store all the burst and Process IDs of the array to make it easy to perform the SJN on IT
typedef struct schedule
{
	string pro_id;
	int at, bt, ct, ta, wt;

	/*

	all the previous variable names are simply as follows:

	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}schedule;

// function for the SJN Algorithm
bool compare(schedule a, schedule b)
{
	return a.at < b.at;
	/* This process will always return TRUE
	if above condition comes*/
}
// function for the SJN Algorithm
bool compare2(schedule a, schedule b)
{
	return a.bt < b.bt&& a.at <= ab;
	/* This process will always return TRUE
	if above condition comes*/
}

void SJN(char p[], int a[], int b[])
{
	int w[500], t[500];
	schedule pro[10]; //An array of Processes
	
	int i;
	//n = number of processes, i= iteration variable\
	// copying from Passed Arrat to the Structer Array variables 
	for (i = 0; i < n; i++)
	{
		pro[i].pro_id = p[i];
		pro[i].at = a[i];
		pro[i].bt = b[i];
	}

	/*sort is a predefined funcion  defined in algorithm.h header file,
	it will sort the processes according to their arrival time*/

	sort(pro, pro + n, compare);

	// initial values

	pro[0].ct = pro[0].bt + pro[0].at;
	pro[0].ta = pro[0].ct - pro[0].at;
	pro[0].wt = pro[0].ta - pro[0].bt;

	for (i = 1; i < n; i++)
	{
		ab = pro[i - 1].ct;
		sort(pro + i, pro + n, compare2);
		if (pro[i - 1].ct < pro[i].at)
		{
			pro[i].ct = pro[i - 1].ct + pro[i].bt + (pro[i].at - pro[i - 1].ct);
		}
		else
		{

			pro[i].ct = pro[i - 1].ct + pro[i].bt;

		}
		pro[i].ta = pro[i].ct - pro[i].at;
		pro[i].wt = pro[i].ta - pro[i].bt;
	}
	
	
	// registering each process waiting time and turn around time
	// to send a[n] and t[n] later to display function
	for (i = 0; i < n; i++)
	{
		w[i] = pro[i].wt;
		t[i] = pro[i].ta;

	}



	int total_Wait = 0;
	int total_Turn = 0;
	for (i = 0; i < n; i++)
	{

		// calculating Total of Wating and Turn around
		total_Wait += w[i];
		total_Turn += t[i];

	}

	//caluclate avarage waiting time and turnaround time
	avgWaitSJN = (total_Wait / n);
	avgTurnSJN = (total_Turn / n);


	// calling the display function to diplay the output
	cout << "\n\n***********************************SJN***********************************\n" << endl;
	display(p, a, b, w, t);
	cout << "\n***********************************************************************\n" << endl;
}



void FCFS(char p[], int a[], int b[])
{
	int i, ab[50], w[50], t[50];
	double aw_time = 0, atat_time = 0;
	w[0] = 0;
	t[0] = b[0];
	ab[0] = b[0] + a[0];
	for (i = 1; i < n; i++) {
		ab[i] = ab[i - 1] + b[i];
		//Turnaround time is the Time Difference between
		// completion time and arrival time
		//Turn Around Time = Completion Time - Arrival Time
		t[i] = ab[i] - a[i];
		//Waiting time = turnaround time � Burst time
		w[i] = t[i] - b[i];
	}
	//caluclate avarage waiting time and turnaround time
	for (int i = 0; i < n; i++)
	{
		//sum of waiting time
		avgWaitFCFS = avgWaitFCFS + w[i];
		//sum of turn around time
		avgTurnFCFS = avgTurnFCFS + t[i];
	}
	//find avarage waiting time
	avgWaitFCFS = avgWaitFCFS / n;
	//find turnaround time
	avgTurnFCFS = avgTurnFCFS / n;
	cout << "\n\n**********************************FCFS***********************************\n" << endl;
	display(p, a, b, w, t);
	cout << "\n************************************************************************\n" << endl;

}

void SRTF(char p[], int a[], int b[])
{
	int w[n], t[n], k[n], f[n];
	int tot = 0;
	int ct[n],  st = 0;

	// creating an array to temporarily hold the bursttime values in b[i] 
	// because they will change during the program, after the execution finish
	// right before sending it to the display fucntion, we will retore b[i] from backup_burstTime[i]
	// so we can send b directly
	int backup_burstTime[n];


	for (int i = 0; i < n; i++)
	
	{
		k[i] = b[i];
		f[i] = 0;
		backup_burstTime[i] = b[i];
	}
	while (true)
	{
		int min = 999, c = n;
		if (tot == n)
			break;
		//find the shortest remaing time process
		for (int i = 0; i < n; i++)
		{
			if ((a[i] <= st) && (f[i] == 0) && (b[i] < min))
			{
				min = b[i];
				c = i;
			}
		}
		//preempt the process based on the arrival time and remaing time
		if (c == n)
			st++;
		else
		{
			b[c]--;
			st++;
			if (b[c] == 0)
			{
				ct[c] = st;
				f[c] = 1;
				tot++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		b[i] = backup_burstTime[i];
		//find turnaround time of each
		t[i] = ct[i] - a[i];
		//find wating time of each
		w[i] = t[i] - k[i];
		//sum of waiting time
		avgWaitSRT = avgWaitSRT + w[i];
		//sum of turn around time
		avgTurnSRT = avgTurnSRT + t[i];
	}
	//caluclate avarage waiting time and turnaround time
	avgWaitSRT = avgWaitSRT / n;
	avgTurnSRT = avgTurnSRT / n;
	cout << "\n\n**********************************SRTF***********************************\n" << endl;
	display(p, a, b, w, t);
	cout << "\n************************************************************************\n" << endl;

}


void RoundRobin(char p[], int a[], int b[], int timeQuantum)
{

	int i, time, remain, temps = 0, time_quantum;
	int w[n], t[n];


	int wt = 0, tat = 0;

	remain = n;
	// assigning the number of process to remain variable

	vector<int>at(n);
	vector<int>bt(n);
	vector<int>rt(n);
	//dynamic array declaration using vector method of (STL)
	//STL standard template library of C++


	// getting the Arrival time, Burst time for All the processes
	for (i = 0; i < n; i++)
	{
		at[i] = a[i];
		bt[i] = b[i];
		rt[i] = bt[i];
	}

	// Assigning the time Quantum
	time_quantum = timeQuantum;

	
	for (time = 0, i = 0; remain != 0;)
	{
		if (rt[i] <= time_quantum && rt[i] > 0)
		{
			time += rt[i];
			//Addition using shorthand operators
			rt[i] = 0;
			temps = 1;
		}

		else if (rt[i] > 0)
		{
			rt[i] -= time_quantum;
			//Subtraction using shorthand operators
			time += time_quantum;
			//Addition using shorthand operators
		}

		if (rt[i] == 0 && temps == 1)
		{
			remain--;

			w[i] = time - at[i];
			t[i] = time - at[i] - bt[i];

			wt += time - at[i] - bt[i];
			tat += time - at[i];
			temps = 0;
		}

		if (i == n - 1)
			i = 0;
		else if (at[i + 1] <= time)
			i++;
		else
			i = 0;
	}


	//caluclate avarage waiting time and turnaround time
	avgWaitRR = wt * 1.0 / n ;
	avgTurnRR = tat * 1.0 / n ;

	// Calling the display function
	
	cout << "\n\n******************************Round Robin*******************************\n" << endl;
	display(p, a, b, w, t);
	cout << "\n************************************************************************\n" << endl;

}

// Driver code
int main()
{
	// Process id's
	char processes[] = { 'A','B','C','D','E','F','G','H','I','J' };
	// Burst time of all processes
	int burst_time[] = { 6, 2,1, 7, 5, 3, 4, 5, 7, 2 };
	// Arrival time of all processes
	int arrival_time[] = { 0, 3, 5, 9, 10, 12, 14, 16, 17,19 };
	
	// Calling FCFS
	int* b = burst_time;
	int* a = arrival_time;
	FCFS(processes, a, b);


	// caling SJN
	b = burst_time;
	a = arrival_time;
	SJN(processes, a, b);



	// calling SRTF
	b = burst_time;
	a = arrival_time;

	SRTF(processes, a, b);


	// Calling RoundRobin
	//time quantum for round robin algorithm
	// context switching is 0 so no point of passing it:
	int timeQuantum = 4;
	b = burst_time;
	a = arrival_time;
	RoundRobin(processes, a, b, timeQuantum);
	cout << "\n\nAlgorithm\tAvarage Waiting time\tAvarage Turn time\n";





	// Outputting the Average Values


	// first making sure all going out in the right precesion:
	cout << fixed << setprecision(1);
	// now couting in the reigt precesion
	cout << setw(13) << left << "FCFS"
		<< setw(12) << right << avgWaitFCFS
		<< setw(25) << right << avgTurnFCFS << endl;

	cout << setw(13) << left << "SJN";
	cout << setw(12) << right << avgWaitSJN;
	cout<< setw(25) << right << avgTurnSJN << endl;


	cout << setw(13) << left << "SRTF"
		<< setw(12) << right << avgWaitSRT
		<< setw(25) << right << avgTurnSRT << endl;
	cout << setw(13) << left << "Round roubin"
		<< setw(12) << right << avgWaitRR
		<< setw(25) << right << avgTurnRR << endl;
	cout << endl;

	system("pause");
	return 0;
}