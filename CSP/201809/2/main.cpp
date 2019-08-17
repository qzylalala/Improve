#include <iostream>

using namespace std;

int main()
{
    int n, time1[2000][2], time2[2000][2];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> time1[i][0] >> time1[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> time2[i][0] >> time2[i][1];
    }
    int time = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(time1[i][0] <= time2[j][0])
            {
                if(time1[i][1] >= time2[j][1])
                    time += time2[j][1] - time2[j][0];
                else if(time1[i][1] >= time2[j][0])
                    time += time1[i][1] - time2[j][0];
                else
                    ;
            }

            else
            {
                if(time1[i][1] <= time2[j][1])
                    time += time1[i][1] - time1[i][0];
                else if(time1[i][1] > time2[j][1] && time1[i][0] < time2[j][1])
                    time += time2[j][1] - time1[i][0];
                else
                    ;
            }
        }
    }

    cout << time;
}
