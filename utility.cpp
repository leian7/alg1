/* This file contains helper functions used by both the naive and enhanced
 * versions of the closest-pair algorithms. */

/* list of var names
 * find_closest_pair
 * points_arr
 * n  <-- length of arr
 * find_min_dist
 * L
 * find_L
 * points_arr_left
 * points_arr_right
 * delta_1, delta_2, delta
 * M_y
 * merge_sort
 * d_m
 * closest_cross_pair
 * presort_y_c
 * presort_x_c
 * curr_min, min
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Coordinate {
	float x;
	float y;
};

/* Coordinate* merge() {
}

void merge_sort(Coordinate* points_arr, char c, int n, int start, int end) {
	Coordinate *points_arr_left = new Coordinate[n/2];
	Coordinate *points_arr_right = new Coordinate[n/2];

} */	

float find_min_dist(Coordinate* points_arr, int n){
	int k=0;
	float curr_min=0.0, min=0.0; 
	float* arr = new float [n];
	for(int i=0; i<n-1; i++){
			for(int l=i+1; l<n; l++){

			curr_min = sqrtf( (pow((points_arr[i].x - points_arr[l].x) , 2) + pow((points_arr[i].y - points_arr[l].y) , 2 )) );
			arr[k] = curr_min;
			k++;			
			}
		}
		sort(arr, arr+n);
		min = arr[0];
		delete[]arr;
		return min;
}

/*
int main()
{
	float minimum=0.0;
	Coordinate* array = new Coordinate [1];
	for(int i=0; i<1; i++){
		array[i].x = i+i;	
		array[i].y = i;
	}
	minimum = find_min_dist(array, 1);
	cout << " this is the minimum" << minimum << endl;
	for(int i=0; i<1; i++){
		cout << " index" << i << " : " << "(" << array[i].x << "  " << array[i].y << ")" << endl;
	}
	delete[]array;
	return 0;
}
*/
	
