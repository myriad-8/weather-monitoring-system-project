#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<math.h>
//#include<unistd.h> 

#define MONTHS 12
#define DAYS 30  
#define WEEKS 52

#define USERNAME "admin"
#define PASSWORD "1234"           // User credentials

#define RESET  "\033[0m"
#define GREEN  "\033[32m"         //Colour codes
#define RED    "\033[31m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define CYN    "\033[0;36m"
#define MAG    "\033[0;35m"

char a = ' ';

int temp[MONTHS][DAYS] = {
    // January 
    {12, 14, 15, 16, 14, 13, 12, 11, 10, 9, 8, 12, 13, 15, 16, 14, 13, 12, 11, 10, 8, 7, 8, 9, 10, 12, 14, 15, 16, 14},
    // February 
    {16, 17, 18, 18, 19, 20, 21, 19, 17, 16, 15, 16, 18, 19, 20, 19, 18, 17, 16, 15, 14, 16, 17, 18, 20, 21, 20, 19, 18, 17},
    // March 
    {22, 23, 24, 25, 26, 28, 29, 28, 27, 25, 24, 23, 22, 24, 25, 26, 28, 30, 31, 32, 30, 28, 27, 26, 25, 26, 27, 28, 29, 30},
    // April 
    {35, 36, 38, 40, 42, 41, 40, 39, 38, 37, 36, 35, 34, 36, 37, 38, 39, 40, 41, 42, 43, 44, 43, 42, 41, 40, 39, 38, 37, 36},
    // May 
    {42, 44, 45, 46, 47, 46, 45, 44, 43, 42, 41, 40, 42, 44, 46, 48, 47, 46, 45, 44, 43, 42, 41, 43, 44, 45, 46, 47, 48, 46},
    // June 
    {39, 38, 37, 36, 35, 34, 33, 35, 36, 38, 39, 40, 41, 39, 37, 36, 35, 33, 32, 34, 35, 36, 38, 39, 40, 39, 38, 37, 36, 35},
    // July 
    {33, 32, 31, 30, 29, 28, 30, 32, 33, 31, 30, 29, 28, 27, 28, 30, 32, 34, 35, 33, 32, 31, 30, 29, 28, 27, 26, 28, 30, 31},
    // August 
    {32, 31, 30, 29, 30, 31, 32, 33, 34, 33, 32, 31, 30, 29, 28, 30, 32, 33, 34, 33, 32, 31, 30, 29, 28, 27, 29, 30, 31, 32},
    // September 
    {33, 34, 35, 36, 37, 36, 35, 34, 33, 32, 31, 30, 29, 30, 32, 34, 35, 36, 37, 36, 35, 34, 33, 32, 31, 30, 32, 33, 34, 35},
    // October
    {30, 29, 28, 27, 26, 27, 28, 29, 30, 31, 32, 30, 29, 28, 27, 26, 25, 26, 28, 29, 30, 31, 30, 29, 28, 27, 26, 25, 24, 26},
    // November 
    {24, 23, 22, 21, 20, 22, 24, 25, 26, 25, 24, 23, 22, 21, 20, 19, 18, 19, 20, 21, 22, 23, 24, 25, 24, 23, 22, 21, 20, 19},
    // December 
    {15, 14, 13, 12, 11, 13, 14, 15, 16, 15, 14, 13, 12, 11, 10, 9, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9}

};

int rf[WEEKS] = {45, 75, 50, 75, 45, 50, 60, 65, 100, 150, 175, 160, 165, 170, 160, 175, 160, 155, 160, 200, 300, 400, 450, 450, 650,750, 800, 850, 950, 1005, 1000, 900, 950, 1000, 800, 750, 600, 500, 400, 450, 300, 250, 275, 250, 200, 240, 275, 250, 150, 100, 75, 50};

char months[12][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

//functions 
void analyze();
void inputTemp();
void Games();

void Login();
void DisplayMenu();

//features
void ViewOver();
void FindMax(int arr[MONTHS][DAYS]);
void FindMin(int arr[MONTHS][DAYS]);
void FindAvg(int arr[MONTHS][DAYS]);
float CalcAvgMonth(int m);
void AvgAllMonths(int arr[MONTHS][DAYS]);
void Warnings(int n);
void MonthlyStats(int n);
void Graph(int n);
void Forecast(int m, int n);  
void Trend(int arr[MONTHS][DAYS] ,int n);
void Streak();
void Deviation();
void Seasonal_Analysis();
//deviation function
int DevMenu();

void SpecificTemp();
void CelToFah();
void FahtoCel();
void Days();
void Order();
void TempRange();

//Rainfall Functions
void Rain();
int rf_avg_m4(int i);
int rf_avg_m5(int i);
void report(int i, int rval);
void DisplayRain();
void FindAvgRain(float *pAvg);
void FindMinRain(int *pMin);
void FindMaxRain(int *pMax);
void Brief_Report();
void Overview();
void Alert();

//Games
void Quiz();
void GuessTemp();
void MemoryGame();

int MaxTemp_Year;
int MinTemp_Year;
float AvgTemp_Year;

int main()
  {
    system("cls");
    Login();
    int option;
    top:
    DisplayMenu();
    scanf("%d", &option);

    switch(option)
     {
        case 1 :
            analyze();
            goto top;
            break;
        case 2 : 
            inputTemp();
            goto top;
            break;
        case 3 : 
            Games();
            goto top;
            break;
        case 4 : 
            printf("Thank you .....\n");
            break;
        default : 
            printf("Enter Valid input\n");
    }
    return 0;
}

void Login()
  {
    char username[50];
    char password[50];

    label :
    printf("Enter Username : ");
    gets(username);
    printf("Enter Password : ");
    gets(password);

    if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0){
        printf(GREEN"Access Granted\n"RESET);
        Sleep(2);
    }
    else {
        printf(RED"Authentication Failed !! Invalid Username or Password\n"RESET);
        goto label;
    }
   }

