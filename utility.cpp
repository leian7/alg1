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
#include <cmath>

using namespace std;

struct Coordinate {
	float x;
	float y;
};

void merge_x(Coordinate *points_arr, Coordinate *new_arr, int start, int mid, int end) {
	int left_iter = start;
	int right_iter = mid + 1;
	int combo_iter = start;
	int i;
	while ((left_iter <= mid) && (right_iter <= end)) {
		if (points_arr[left_iter].x <= points_arr[right_iter].x) {
			new_arr[combo_iter] = points_arr[left_iter];
			left_iter++;
		}
		else {
			new_arr[combo_iter] = points_arr[right_iter];
			right_iter++;
		}
		combo_iter++;
	}
	if (left_iter > mid) {
		for (i = right_iter; i <= end; i++) {
			new_arr[combo_iter] = points_arr[i];
			combo_iter++;
		}
	}
	else {
		for (i = left_iter; i <= mid; i++) {
			new_arr[combo_iter] = points_arr[i];
			combo_iter++;
		}
	}
	for (i = start; i <= end; i++) {
		points_arr[i] = new_arr[i];
	}
}

void merge_sort_x(Coordinate *points_arr, Coordinate *new_arr, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort_x(points_arr, new_arr, start, mid);
		merge_sort_x(points_arr, new_arr, mid+1, end);
		merge_x(points_arr, new_arr, start, mid, end);
	}
}

void merge_y(Coordinate *points_arr, Coordinate *new_arr, int start, int mid, int end) {
	int left_iter = start;
	int right_iter = mid + 1;
	int combo_iter = start;
	int i;
	while ((left_iter <= mid) && (right_iter <= end)) {
		if (points_arr[left_iter].y <= points_arr[right_iter].y) {
			new_arr[combo_iter] = points_arr[left_iter];
			left_iter++;
		}
		else {
			new_arr[combo_iter] = points_arr[right_iter];
			right_iter++;
		}
		combo_iter++;
	}
	if (left_iter > mid) {
		for (i = right_iter; i <= end; i++) {
			new_arr[combo_iter] = points_arr[i];
			combo_iter++;
		}
	}
	else {
		for (i = left_iter; i <= mid; i++) {
			new_arr[combo_iter] = points_arr[i];
			combo_iter++;
		}
	}
	for (i = start; i <= end; i++) {
		points_arr[i] = new_arr[i];
	}
}

void merge_sort_y(Coordinate *points_arr, Coordinate *new_arr, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort_y(points_arr, new_arr, start, mid);
		merge_sort_y(points_arr, new_arr, mid+1, end);
		merge_y(points_arr, new_arr, start, mid, end);
	}
}	

int main()
{
		return 0;
}
