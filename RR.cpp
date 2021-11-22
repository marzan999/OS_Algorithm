#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n, time, remain, done=0, time_quantum;

    int Process[10], burst_time[10], turnaround_time[10], waiting_time[10];

    float avg_wt=0, avg_TA=0;

    cout<<endl;
    cout<<"Input the number of process: ";
    cin>>n;

    remain=n;

    cout<<endl;
    cout<<"Please Input the burst time: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"P["<<i+1<<"]=";
        cin>>Process[i];

        burst_time[i]=Process[i];
    }

    cout<<endl;
    cout<<"Please Input the Quantum: ";
    cin>>time_quantum;

    time = 0;
    i = 0;

    while(remain!=0)
    {
        if(burst_time[i]<=time_quantum && burst_time[i]>0)
        {
            time = time + burst_time[i];
            burst_time[i] = 0;
            done = 1;
        }

        else if(burst_time[i]>0)
        {
            time = time + time_quantum;
            burst_time[i] -= time_quantum;
        }

        if(burst_time[i] == 0 && done == 1)
        {
            remain--;
            turnaround_time[i] = time;
            cout<<time<<endl;
            waiting_time[i] = turnaround_time[i] - Process[i];
            done=0;
        }

        if(i == n-1)
            i = 0;
        else
            i++;

    }

    //waiting time

    waiting_time[0] = 0;

    for(i=0; i<n; i++)
    {
        cout<<endl;
        printf("Waiting Time of Process[%d]=%d",i+1,waiting_time[i]);
        avg_wt += waiting_time[i];
    }
    cout<<endl;
    cout<<endl;

    printf("Average Waiting time= %f\n", (avg_wt/n));

    //turn around time

    for(i=0; i<n; i++)
    {
        cout<<endl;
        printf("TurnAround Time of Process[%d]=%d",i+1,turnaround_time[i]);
        avg_TA += turnaround_time[i];
    }

    cout<<endl;

    cout<<endl;
    printf("Average TurnAround time= %f\n", (avg_TA/n));

}