void DisplayMenu()
  {
    system("clear");
    printf("%40c"GREEN"+----------------------------------------------+\n"RESET, a);
    printf("%40c""|          WELCOME TO THE CITY TEMPERATURE     |\n", a);
    printf("%40c""|             MONITORING SYSTEM                |\n", a);
    printf("%40c"GREEN"+----------------------------------------------+\n"RESET, a);
    printf("%40c""| " YELLOW "1. Analyze Data                              "RESET"|\n", a);
    printf("%40c""| " YELLOW "2. Input Data                                "RESET"|\n", a);
    printf("%40c""| " YELLOW "3. Play Games                                "RESET"|\n", a);
    printf("%40c""| " YELLOW "4. Exit Program                              "RESET"|\n", a);
    printf("%40c"GREEN"+----------------------------------------------+\n"RESET, a);
    printf("%40c""Please choose an option(1-4) : ", a);
  }

void analyze()
  {
    /*Various function we can implement here
          user can view data
        It will be interactive as well
      can see graphs / trends / avg temps and all*/

    system("cls");
    int choice;
    printf("%s\n", BLUE"------------Analysis Menu-----------\n"RESET);
    printf("=========================================\n");
    printf("     | " YELLOW"Options\n"RESET);
    printf("=========================================\n");
    printf("     |1. Overview of temperatures.\n");
    //printf("     |2. Find min temp.\n");
    //printf("     |3. Find avg temp.\n");
    //printf("     |4. Display Avg of all months.\n");
    printf("     |2. Warnings.\n");
    printf("     |3. Monthly Statistics.\n");
    printf("     |4. Forecasting.\n");
    printf("     |5. Current Trend.\n");
    printf("     |6. Deviations.\n");
    printf("     |7.Longest Streaks.\n");
    printf("     |8.Specifc Day Temp.\n");
    printf("     |9.Temperature unit conversion.\n");
    printf("     |10.Seasonal Analysis.\n");
    printf("     |11.Days Categorization.\n");
    printf("     |12.Order(Ascending/descending).\n");
    printf("     |13.Rainfall Data.\n");
    printf("     |14.Temperature Range.\n");
    printf("========================================\n");
    
    do
    {
        printf("Choose an option(1-17) : ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 17)
        printf(RED"Invalid choice. Enter a number between 1 to 17\n"RESET);
    } while (choice < 1 || choice > 17);

    switch(choice)
    {
        case 1 : 
            ViewOver();
            break;
        /*case 2 :
            FindMin(temp);
            break;
        case 3 : 
            FindAvg(temp);
            break;
        case 4 :
            AvgAllMonths(temp);
            break;*/
        case 2 : {
            int n;
            printf("Enter the month : ");
            scanf("%d", &n);
            Warnings(n - 1);
            break;
        }
        case 3 : {
            int n;
            printf("Enter the month : ");
            scanf("%d", &n);
            MonthlyStats(n - 1);
            break;
        }     
        case 4 : {
            int m,n;
            printf("Enter Month and Date : ");
            scanf("%d %d", &m, &n);
            Forecast(m ,n);
            break;
        }                
        case 5 : {
            int n;
            printf("Enter the month : ");
            scanf("%d", &n);
            Trend(temp, n - 1);
            break;
        }
         case 6 :     
            Deviation();
            break;
        case 7 : 
            system("cls");
            Streak();
            break;
        case 8 :
            SpecificTemp();
            break;
        case 9 : {
            system("cls");
            printf("----------------------------------------\n");
            printf("          TEMPERATURE CONVERTOR         \n");
            printf("----------------------------------------\n");
            int choice;
            printf("1.Celsius to Fahrenhiet.\n");
            printf("2.Fahrenheit to Celsius.\n");
            printf("Choose an option : ");
            scanf("%d", &choice);

            if(choice == 1)
            CelToFah();

            if(choice == 2)
            FahtoCel();

            break;
        }
        case 10 : 
            Seasonal_Analysis();
            break;
        case 11 : 
            Days();
            break;
        case 12 : 
            Order();
            break;
        case 13 : 
            Rain();
            break;
        case 14 : 
            TempRange();
            break;
        default : 
            printf("Enter valid choice ");
    }

    char ch;
    printf("Do you want to continue Analysis?(Y/N) : ");
    scanf(" %c", &ch);
    if(ch == 'Y')
    analyze();
}

void ViewOver(){
       FindMax(temp);
       FindMin(temp);
       FindAvg(temp);
       AvgAllMonths(temp);
    }
    
void inputTemp(){
    /*Ask data inputs of multiple months and store it into some diff array
    Then can also give an option to analyze this data and we can call analyze() here as well
    we can keep input section for only admin by implementing user authentication*/
    printf("Still in progress.\n");
    Sleep(5);
}

void Games(){
    int n;
    label1:
    printf("1.Trivia quiz.\n");
    printf("2.Guess the Temperature\n");
    printf("3.Memory Game\n");
    printf("4.Exit\n");
    
    printf("Choose an option : ");
    scanf("%d", &n);

    switch(n){
        case 1 : 
            Quiz();
            goto label1;
            break;
        case 2 :
            GuessTemp();
            goto label1;
            break;
        case 3 :
            MemoryGame();
            goto label1;
            break;
        case 4 :
            break;
        default:
            printf("choose correct a number between 1-4\n");
            goto label1;
            break;
    }
}

void Quiz() {
    int score = 0,answer;
    printf(BLUE"-------------- Welcome to the quiz!!--------\nThere will be five questions.Each correct answer rewards 1 point.\n\n\n"RESET);

    printf("Question 1 : What is considered the freezing point of water in Celsius?\n1.0C\n2.-10C\n3.10C\n4.100C\n");
    scanf("%d", &answer);
    if(answer == 1){
        printf(GREEN"Correct Answer\n"RESET);
        score++;
    }
    else
    printf(RED"Incorrect Answer!" RESET "The correct Answer is 1.0C\n");

    printf("Question 2 : Which Indian state is known for receiving the highest rainfall?\n1.Kerala\n2.Assam\n3.Meghalaya\n4.West Bengal\n");
    scanf("%d", &answer);
    if(answer == 3){
        printf(GREEN"Correct Answer\n\n"RESET);
        score++;
    }
    else
    printf(RED"Incorrect Answer!"RESET " The correct Answer is Meghalaya\n");

    printf("Question 3 : Which instrument is primarily used to measure air temperature?\n1.Barometer\n2.Thermometer\n3.Hygrometer\n4.Anemometer\n");
    scanf("%d", &answer);
    if(answer == 2){
        printf(GREEN"Correct Answer\n\n"RESET);
        score++;
    }
    else
    printf(RED"Incorrect Answer!"RESET "The correct Answer is Thermometer\n");

    printf("Question 4 : In what layer of Earth's atmosphere does most weather occur?\n1.Stratosphere\n2.Mesosphere\n3.Troposphere\n4.Thermosphere\n");
    scanf("%d", &answer);
    if(answer == 3){
        printf(GREEN"Correct Answer\n\n"RESET);
        score++;
    }
    else
    printf(RED"Incorrect Answer!"RESET "The correct Answer is Troposphere\n");

    printf("Question 5 : Which region in India experiences the largest diurnal (day-to-night) temperature variation?\n1.Thar Desert, Rajasthan\n2.Western Ghats\n3.Eastern Himalayas\n4.Coastal Andhra Pradesh\n");
    scanf("%d", &answer);
    if(answer == 1){
        printf(GREEN"Correct Answer\n\n"RESET);
        score++;
    }
    else
    printf(RED"Incorrect Answer!"RESET "The correct Answer is Thar Desert, Rajasthan\n");

    printf("Your score is : %d\n", score);
    printf("Thanks for playing\n");
}

void GuessTemp()
{
    int m,ans,guess,attempt = 0,choice;
    printf("1.Average Temperature of Month\n");
    printf("2.Random Temperature(0-50)\n");
    printf("Choose an option : ");
    scanf("%d", &choice);
    
    if(choice == 1){

        printf("Enter a month : ");
        scanf("%d", &m);

        ans = CalcAvgMonth(m);
        do{

            printf("Guess the Average temperature of %s: ", months[m - 1]);
            scanf("%d", &guess);
            attempt++;

            if(guess < ans)
            printf("Lower! try again\n");

            else if(guess > ans)
            printf("Higher! try again\n");

            else
            printf("Correct Guess!! the temperature was %d\n", ans);
        }while(guess != ans);
        printf("It took you %d attempts\n", attempt);
        GuessTemp();
    }
    if(choice == 2){
        srand(time(0));
        ans = rand() % 51;
        do{

        printf("Guess the temperature : ");
        scanf("%d", &guess);
        attempt++;
        
        if(guess < ans)
        printf("Lower! try again\n");

        else if(guess > ans)
        printf("Higher! try again\n");

        else
        printf("Correct Guess!! the temperature was %d\n", ans);
        }while(guess != ans);
        printf("It took you %d attempts\n", attempt);
        GuessTemp();
        
    }
}

void MemoryGame()
{
    srand(time(0));
    int choice;
    int len = 5,flag = 0;

    printf("1.Temperature\n");
    printf("2.Months\n");
    printf("Choose a option : ");
    scanf("%d", &choice);

    if(choice == 1){
        int actualSeq[5], ans[5];
        for(int i = 0 ; i < len ; i++){
            int n = rand() % 46;
            printf("%d ", n);
            actualSeq[i] = n;
        }
        printf("\n");
        Sleep(5);
        system("cls");

        printf("Enter the Sequence now : \n");
        for(int i = 0 ; i < len ; i++){
            scanf("%d", &ans[i]);
        }

        for(int i = 0 ; i < len ; i++){
            if(actualSeq[i] != ans[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        printf("Incorrect\n");

        else
        printf("Correct\n");
    }
    /* if(choice == 2){
         char *actualSeq[len];
         char *ans[len];
         for(int i = 0 ; i < len ; i++){
             int n = rand() % 11;
             printf("%s\n", months[n][20]);
             strcpy(actualSeq[i] , months[n]);
         }
         printf("\n");
         Sleep(5000);
         system("cls");

         printf("Enter the Sequence now : \n");
         for(int i = 0 ; i < len ; i++){
             scanf("%s\n", &ans[i]);
        }

        for(int i = 0 ; i < len ; i++){
           if(strcmp(actualSeq[i], ans[i]) != 0){
                flag = 1;
                break;
             }
        }
        if(flag = 1)
         printf("Incorrect\n");

         else
       printf("Correct\n");
     }*/
    Sleep(2);
    DisplayMenu();
}

void FindMax(int temp[MONTHS][DAYS]){
        MaxTemp_Year = temp[0][0];
        int maxmonth ;
        int maxday ;
        for(int i = 0 ; i < MONTHS ; i++){
            for(int j = 0 ; j < DAYS ; j++){
                if(MaxTemp_Year < temp[i][j]){
                MaxTemp_Year = temp[i][j];
                maxmonth = i;
                maxday = j;
                }
            }
        }
        printf(YELLOW"Max temp in a year is : %d\n"RESET, MaxTemp_Year);
        printf(YELLOW"Recorded on : %s %d\n"RESET, months[maxmonth] , maxday + 1);
}

void FindMin(int temp[MONTHS][DAYS]){
    MinTemp_Year = temp[0][0];
    int minmonth;
    int minday;
    for(int i = 0 ; i < MONTHS ; i++){
        for(int j = 0 ; j < DAYS ; j++){
            if(MinTemp_Year > temp[i][j]){

            MinTemp_Year = temp[i][j];
            minmonth = i;
            minday = j;
            }
        }
    }
    printf(CYN"Min temp in a year is : %d\n"RESET, MinTemp_Year);
    printf(CYN"Recorded on : %s %d\n"RESET, months[minmonth] , minday + 1);
}

void FindAvg(int temp[MONTHS][DAYS]){
    int sum = 0;
    for(int i = 0 ; i < MONTHS ; i++){
        for(int j = 0 ; j < DAYS ; j++){
            sum += temp[i][j];
        }
    }
    AvgTemp_Year = (float)sum / (MONTHS * DAYS);
    printf(GREEN"Average temp of a year is : %.2f °C\n" RESET, AvgTemp_Year);
}

float CalcAvgMonth(int m){
    int sum = 0;
    for(int i = 0 ; i < DAYS ; i++){
        sum += temp[m - 1][i];
    }
    float avg = (float)sum / DAYS;
    return avg;
}

void AvgAllMonths(int arr[MONTHS][DAYS]){
    int sum[MONTHS] = {0};

    for(int i = 0 ; i < MONTHS ; i++){
        for(int j = 0 ; j < DAYS ; j++){
            sum[i] += temp[i][j];
        }
    }
    for(int i = 0 ; i < MONTHS ;i++){
        printf(GREEN"%-10s : %.2f\n"RESET, months[i] , (float)sum[i] / DAYS);
    }

    int w = 0, c = 0;
    float warm = (float)sum[0] / DAYS;
    float cold = (float)sum[0] / DAYS;
    for(int i = 1 ; i < MONTHS ; i++){
        if(warm < (float)sum[i] / DAYS){
            warm = (float)sum[i] / DAYS;
            w = i;
        }
       
        if(cold > (float)sum[i] / DAYS){
            cold = (float)sum[i] / DAYS;
            c = i;
        }
    }
    printf("\n\n");
    printf(YELLOW"The warmest month was %s : %.2f\n"RESET, months[w] , warm);
    printf(BLUE"The coldest month was %s : %.2f\n"RESET, months[c] , cold);
}

void Warnings(int n){
        int sum = 0,flag = 0;
        for(int j = 0 ; j < DAYS - 2;  j++){
        sum = temp[n][j] + temp[n][j + 1] + temp[n][j + 2];
        float avg = (float)sum / 3;

        if(avg >= 40){
            printf(RED"HEATWAVE detected at day : %d\n\a"RESET, j + 2 + 1);
           // Beep(750,300);
            flag = 1;
        }
        if(avg <= 10){
            printf(BLUE"COLDWAVE detected at day : %d\n\a"RESET, j + 2 + 1);
            //Beep(750,300);
            flag = 1;
        }
    }
    if(flag == 0)
    printf("No warnings detected.\n");
 
}

void MonthlyStats(int n){
    int max = temp[n][0];
    int min = temp[n][0];
    int sum = 0;

    for(int j = 0 ; j < DAYS ; j++){
        sum += temp[n][j];
        
        if(max < temp[n][j])
        max = temp[n][j];

        if(min > temp[n][j])
        min = temp[n][j];
    }
    float avg = (float)sum / DAYS;
    printf(RED"Maximum Temp is : %d\n"RESET, max);
    printf(BLUE"Minimum Temp is : %d\n"RESET, min);
    printf(GREEN"Average Temp is : %.2f\n"RESET, avg);

    printf("\n\n");
    char ch;
    printf(YELLOW"Do you want Graphical Representation(Y/N) : "RESET);
    scanf(" %c", &ch);

    if(ch == 'Y')
    Graph(n);

    else
    printf("Thank you !!\n");  
}

void Graph(int n){
    printf(BLUE"Graphical Representation for Month of %s : \n"RESET, months[n]);
    printf("-----------------------------------------------\n");
    for(int i = 0 ; i < DAYS ; i++){
        printf("Day %2d : ", i + 1);
        for(int j = 0 ; j < temp[n][i]; j++){
            printf("*");
        }
        printf(" %d", temp[n][i]);
        printf("\n");
    }
    printf("------------------------------------------------\n");
    int sum = 0;
    float avg;
    for(int i = 0 ; i < DAYS ; i++){
        sum += temp[n][i];
    }
    avg = (float)sum / DAYS; 
    printf("Average temperature of %s is %.2f C\n", months[n] , avg);
    printf("------------------------------------------------\n");
}

void Forecast(int m, int n){
    float sum_x = 0 ,sum_y = 0 , sum_xy = 0, sum_x2 = 0;
    for(int i = 0 ; i < DAYS ; i++){
        sum_x += i + 1;
        sum_y += temp[m - 1][i];
        sum_xy += (i + 1) * temp[m - 1][i];
        sum_x2 += (i + 1) * (i + 1);
    } 

    float M = (DAYS * sum_xy - sum_x * sum_y) / (DAYS * sum_x2 - sum_x * sum_x);
    float c = (sum_y - M * sum_x) / DAYS;

    float prediction = M * (DAYS + 1) + c;
    printf(BLUE"-------------------------------------------------------\n"RESET);
    printf(GREEN"Predicted Temperature of the day : %.2f\n"RESET, prediction);
    printf(GREEN"Actual Temperature of the day : %d\n"RESET, temp[m - 1][n - 1]);
    printf(BLUE"-------------------------------------------------------\n"RESET);
}

void Trend(int temp[MONTHS][DAYS], int n){
    int sum1 = 0,sum2 = 0;
    for(int i = 0 ; i < DAYS ; i++){
        sum1 += temp[n][i];
    }
    for(int i = 0 ; i < DAYS ; i++){
        if(n != 0)
        sum2 += temp[n - 1][i];     //condition for boundary checking (basically jan)
        
        else
        sum2 += temp[n + 11][i];                                           
    }
    float avg1 = (float)sum1 / DAYS;
    float avg2 = (float)sum2 / DAYS;

    //SetConsoleOutputCP(CP_UTF8);
    if(avg1 > avg2){
        printf(GREEN"Current month's Average : %.2f\n"RESET, avg1);
        printf(GREEN"Previous month's Average : %.2f\n"RESET, avg2);
        printf(GREEN"It is "RED"warming \U0001F321 \U0001F321 \U0001F321\n"RESET);
    }
    else if(avg1 < avg2){
        printf(GREEN"Current month's Average : %.2f\n"RESET, avg1);
        printf(GREEN"Previous month's Average : %.2f\n"RESET, avg2);
        printf(GREEN"It is "BLUE"cooling \U00002744 \U00002744 \U00002744\n"RESET);
    }
    else{
        printf(GREEN"Current month's Average : %.2f\n"RESET, avg1);
        printf(GREEN"Previous month's Average : %.2f\n"RESET, avg2);
        printf(GREEN"The temperature remained same\n"RESET);
    }
   
}

void Streak(){
    int max_hot = 0,counthot = 0;
    int max_cold = 0,countcold = 0;
    for(int i = 0 ; i < MONTHS ; i++){
        for(int j = 0 ; j < DAYS ; j++){
            if(temp[i][j] > 35)
            counthot++;

            else{
                if(counthot > max_hot)
                max_hot = counthot;

                counthot = 0;
            }

            if(temp[i][j] < 10)
            countcold++;

            else{
                if(countcold > max_cold)
                max_cold = countcold;

                countcold = 0;
            }
        }
    }
    printf("Longest streak of "RED"Hot days(above 35C)"RESET" in a year was : %d\n", max_hot);
    printf("Longest streak of "BLUE"Cold days(Below 10C)"RESET" in a year was : %d\n", max_cold);
    printf("______________________________________________________________\n");
    
    char ch;
    do{
        printf("Do you want Streaks for month?(Y/N) : ");
        scanf(" %c", &ch);

        if(ch == 'N')
        break;
        
        int n;
        printf("Enter a month : ");
        scanf("%d", &n);

        int maxmhot = 0 , maxmcold = 0, counthm = 0, countcm = 0;
        for(int i = 0; i < DAYS ; i++){
            if(temp[n - 1][i] > 35)
            counthm++;

            else{
                if(counthm > maxmhot)
                maxmhot = counthm;

                counthm = 0;
            }

            if(temp[n - 1][i] < 10)
            countcm++;

            else{
                if(countcm > maxmcold)
                maxmcold = countcm;

                countcm = 0;
            }
        }

        printf("longest streak of "RED"Hot days(above 35C)"RESET"in a month was : %d\n", maxmhot);
        printf("Longest streak of "BLUE"Cold days(Below 10C)"RESET"in a month was : %d\n", maxmcold);
        printf("______________________________________________________________\n");
    }while(ch == 'Y' || ch == 'y');
}

void Deviation(){
        system("clear");
        int n = DevMenu();

        //calculations
        float sum,avg[12],diff[11],max,dev[12][30],sup=0,md[12];
        int i,j,p,q,r,maxmonth;

        for(i = 0; i < 12; i++){
        for(j = 0, sum = 0 ;j < 30; j++){
            sum += temp[i][j];
        }
        avg[i]=sum/30;
    }

    for( i = 0; i < 12; i++){
        for(j = 0; j < 30; j++){
            dev[i][j] = abs(temp[i][j] - avg[i]);
        }
    }
    
    for(i = 0; i < 12; i++){
        for(j = 0 ,sup = 0;j < 30; j++){
            if(sup < dev[i][j])
            sup = dev[i][j];
            md[i] = sup;
        }
    }
        
    for(i = 0; i <12; i++){
        for(j = 0; j < 30; j++){
            diff[i] = abs(avg[i] - avg[i + 1]);
        }
    }
    max=0;
    for(i = 1; i <= 11; i++){
        if(max < diff[i]){
            max = diff[i];
            maxmonth = i;
        }
    }

        switch(n){
            case 1 : {
                int m;
                printf("Enter the month : ");
                scanf("%d", &m);
                printf("Average Temperature of %s is %.2f\n", months[m - 1], avg[m - 1]);
                break;
            }
            case 2 :{
                int m;
                printf("Enter the month : ");
                scanf("%d", &m);
                printf("Maximum deviation from average Temperature of %s is %.2f\n", months[m - 1], md[m - 1]);
                break;
            }
            case 3 : {
                printf("Maximum deviation between consecutive months is %.2f\n", max);
                printf("Between %s and %s\n", months[maxmonth], months[maxmonth + 1]);
                break;
            }
            case 4 :{
                int m,d;
                printf("Enter the month and day to find the maximum deviation from the average temperature of the month: ");
                scanf("%d %d", &m, &d);
                printf("The deviation from the average temperature of the month is : %.2f\n", dev[m - 1][d - 1]);
                break;
            }
            default : 
            printf(RED"Enter Valid option\n"RESET);
            Sleep(1);
            system("cls");
            DevMenu();
        }
        
}

int DevMenu(){
    int choice;
    printf("%s\n", MAG"------------DEVIATION-----------\n"RESET);
    printf("=========================================\n");
    printf("     | " YELLOW"Options\n"RESET);
    printf("=========================================\n");
    printf("     |1. Average Temperature of Month \n");
    printf("     |2. Maximum deviation from Average Temperature\n");
    printf("     |3. Maximum deviation between consecutive months\n");
    printf("     |4. Deviaton of particular day\n");
    
    printf("Choose a option : ");
    scanf("%d", &choice);

    return choice;

}
void SpecificTemp(){
    int m,d;

    do{
        printf("Enter Month(1-12) and Date(1-30) : ");
        scanf("%d %d", &m, &d);

        if(m < 1 || m > 12){
            printf(RED"Invalid Month! Enter a number between 1 to 12\n"RESET);
            continue;
        }

        if(d < 1 || d > 30){
            printf(RED"Invalid Day! Enter a number between 1 to 30\n"RESET);
            continue;
        }
        else
        break;
    }while(m < 1 || m > 12 || d < 1 || d > 30);

    int flag = 0;
    for(int i = 0 ; i < MONTHS ; i++){
        for(int j = 0; j < DAYS ; j++){
            if(i == m - 1 && j == d - 1){
                printf(GREEN"Temperature on %s %d is : %d\n"RESET,months[m - 1], d , temp[i][j]);
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        break;
    }
}

void CelToFah(){
    char ch;
    do{
        int n;
        printf("Enter the temperature in Celsius : ");
        scanf("%d", &n);

        float fah = ((float)9/5 * n) + 32;
        printf("------------------------------------\n");
        printf("%dC is %.2fF\n"RESET, n ,fah); 
        printf("-------------------------------------\n"); 
        
        printf("Do you want to convert another temperature?(Y/N) : ");
        scanf(" %c", &ch);
    }while(ch == 'Y' || ch == 'y');

    printf(GREEN"Thank you for using temperature convertor !!\n"RESET);
    printf("==============================================\n");
}

void FahtoCel(){
    char ch;
    do{
        int n;
        printf("Enter the temperature in Fahrenheit : ");
        scanf("%d", &n);

        float cel = (float)5/9 * (n - 32);
        printf("------------------------------------\n");
        printf("%dF is %.2fC\n", n, cel);    
        printf("-------------------------------------\n");

        printf("Do you want to convert another temperature?(Y/N) : ");
        scanf(" %c", &ch);
    } while(ch == 'Y' || ch == 'y');

    printf(GREEN"Thank you for using temperature convertor !!\n"RESET);
    printf("==============================================\n");
}

//Seasonal analysis 
void Days(){
    char choice;
    do {
        int Cold = 0, Moderate = 0, Hot = 0 ,Extreme = 0;
        int n;
        printf("1.Whole year.\n");
        printf("2.Specific Month.\n");
        printf("Choose a category : ");
        scanf("%d", &n);

        if(n == 1){
            for(int i = 0 ; i < MONTHS ; i++){
                for(int j = 0 ; j < DAYS ; j++){
                    if(temp[i][j] <= 10)
                    Cold++;

                    else if(temp[i][j] > 10 && temp[i][j] <= 25)
                    Moderate++;

                    else if(temp[i][j] > 25 && temp[i][j] <= 40)
                    Hot++;

                    else if(temp[i][j] > 40)
                    Extreme++;
                }
            }
        }
        else if(n == 2){
            int m;
            printf("Enter a Month : ");
            scanf("%d", &m);

            for(int j = 0 ; j < DAYS ; j++){
                if(temp[m - 1][j] <= 10)
                Cold++;

                else if(temp[m - 1][j] > 10 && temp[m - 1][j] <= 25)
                Moderate++;

                else if(temp[m - 1][j] > 25 && temp[m - 1][j] <= 40)
                Hot++;

                else if(temp[m - 1][j] > 40)
                Extreme++;
            }
        }
        printf(BLUE"Cold Days : %d\n"RESET, Cold);
        printf(GREEN"Moderate Days : %d\n"RESET, Moderate);
        printf(YELLOW"Hot Days : %d\n"RESET, Hot);
        printf(RED"Extreme Days : %d\n"RESET, Extreme);

        printf("Do you want to continue? (Y/N)\n ");
        scanf(" %c", &choice);
        
            if(choice != 'Y')
            printf("Thank you!\n");
    } while(choice == 'Y');
}

void Order(){
    int n;
    printf("1.Yearly order.\n");
    printf("2.Monthly Order.\n");
    printf("Choose an option : ");
    scanf("%d", &n);

    if(n == 1){
        float avg[12],count[12];
        for(int i = 0; i < MONTHS ; i++){
            int sum = 0;
            for(int j = 0 ; j < DAYS ; j++){
                sum += temp[i][j];
            }
            avg[i] = (float)sum / DAYS;
            count[i] = i;
        }
        for(int i = 0 ; i < MONTHS - 1 ; i++){
            for(int j = 0 ; j < MONTHS - i - 1 ; j++){
                if(avg[j] > avg[j + 1]){
                    int temp = avg[j];
                    avg[j] = avg[j + 1];
                    avg[j + 1] = temp;

                    int temp2 = count[j];
                    count[j] = count[j + 1];
                    count[j + 1] = temp2;
                }
            }
        }
        printf(YELLOW"--------------------------------------------\n"RESET);
        for(int i = 0 ; i < MONTHS ; i++){
            int x = count[i];
            printf(GREEN"%-10s : %.2f\n"RESET, months[x] , avg[i]);
        }
        printf(YELLOW"--------------------------------------------\n"RESET);
    }

    if(n == 2){
        int m;
        printf("Enter a month(1-12) : ");
        scanf("%d", &m);

        int count[30];
        for(int i = 0 ; i < 30 ; i++){
            count[i] = i;
        }

        for(int i = 0 ; i < DAYS ; i++){
            for(int j = 0 ; j < DAYS - i - 1 ; j++){
                if(temp[m - 1][j] > temp[m - 1][j + 1]){
                    int t = temp[m - 1][j];
                    temp[m - 1][j] = temp[m - 1][j + 1];
                    temp[m - 1][j + 1] = t;

                    int t2 = count[j];
                    count[j] = count[j + 1];
                    count[j + 1] = t2;
                }
            }
        }
        printf(YELLOW"--------------------------------------------\n"RESET);
        for(int i = 0 ; i < DAYS ; i++){
            int x = count[i]; 
            printf(GREEN"Day %2d : %d\n"RESET, x + 1, temp[m - 1][i]);
        }
        printf(YELLOW"--------------------------------------------\n"RESET);
    }
}

void TempRange(){
    int m;
    do{
        printf("Enter the month : ");
        scanf("%d", &m);

        if(m >= 1 && m <= 12)
        break;

        else
        printf(RED"Invalid Month!! please enter number between 1 to 12.\n"RESET);
    } while(m < 1 || m > 12);

    int max = temp[m - 1][0];
    int min = temp[m - 1][0];
    for(int i = 0 ; i < DAYS ; i++){
        if(max < temp[m - 1][i])
        max = temp[m - 1][i];

        if(min > temp[m - 1][i])
        min = temp[m - 1][i];
    }
    printf(GREEN"------------------------------------------------\n"RESET);
    printf(GREEN"Temperature Range for %s is from : %d to %d\n"RESET, months[m - 1], min , max);
    printf(GREEN"------------------------------------------------\n"RESET);
}

void Rain(){
    int x;
    char choice;
    do{
    Sleep(2);
    system ("cls");
 
    printf("%s\n", BLUE"------------RAINFALL-----------\n"RESET);
    printf("=========================================\n");
    printf("     | " YELLOW"Options\n"RESET);
    printf("=========================================\n");
    printf("     |1. Overview\n");
    printf("     |2. Brief Report\n");
    printf("     |3. Alerts\n");
    
    do{
        printf("Choose an option(1-3) : ");
        scanf("%d", &x);

        if(x < 1 || x > 3)
        printf(RED"Invalid choice. Enter a number between 1 to 3\n"RESET);
    } while (x < 1 || x  > 3);

   
    switch(x){
        case 1 : 
            Overview();
            break;
        case 2 :
            Brief_Report();
            break;
        case 3 :
            Alert();
            break;
        default : 
            printf("Invalid choice \n");
    }

    printf("Do you want to continue? (Y/N)\n ");
    scanf(" %c", &choice);
    
        if(choice != 'Y')
        printf("Thank you!\n");

    }while(choice == 'Y');
}

int rf_avg_m4(int i){ 
    int sum = 0 , k;
    float rf_avg = 0;

    for(k = i; k < i+4; k++){ 
        sum=sum+rf[i-1];
    }
    rf_avg = (float)sum/4;
    return rf_avg;
}

int rf_avg_m5(int i){ 
    int sum=0,k;
    float rf_avg=0;

    for( k = i ; k < i + 5 ; k++){ 
        sum=sum+rf[i-1];
    }
    rf_avg = sum/5.0;
    return rf_avg;
}

void report(int i, int rval){
    int sum = 0, j, flag = 0;
    float avg;
    for(j = 0; j < 30; j++){
        sum = temp[i - 1][j] + sum;
    }
    avg = sum/30.0;
    
    if(avg > 25.00 && rval > 700){
        flag = 1;
        printf("Your Month is humid.\n");
    }
    if(avg < 20.00 && rval < 300){
        flag = 1;
        printf("Your Month is dry.\n");
    }
    if(flag != 1){
        printf("Your week is moderate not too dry and not too humid.\n");
    }
}

void DisplayRain(){
   // SetConsoleOutputCP(CP_UTF8);
    for(int i = 0 ; i < 52 ; i++){
        printf("Week %d : ", i + 1);

        for(int j = 1; j <= rf[i]/30; j++)
        printf("\U0001F327 ");   //change to utf-8
            
        printf("\n");
    }       
}

void FindAvgRain(float *pAvg){
    int sum = 0;
    for(int i = 0 ; i < WEEKS ;i++){
        sum += rf[i];
    }
    *pAvg = (float)sum / WEEKS;
}

void FindMinRain(int *pMin){
    *pMin = rf[0];
    for(int i = 0 ; i < WEEKS ;i++){
        if (*pMin > rf[i])
        *pMin = rf[i];
    }
}

void FindMaxRain(int *pMax){
    *pMax = rf[0];   
    for(int i = 0 ; i < WEEKS ;i++){
        if(*pMax < rf[i])
        *pMax = rf[i];
    }   
}

void Brief_Report(){ 
    int flag=0;
    do{
    int month;
    printf("Enter the month for which you want a report: \n");
    scanf("%d", &month);

    switch(month){
        case 1 : { 
            int rval = rf_avg_m5(1);
            report(month, rval);  
            break;      
        }
        case 2 : { 
            int rval = rf_avg_m4(6);
            report(month, rval);  
            break;      
        }
        case 3 :{ 
            int rval = rf_avg_m4(10);
            report(month, rval);  
            break;      
        }
        case 4 :{ 
            int rval = rf_avg_m4(14);
            report(month, rval);  
            break;      
        }
        case 5 :{ 
            int rval = rf_avg_m5(18);
            report(month, rval);  
            break;      
        }
        case 6 :{ 
            int rval = rf_avg_m4(23);
            report(month, rval);  
            break;      
        }
        case 7 :{ 
            int rval = rf_avg_m5(27);
            report(month, rval);  
            break;      
        }
        case 8 :{ 
            int rval = rf_avg_m4(32);
            report(month, rval);  
            break;      
        }
        case 9 :{ 
            int rval = rf_avg_m4(36);
            report(month,rval);  
            break;      
        }
        case 10 :{ 
            int rval = rf_avg_m5(40);
            report(month, rval);  
            break;      
        }
        case 11 :{ 
            int rval = rf_avg_m4(45);
            report(month, rval);  
            break;      
        }
        case 12 :{ 
            int rval = rf_avg_m4(49);
            report(month, rval);  
            break;      
        }
        default:
           printf("Invalid Month.\n");
           flag = 1;
           break;             
    }
   }while(flag == 1);
}

void Overview(){
    int Min, Max;
    float Avg;
    FindMinRain(&Min);
    FindMaxRain(&Max);
    FindAvgRain(&Avg);
    printf("Min Rainfall in this year is : %d mm\n", Min);
    printf("Max Rainfall in this year is : %d mm\n", Max);
    printf("Average rainfall of this year is : %.2f mm\n", Avg);
        
    char ch;
    printf(BLUE"Do you want Graphical Representation(Y/N) : "RESET);
    scanf(" %c", &ch);

    if (ch == 'Y' || ch == 'y'){ 
        system("cls");
        DisplayRain();
    }
}

void Alert(){
    int d = 0;
    do{
        printf("Enter the week for which you want Alerts : ");
        scanf("%d", &d);

        if(d < 1 || d > 52){ 
            printf("Invalid week\n");
        }
        if( rf[d-1] > 900){
            printf(RED"There is chance of flood.\n\a"RESET);
        }
        else 
        printf(GREEN"No chance of floods\n"RESET);

        }while(d < 1 || d > 52);
}

void Seasonal_Analysis(){
char choice;
do { 
float sum,avg[12],diff[11],max,s1,s2,s3,s4;
int i,j,n,p,k=0;

for (i=0;i<12;i++) 
{
    for (j=0, sum=0;j<30;j++)
    {
        sum+=temp[i][j];
    }
    avg[i]=sum/30;
   
}
s1=(avg[11]+avg[0]+avg[1])/3;
s2=(avg[2]+avg[3]+avg[4])/3;
s3=(avg[5]+avg[6]+avg[7]+avg[8])/4;
s4=(avg[9]+avg[10])/2;

int a,b,c,d;
printf("The Indian Meteorological Department (IMD) divides the year into four seasons, each with its own months:\n");
printf("------------------------------------------------\n");
printf("1.Winter: December to February\n2.Summer: March to May\n3.Monsoon: June to September\n4.Post-monsoon: October to November\n");
printf("------------------------------------------------");
printf("\nEnter 1 if you want to analyze WINTER season\nEnter 2 if you want to analyze SUMMER season\nEnter 3 if you want to analyze MONSOON season\nEnter 4 if you want to analize POST MONSOON season:\n");
scanf("%d", &a);
switch(a){
    case 1 :
    printf("\nTHIS IS THE ANALYSIS OF WINTER SEASON:\n");
    printf("\n------------------------------------------------\n");
    printf("Average temperature of WINTER SEASON IS:%fC", s1);
    printf("\nAverage temperatures of individual months:\nDECEMBER:%fC\nJANUARY:%fC\nFEBRUARY:%fC\n", avg[11],avg[0],avg[1]);
    printf("\nThe maximum temperature of this season is 21C ");
    printf("\nThe minimum temperature of this season is 7C ");
    printf("\nGraphical representation of variation of temperature in this season:\n");

   printf("DECEMBER\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[11][j];k++)
        {
        printf("*");
    }
    printf("\n");}
printf("\nJANUARY\n");
for(j=0;j<30;j++)
    {
        for(k=0;k<temp[0][j];k++)
        {
        printf("*");
    }
    printf("\n");}
printf("\nFEBRUARY\n");
for(j=0;j<30;j++)
    {
        for(k=0;k<temp[1][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    break;
    case 2 :
     printf("\nTHIS IS THE ANALYSIS OF SUMMER SEASON:\n");
    printf("\n------------------------------------------------\n");
    printf("Average temperature of SUMMER SEASON IS:%fC", s2);
    printf("\nAverage temperatures of individual months:\nMARCH:%fC\nAPRIL:%fC\nMAY:%fC\n", avg[2],avg[3],avg[4]);
    printf("\nThe maximum temperature of this season is 48C ");
    printf("\nThe minimum temperature of this season is 22C");
    printf("\nGraphical representation of variation of temperature in this season:\n");
    printf("\nMARCH\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[2][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    printf("\nAPRIL\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[3][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    printf("\nMAY\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[4][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    break ;
    case 3:
         printf("\nTHIS IS THE ANALYSIS OF MONSOON SEASON:\n");
    printf("\n------------------------------------------------\n");
    printf("Average temperature of SUMMER SEASON IS:%fC", s3);
    printf("\nAverage temperatures of individual months:\nJUNE:%fC\nJULY:%fC\nAUGUST:%fC\nSEPTEMBER:%f\n", avg[5],avg[6],avg[7], avg[8]);
    printf("\nThe maximum temperature of this season is 41C ");
    printf("\nThe minimum temperature of this season is 26C");
    printf("\nGraphical representation of variation of temperature in this season:\n");
    printf("\nJUNE\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[5][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    printf("\nJULY\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[6][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    printf("\nAUGUST\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[7][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    printf("\nSEPTEMBER\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[8][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    break ;
    case 4 :
    printf("\nTHIS IS THE ANALYSIS OF POST MONSOON SEASON:\n");
    printf("\n------------------------------------------------\n");
    printf("Average temperature of POST MONSOON SEASON IS:%fC", s4);
    printf("\nAverage temperatures of individual months:\nOCTOBER:%fC\nNOVEMBER:%fC\n", avg[9],avg[10]);
    printf("\nThe maximum temperature of this season is C ");
    printf("\nThe minimum temperature of this season is C ");
    printf("\nGraphical representation of variation of temperature in this season:\n");

   printf("OCTOBER\n");
    for(j=0;j<30;j++)
    {
        for(k=0;k<temp[9][j];k++)
        {
        printf("*");
    }
    printf("\n");}
printf("\nNOVEMBER\n");
for(j=0;j<30;j++)
    {
        for(k=0;k<temp[10][j];k++)
        {
        printf("*");
    }
    printf("\n");}
    break;
    default:
    printf("ENTER A VALID NUMBER");
 }
  printf("Do you want to continue? (Y/N)\n ");
    scanf(" %c", &choice);
    
        if(choice != 'Y')
        printf("Thank you!\n");

    }while(choice == 'Y');
 }
