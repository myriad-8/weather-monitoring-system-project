#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MONTHS 12
#define DAYS 30

int temp[MONTHS][DAYS] = {
    {12,14,15,16,14,13,12,11,10,9,8,12,13,15,16,14,13,12,11,10,8,7,8,9,10,12,14,15,16,14},
    {16,17,18,18,19,20,21,19,17,16,15,16,18,19,20,19,18,17,16,15,14,16,17,18,20,21,20,19,18,17},
    {22,23,24,25,26,28,29,28,27,25,24,23,22,24,25,26,28,30,31,32,30,28,27,26,25,26,27,28,29,30},
    {35,36,38,40,42,41,40,39,38,37,36,35,34,36,37,38,39,40,41,42,43,44,43,42,41,40,39,38,37,36},
    {42,44,45,46,47,46,45,44,43,42,41,40,42,44,46,48,47,46,45,44,43,42,41,43,44,45,46,47,48,46},
    {39,38,37,36,35,34,33,35,36,38,39,40,41,39,37,36,35,33,32,34,35,36,38,39,40,39,38,37,36,35},
    {33,32,31,30,29,28,30,32,33,31,30,29,28,27,28,30,32,34,35,33,32,31,30,29,28,27,26,28,30,31},
    {32,31,30,29,30,31,32,33,34,33,32,31,30,29,28,30,32,33,34,33,32,31,30,29,28,27,29,30,31,32},
    {33,34,35,36,37,36,35,34,33,32,31,30,29,30,32,34,35,36,37,36,35,34,33,32,31,30,32,33,34,35},
    {30,29,28,27,26,27,28,29,30,31,32,30,29,28,27,26,25,26,28,29,30,31,30,29,28,27,26,25,24,26},
    {24,23,22,21,20,22,24,25,26,25,24,23,22,21,20,19,18,19,20,21,22,23,24,25,24,23,22,21,20,19},
    {15,14,13,12,11,13,14,15,16,15,14,13,12,11,10,9,8,9,10,11,12,13,14,15,14,13,12,11,10,9}
};

char *months[MONTHS] = {
    "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};

void YearOverview();
void MonthlyStats();
void SimpleGraph();
void HeatColdWarnings();
void DetectAnomalies();
void LinearRegressionForecast();

int main() {
    int option;

    do {
        printf("\nWeather Monitoring System\n");
        printf("1. Yearly Overview\n");
        printf("2. Monthly Stats\n");
        printf("3. Simple Graph\n");
        printf("4. Heat/Cold Warnings\n");
        printf("5. Detect Anomalies\n");
        printf("6. Forecast Trend (Linear Regression)\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: YearOverview(); break;
            case 2: MonthlyStats(); break;
            case 3: SimpleGraph(); break;
            case 4: HeatColdWarnings(); break;
            case 5: DetectAnomalies(); break;
            case 6: LinearRegressionForecast(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while(option != 7);

    return 0;
}

void YearOverview() {
    int max = temp[0][0], min = temp[0][0], sum = 0;

    for(int i=0; i<MONTHS; i++)
        for(int j=0; j<DAYS; j++) {
            if(temp[i][j] > max) max = temp[i][j];
            if(temp[i][j] < min) min = temp[i][j];
            sum += temp[i][j];
        }

    printf("\nYearly Max Temp: %d", max);
    printf("\nYearly Min Temp: %d", min);
    printf("\nYearly Avg Temp: %.2f\n", (float)sum/(MONTHS*DAYS));
}

void MonthlyStats() {
    int m;
    printf("Enter month number (1-12): ");
    scanf("%d",&m);
    m--;

    if(m<0 || m>=MONTHS) {
        printf("Invalid month!\n");
        return;
    }

    int max=temp[m][0], min=temp[m][0], sum=0;

    for(int i=0; i<DAYS; i++) {
        if(temp[m][i]>max) max=temp[m][i];
        if(temp[m][i]<min) min=temp[m][i];
        sum+=temp[m][i];
    }

    printf("\nStats for %s:\nMax: %d\nMin: %d\nAvg: %.2f\n",
           months[m], max, min, (float)sum/DAYS);
}

void SimpleGraph() {
    int m;
    printf("Enter month number (1-12): ");
    scanf("%d",&m);
    m--;

    if(m<0 || m>=MONTHS) {
        printf("Invalid month!\n");
        return;
    }

    printf("\nTemperature Graph for %s:\n", months[m]);

    for(int i=0; i<DAYS; i++) {
        printf("Day %2d: ", i+1);
        for(int k=0; k<temp[m][i]/2; k++)
            printf("*");
        printf(" %d\n", temp[m][i]);
    }
}

void HeatColdWarnings() {
    printf("\nHeat/Cold Warnings:\n");

    for(int i=0; i<MONTHS; i++)
        for(int j=0; j<DAYS; j++) {
            if(temp[i][j]>=40)
                printf("Heat wave on %s Day %d\n", months[i], j+1);
            if(temp[i][j]<=10)
                printf("Cold wave on %s Day %d\n", months[i], j+1);
        }
}

void DetectAnomalies() {
    float sum=0;
    int total = MONTHS*DAYS;

    for(int i=0;i<MONTHS;i++)
        for(int j=0;j<DAYS;j++)
            sum += temp[i][j];

    float avg = sum/total;

    printf("\nAnomalies (Deviation > 8°C from avg %.2f):\n", avg);

    for(int i=0;i<MONTHS;i++)
        for(int j=0;j<DAYS;j++)
            if(fabs(temp[i][j]-avg) > 8)
                printf("%s Day %d: %d°C\n",
                       months[i], j+1, temp[i][j]);
}

void LinearRegressionForecast() {

    int n = MONTHS*DAYS;
    float sumx=0,sumy=0,sumxy=0,sumxx=0;

    for(int i=0;i<n;i++) {
        int month = i/DAYS;
        int day = i%DAYS;

        float x = i+1;
        float y = temp[month][day];

        sumx += x;
        sumy += y;
        sumxy += x*y;
        sumxx += x*x;
    }

    float slope = (n*sumxy - sumx*sumy)/(n*sumxx - sumx*sumx);
    float intercept = (sumy - slope*sumx)/n;

    printf("\nTrend slope: %.5f\n", slope);

    if(slope>0)
        printf("Overall Trend: Increasing (Warming)\n");
    else if(slope<0)
        printf("Overall Trend: Decreasing (Cooling)\n");
    else
        printf("Overall Trend: Stable\n");

    int futureDays;
    printf("Predict temperature after how many days? ");
    scanf("%d",&futureDays);

    float prediction = slope*(n+futureDays) + intercept;

    printf("Predicted temperature after %d days: %.2f°C\n",
           futureDays, prediction);
}
