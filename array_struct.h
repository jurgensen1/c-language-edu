 /**
 * @file array_struct.h
 *
 * @author Stephen Jurgensen
 *
 * @date 2022 March 11
 *
 * @brief This is the header file for array_struct.c
 * 
 * @details See array_struct.c
 */
#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_


#define SIZE 5
#include <stddef.h>		

struct data_t {

	char subject; 	/* one capital letter id for subject */
	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	
};

void init_array(struct data_t data[], int index, char id, int years, 
        int inches);
void print(struct data_t data[], int index);
void init_array(struct data_t data[], int index, char id, int years, 
        int inches);
int min_age(struct data_t data[], size_t size);
int max_age(struct data_t data[], size_t size);
int min_height(struct data_t data[], size_t size);
int max_height(struct data_t data[], size_t size);
double average_age(struct data_t data[], size_t size);
double average_height(struct data_t data[], size_t size);

#endif
