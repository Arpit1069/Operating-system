
#include <stdio.h>
int main()
{
    int i, j, BT[5], AT[5], TAT[5], WT[5], c = 0, sum[6], P2[5], BT2[5], idle, n = 5, temp;
    sum[0] = 0;
    printf("Enter new Process order : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &P2[i]);
    }
    printf("\nEnter Arrival time order wise : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &AT[i]);
    }
    printf("\nEnter Burst time order wise : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &BT2[i]);
    }
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 5; i++)
        {
            if (AT[i] > AT[i + 1])
            {
                temp = AT[i];
                AT[i] = AT[i + 1];
                AT[i + 1] = temp;
                temp = P2[i];
                P2[i] = P2[i + 1];
                P2[i + 1] = temp;
                temp = BT2[i];
                BT2[i] = BT2[i + 1];
                BT2[i + 1] = temp;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (AT[i] > sum[i])
        {
            idle = AT[i] - sum[i];
            c = c + BT2[i] + idle;
        }
        else
        {
            c = c + BT2[i];
        }
        sum[i + 1] = c;
    }
    float avgWT = 0.0, avgTAT = 0.0;
    printf("Gantt Chart:\n");
    printf("_______________________________\n");
    for (i = 0; i < 5; i++)
    {
        printf("| P%d  ", P2[i + 1]);
    }
    printf("|\n|_____|_____|_____|_____|_____|\n");
    printf("0     %d     %d     %d    %d     %d", sum[1], sum[2], sum[3], sum[4], sum[5]);
    printf("\n\n");
    printf("Process\t\tAT\tBT\tTAT\tWT");
    for (i = 0; i < 5; i++)
    {
        TAT[i] = sum[i + 1] - AT[i];
        WT[i] = TAT[i] - BT2[i];
        printf("\nP%d\t\t%d\t%d\t%d\t%d", P2[i + 1], AT[i + 1], BT2[i + 1], TAT[i + 1], WT[i + 1]);
        avgWT = avgWT + WT[i];
        avgTAT = avgTAT + TAT[i];
    }
    avgWT = avgWT / 5;
    avgTAT = avgTAT / 5;
    printf("\nAverage Waiting Time : %f", avgWT);
    printf("\nAverage Turn-Around Time : %f", avgTAT);
    printf("\n");
}
