#include<bits/stdc++.h>
using namespace std;
 
struct Process
{
   int pid; 
   int bt;  
};

bool comparison1(Process a, Process b)
{
     return (a.bt < b.bt);
}
bool comparison2(Process a, Process b)
{
     return (a.bt > b.bt);
}

void findWaitingTime(Process proc[], int n, int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
    wt[i] = proc[i-1].bt + wt[i-1] ;
}

void findTurnAroundTime(Process proc[], int n,int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    cout << "\nArrivalTime "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
int main()
{
    Process proc[] = {{8, 16}, {3, 6}, {2, 4}, {4, 8} , {6,12}};
    int n = sizeof proc / sizeof proc[0];
	    
    
    sort(proc, proc + n, comparison2);
    cout<<"\n---------------------------------------WELCOME TO SCHEDULING APPROACH----------------------------------------"<<endl;
    cout<<"\n";
    cout << "\n\n\t\t\t+++++++++++++++LONGEST JOB FIRST++++++++++++++++\t\t\t\t\t\n";
    cout<<"\n";
    cout << "\nThe Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
    cout << proc[i].pid <<" ";
    findavgTime(proc, n);
    
	cout << "\n\n\t\t\t+++++++++++++++SHORTEST JOB FIRST+++++++++++++++\t\t\t\t\t\n";
    sort(proc, proc + n, comparison1);
    cout<<"\n";
    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
    cout << proc[i].pid <<" ";
    findavgTime(proc, n);
    return 0;
}
