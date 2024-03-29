#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "point_array.h"

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
	pa->len = 0;
	pa->points = NULL;
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa )
{
	pa->len = 0;
	free(pa->points);
	pa->points = NULL;
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p )
{
	if (pa == NULL || p == NULL)
	{
		return 1;
	}
	//If there is no space left, reserve 5x space
	if (pa->reserved == pa->len)
	{
		pa->reserved = pa->reserved*5;
		pa->points = realloc(pa->points,sizeof(point_t)*pa->reserved);
		
	}
	
	if (pa->len == 0)
	{
		pa->len = pa->len + 1;
		pa->points = realloc(pa->points , sizeof(point_t)*pa->len*2);
		pa->reserved = 2;
		
		pa->points[pa->len-1].x = p->x;	
		pa->points[pa->len-1].y = p->y;
		pa->points[pa->len-1].z = p->z;

	}
	else
	{
		pa->len = pa->len + 1;
		pa->points[pa->len-1].x = p->x;
		pa->points[pa->len-1].y = p->y;
		pa->points[pa->len-1].z = p->z;
	}
	
	return 0;
	
	
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i )
{
	if (i >= pa->len || pa->len == 0)
	{
		return 1;
	}
	pa->points[i].x = pa->points[pa->len - 1].x;
	pa->points[i].y = pa->points[pa->len - 1].y;
	pa->points[i].z = pa->points[pa->len - 1].z;
	/* 
	pa->points[pa->len -1].x = 0;
	pa->points[pa->len -1].y = 0;
	pa->points[pa->len -1].z = 0;
	*/
	pa->len = pa->len -1;
	return 0;
}
