#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, temp, burst_time[10], waiting_time[10], turnaround_time[10], process[10];
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;

    cout<<"Input the number of processes: ";
    cin>>n;

    cout<<"Input the burst time of processes: \n";
    for(i=1; i<=n; i++)
    {
        cin>>burst_time[i];
        process[i] = i;

    }


    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            if(burst_time[i] > burst_time[j])
            {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    //waiting time

    waiting_time[1] = 0;

    for(i=2; i<=n; i++)
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];

    cout<<"Waiting time of processes: \n";
    for(i=1; i<=n; i++)
        cout<<"P["<<process[i]<<"]= "<<waiting_time[i]<<endl;

    //TurnAround time

    for(i=1; i<=n; i++)
        turnaround_time[i] = waiting_time[i] + burst_time[i];

    cout<<"Turnaround time of processes: \n";
    for(i=1; i<=n; i++)
        cout<<"P["<<process[i]<<"]= "<<turnaround_time[i]<<endl;

    //Average waiting time

    for(i=1; i<=n; i++)
        avg_waiting_time += waiting_time[i];


    //Average turnAround time

    for(i=1; i<=n; i++)
        avg_turnaround_time += turnaround_time[i];

    cout<<"Average waiting time: "<<avg_waiting_time / n<<endl;
    cout<<"Average turnaround time: "<<avg_turnaround_time / n<<endl;

}

