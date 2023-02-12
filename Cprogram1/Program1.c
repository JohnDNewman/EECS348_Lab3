/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: j087n641
 */


#include <stdio.h>
#include <malloc.h>

//Provided by TA
float *read_data_from(char *filename){
	//12 months so 12 years
	const int months = 12;
	// Allocate data for 12 floats in month sales data
	float* month_sales_data = (float*)malloc(sizeof(float) * months);
	//OPen file with given filename
	FILE *fp = fopen(filename, "r+");

	//If no file exists, complain about it
	if (fp == NULL){
		printf("Check filename");
	}

	//For each of the 12 lines, add to month sales at the ith index
	for( int i=0;i<months; ++i){
		fscanf(fp, "%f", &month_sales_data[i]);
	}
	//return the found data
	return month_sales_data;
}

//Function to calculate minimum of the sales list
float minimum_of_list(float *sales_list){
	// 12 months, had weird issues with tmp being used in multiple place causing errors and im too lazy to fix it
	//Thus, define timp
    const int months = 12;
    float timp = sales_list[0];

	// For every index
    for(int i = 0; i < months;i++){
		//If entry is less than the current min, replace min with it
        if (sales_list[i] < timp){
           timp = sales_list[i];
        }
    }
	//Return final min
    return timp;
}

//Function to calculate maximum of sales list
float maximum_of_list(float *sales_list){
    //12 months, tamp for the same reason as line 35
    const int months = 12;
    float tamp = sales_list[0];

	//For every index
    for(int i = 0; i < months;i++){
		//If index is greater than current max, replace with it
        if (sales_list[i] > tamp){
           tamp = sales_list[i];
        }
    }

	//Return found max
    return tamp;
}

//Function to calculate maximum
float average_of_list(float *sales_list){
	// 12 months in the list
    const int months = 12;
	//initialize tmp as 0
    float tmp = 0.0;

	//For every value in array
    for(int i = 0; i < months;i++){
		//Add to tmp
        tmp = tmp + sales_list[i];
    }

	//Divide by num of months
    tmp = tmp/months;


	//return the final month
    return tmp;

}



int main() {
	//Theres a lot of months
	//List of months
    char* months[12]= {"January    ","February   ","March      ","April      ","May        ","June       ","July       ","August     ","September  ","October    ","November   ","December   "};
    //array of how long the names of months are
	int month_length[12] = {7 , 8 , 5 , 5 , 3 , 4 , 4 , 6 , 9 , 7 , 8 , 8};

	//index and holder variable
	int index = 0;
	int hold;

	//Create char for filename
	char filnam[100];

	printf("Enter file Name: ");
	//Get the name through scanf
	scanf("%s", filnam);

	//Get sales data from function
	float *months_sales_data = read_data_from(filnam);

	//Print format
    printf("Monthly sales report for 2022:\n\n");
    printf("Month      Sales\n\n");

	//For every index, print the value and month
	for(index = 0; index < 12; index++){
		printf( "%.11s$%.2f\n", months[index], months_sales_data[index]);
	}

	//Set minimum to minium of the list
	float minimum = minimum_of_list(months_sales_data);

	//Vars for the min month calc
	char* min_month;
	int min_month_length = 0;

	//compare each index to the min and return the one that matches so you get the month name and length
	for(index = 0; index < 12; ++index){
	    if (months_sales_data[index] == minimum){
	    	hold = index;
	        min_month = months[index];
	        min_month_length = month_length[index];

	    }

	}

	//Same as minimum but for maximum
	float maximum = maximum_of_list(months_sales_data);

	char* max_month;
	int max_month_length;

	for(index = 0; index < 12; index++){
	    if (months_sales_data[index] == maximum){
	        max_month = months[index];
	        max_month_length = month_length[index];

	    }
	}

	//Get average of sales list
	float average = average_of_list(months_sales_data);

	//Print format of sales summary
	printf("\nSales summary:\n\n");

	//Print min and max month with their names as lengths so the output is the same no matter the month
	printf("Minimum Sales:  $%.2f  (%.*s) \n", minimum, min_month_length, min_month);
	printf("Maximum Sales:  $%.2f  (%.*s) \n", maximum, max_month_length, max_month);
	printf("Average Sales:  $%.2f\n", average);

	//Six month moving average, cause why not
	printf("\n\nSix-Month Moving Average Report:\n\n");

	//DEfine a tmp var for calculation
    float tmp = 0.0;

	// 6 times, which is number of months minus the number of starting months
    for (int i = 0; i < 7; i++) {
		//add the next 6 values from the starting month
        for (int j = i; j < i + 6; j++) {
            tmp += months_sales_data[j];
        }
		//Print that stuff in a nice fashion and finish the caluclation in the statement
        printf("%s - %s$%.2f\n", months[i], months[i+5], tmp / 6);
		//reset tmp for next loop
        tmp = 0.0;
    }

	// Print format for max min listing
    printf("\n\nSales Report(Highest to Lowest):\n\n");
    printf("Month      Sales\n\n");

	//Temporaryly set tmp to above the max so we first get the max of the list when calculating
    tmp = maximum+1;

	//For the 12 months of the year
	for (int i=0;i<12;i++){
		//Set index to month of lowest profit
	    index = hold;
		//check every month
	    for(int j=0;j<12;j++){
			//If that month is less than the previous max
	        if (months_sales_data[j] < tmp){
				// And greater than every other month
	            if(months_sales_data[j] > months_sales_data[index]){
					//Make a note of that index
	                index = j;
	            }
	        }
	    }
		//set tmp to new value, which is the next highest after the last run
	    tmp = months_sales_data[index];
		//Print everything in a pretty fashion
	    printf( "%.11s$%.2f\n", months[index], months_sales_data[index]);
	}
	return 0;

}
