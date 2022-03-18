 /**
 * @file array_struct.c
 *
 * @author Stephen Jurgensen
 *
 * @date 2022 March 11

 * @brief This program implements fucntions that act on a struct of demographic
 *  info.
 *
 * @details This program implements these fucntions: 
 *      init_array()
 *      print()
 *      init_array()
 *      min_age()
 *      max_age()
 *      min_height()
 *      max_height()
 *      average_age()
 *      average_height()
 */
#include "array_struct.h"
#include <stdio.h>
#include <stddef.h>


int main(void)
{

	struct data_t data[SIZE];
        size_t size = sizeof(data)/sizeof(struct data_t);

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);

        int min_age_index = min_age(data, size);
        int max_age_index = max_age(data, size);
        int min_height_index = min_height(data, size);
        int max_height_index = max_height(data, size);
        printf("Stucture that corresponds to the minimum age:\n");
        print(data, min_age_index);
        printf("Stucture that corresponds to the maximum age:\n");
        print(data, max_age_index);
        printf("Stucture that corresponds to the minimum height:\n");
        print(data, min_height_index);
        printf("Stucture that corresponds to the maximum height:\n");
        print(data, max_height_index);

        double the_average_age = average_age(data, size);
        double the_average_height = average_height(data, size);
        printf("The average age:      %.1f\n", the_average_age);
        printf("The average height:   %.1f\n", the_average_height);

	return 0;
}
/* 
* Prints the single structure by its index. 
* @param data[] is the array of stuctures.
* @param index is the sturture's index that is printed.
* @return void. 
*/
void print(struct data_t data[], int index)
{
        printf("data[%d]:\n", index);
        printf("        subject: %c\n", data[index].subject);
        printf("        age:     %d\n", data[index].age);
        printf("        height:  %d\n", data[index].height);
}
/* 
* Initializes the data at one index in an array of stuctures. 
* @param index is the array index where the data is added
* @param id the subject in the stucture
* @param years is the age in the stucture
* @param inches is the height in the stucture
* @param data[] is the stucture array being updated.
* @return void. 
*/
void init_array(struct data_t data[], int index, char id, int years, 
        int inches)
{
        data[index].subject = id;
        data[index].age = years;
        data[index].height = inches;
}
/* 
* Finds the index of struct with the min age. 
* @param data[] is the array of stucture being searched.
* @param size is the number of stuctures in the array.
* @return index's integer. 
*/
int min_age(struct data_t data[], size_t size){
        int min = data[0].age, index_m = 0, i; 
        for (i = 1; i < size; i++)
        {
                if (min > data[i].age)
                {
                        min = data[i].age;
                        index_m = i;
                }
        }
        return index_m;
}
/* 
* Finds the index of struct with the max age. 
* @param data[] is the array of stucture being searched.
* @param size is the number of stuctures in the array.
* @return index's integer. 
*/
int max_age(struct data_t data[], size_t size){
        int max = data[0].age, index_m = 0, i; 
        for (i = 1; i < size; i++)
        {
                if (max < data[i].age)
                {
                        max = data[i].age;
                        index_m = i;
                }
        }
        return index_m;
}
/* 
* Finds the index of struct with the min height. 
* @param data[] is the array of stucture being searched.
* @param size is the number of stuctures in the array.
* @return index's integer. 
*/
int min_height(struct data_t data[], size_t size){
        int min = data[0].height, index_m = 0, i; 
        for (i = 1; i < size; i++)
        {
                if (min < data[i].height)
                {
                        min = data[i].height;
                        index_m = i;
                }
        }
        return index_m;
}
/* 
* Finds the index of struct with the max height. 
* @param data[] is the array of stucture being searched.
* @param size is the number of stuctures in the array.
* @return index's integer. 
*/
int max_height(struct data_t data[], size_t size){
        int max = data[0].height, index_m = 0, i; 
        for (i = 1; i < size; i++)
        {
                if (max < data[i].height)
                {
                        max = data[i].height;
                        index_m = i;
                }
        }
        return index_m;
}
/* 
* Finds the average of the age. 
* @param data[] is the array of stucture being searched.
* @param size is the number of stuctures in the array.
* @return index's integer. 
*/
double average_age(struct data_t data[], size_t size){
        int sum = 0, i; 
        for (i = 0; i < size; i++)
        {
                sum = sum + data[i].age;
        }
        return (double) sum / size;
}
/* 
* Finds the average of the age. 
* @param data[] is the array of stucture being searched.
* @param size is the number of stuctures in the array.
* @return index's integer. 
*/
double average_height(struct data_t data[], size_t size){
        int sum = 0, i; 
        for (i = 0; i < size; i++)
        {
                sum = sum + data[i].height;
        }
        return (double) sum / size;
}
