/**
 * @file departure_time_checker.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2019 Feb 7
 *
 * @brief This program implements a departure-time check, printing the closest
 *  departure time from the user’s inputted time. 
 *
 * @details This program uses three arrays of the data, which represent eight 
 *      departure times in 12-hour format. Then it calculates the time from midnight
 *      in minutes for each of the eight times, storing each minute-value in an array. It then 
 *      takes input in the form of 24-hour time and it calculates the time in minutes 
 *      from midnight. This user input is checked against departure times in a 
 *      for-loop using the absolute value of the difference. A switch statement prints 
 *      the corresponding departure time. 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int i = 0;
        int test_hour;
        int test_minute;
        int test_min_from_midnight;
        int time_diff;
        int shortest_time;
        int postion=0;
        int dpt_hours[8] =      {8,9,11,12,2,3,7,9};
        int dpt_min[8] =        {0,43,19,47,0,45,0,45};
        int dpt_diurnal[8] =  {'a.m.', 'a.m.','a.m.','p.m.','p.m.','p.m.','p.m.','p.m.',};     
        int dpt_min_from_midnight[8];

        // Departures times are converted to minutes from midnight
        //      and stored in an array. 
        for(i = 0; i < 8; i++){
                if (dpt_diurnal[i] == 'a.m.' && (dpt_hours[i] != 12)){
                        dpt_min_from_midnight[i] = (dpt_hours[i] * 60) + dpt_min[i];
                } else if ((dpt_diurnal[i] == 'p.m.') && (dpt_hours[i] != 12))
                        dpt_min_from_midnight[i] = ((dpt_hours[i] + 12) * 60) + dpt_min[i];
                else
                    dpt_min_from_midnight[i] = (dpt_hours[i] * 60) + dpt_min[i];  
        }

        printf("\nEnter a 24-hour departure time (HH:MM format): ");
        scanf("%02d:%02d", &test_hour, &test_minute);

        // Caclulate time from midnight and find closet-departure
        //      time's postion in the array.  
        test_min_from_midnight = (test_hour * 60) + test_minute;
        shortest_time = 1440;
        for(i = 0; i < 8; i++){
                time_diff = dpt_min_from_midnight[i] - test_min_from_midnight;
                if ((abs(time_diff)) <= shortest_time) {
                        shortest_time = abs(time_diff);
                        postion = i;
                }
        }

        //Based on postion in the array, print the departure time. 
        switch (postion)
        {
        case 0:
                printf("Closest departure time is 8:00 a.m., arriving at 10:16a.m.");
                break;
        case 1:
                printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.");
                break;
        case 2:
                printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.");
                break;
        case 3:
                printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.");
                break;
        case 4:
                printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.");
                break;
        case 5:
                printf("Closest departure time is 3:45 p.m , arriving at 5:55 p.m.");
                break;
        case 6:
                printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.");
                break;
        case 7:
                printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.");
                break;
        default:
                printf("There are no flights within the day");
                break;
        }
        printf("\n\n");
        return 0;
}
