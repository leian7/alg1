/* This file contains helper functions used by both the naive and enhanced
 * versions of the closest-pair algorithms. */

/* list of var names
 * find_enhance_closest_pair
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
#include <set>
using namespace std;

struct Coordinate {
	float x;
	float y;
};

// what makes one pair less than another pair?
inline bool operator<(const Coordinate& lhs, const Coordinate& rhs){
		return lhs.x <= rhs.x ;
}

set< pair<Coordinate,Coordinate> > st;
void make_pair(pair<Coordinate,Coordinate>, pair<Coordinate, Coordinate>);// set's elts are pairs of coors
	
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

float find_min_dist(Coordinate* points_arr, int n){
	int k = 0;
	float curr_min = 0.0, min = 0.0;
	float* arr;

   	if (n == 2) {
		arr	= new float[1];
	}

	else
		arr = new float[n];

	for (int i = 0; i < n-1; i++){
		for (int l = i+1; l < n; l++){
			curr_min = sqrtf( (pow((points_arr[i].x - points_arr[l].x) , 2) + pow((points_arr[i].y - points_arr[l].y) , 2 )) );
			arr[k] = curr_min;
			k++;			
		}
	}
	if(n!=2){
		sort(arr, arr+n);
	}

	min = arr[0];
	delete [] arr;	
	return min;
}

float find_L(Coordinate *points_arr, int n) {
	float L;
	Coordinate *new_arr = new Coordinate[n];
	merge_sort_x(points_arr, new_arr, 0, n-1);
	L = points_arr[n/2].x;
	delete[] new_arr;
	return L;
}

/* Divides array of points into a left and right array according to a dividing
 * line L
 */
void split_array(Coordinate *points_arr, Coordinate *points_arr_left, Coordinate *points_arr_right, int n, int L) {
	
	int left_iter = 0;
	int right_iter = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n/2; i++) {
			points_arr_left[left_iter] = points_arr[i];
			left_iter++;
		}
		for (int i = n/2; i < n; i++) {
			points_arr_right[right_iter] = points_arr[i];
			right_iter++;
		}
	}
	else { // if size of points_arr[i] is odd
		for (int i = 0; i < n/2; i++) {
			points_arr_left[left_iter] = points_arr[i];
			left_iter++;
		}
		for (int i = n/2; i < n; i++) {
			points_arr_right[right_iter] = points_arr[i];
			right_iter++;
		}
	}
	
}

float closest_cross_pairs(Coordinate *M_y, float delta, int m) {
	float d_m = delta;
	float d;
	int i, j;
	Coordinate x,y;
	set< pair<Coordinate,Coordinate> >::iterator it;
	for (i = 0; i < m-1; i++) {
		j = i + 1;
		if(abs((M_y[j].y - M_y[i].y)) <= delta && j <= m) {
			d = sqrtf( (pow((M_y[i].x - M_y[j].x) , 2) + pow((M_y[i].y - M_y[j].y) , 2 )) );
			d_m = min(d, d_m);
			x = M_y[i];
			y = M_y[j];
			st.insert(make_pair(x,y));
			j++;
		}
		
	}
	return d_m;
}

float enhance_closest_pair(Coordinate *points_arr, int n) {
	float L, delta_1, delta_2, delta, d_m, minimum;
	int j = 0;
	// We know size of M_y must be smaller than total num of points.

	if (n <= 3) {
		minimum = find_min_dist(points_arr, n);
		return 	minimum ;
	}

	else {
		L = find_L(points_arr, n);

		Coordinate *points_arr_left = new Coordinate[n/2];
		Coordinate *points_arr_right;
		if (n % 2 == 0) {
			points_arr_right = new Coordinate[n/2];
		}
		else {
			points_arr_right = new Coordinate[(n/2) + 1];
		}

		split_array(points_arr, points_arr_left, points_arr_right, n, L);
		split_y_array()
		delta_1 = enhance_closest_pair(points_arr_left, n/2);
		if (n % 2 == 0)
			delta_2 = enhance_closest_pair(points_arr_right, n/2);
		else
			delta_2 = enhance_closest_pair(points_arr_right, (n/2+1));

		delta = min(delta_1, delta_2);

		int m = 0;

	
		for (int i = 0; i < n; i++) {
			if (abs(L - points_arr[i].x) <= delta) {
				m++;
			}
		}
		delete[] points_arr_left;
		delete[] points_arr_right;
		Coordinate *M_y = new Coordinate[m];
		for (int i = 0; i < n; i++) {
			if (abs(L - points_arr[i].x) <= delta) {
				M_y[j] = points_arr[i];
				j++;
			}
		}
			
		Coordinate *new_arr = new Coordinate[m];
		
		merge_sort_y(M_y, new_arr, 0, m-1);
		
		d_m = closest_cross_pairs(new_arr, delta, m);
		delete[] new_arr;
		delete[]M_y;	
		return d_m;
		
		
	}
}


float naive_closest_pair(Coordinate *points_arr, int n) {
	float L, delta_1, delta_2, delta, d_m, minimum;
	int j = 0;
	// We know size of M_y must be smaller than total num of points.

	if (n <= 3) {
		minimum = find_min_dist(points_arr, n);
		return 	minimum ;
	}

	else {
		L = find_L(points_arr, n);

		Coordinate *points_arr_left = new Coordinate[n/2];
		Coordinate *points_arr_right;
		if (n % 2 == 0) {
			points_arr_right = new Coordinate[n/2];
		}
		else {
			points_arr_right = new Coordinate[(n/2) + 1];
		}

		split_array(points_arr, points_arr_left, points_arr_right, n, L);
		delta_1 = naive_closest_pair(points_arr_left, n/2);
		if (n % 2 == 0)
			delta_2 = naive_closest_pair(points_arr_right, n/2);
		else
			delta_2 = naive_closest_pair(points_arr_right, (n/2+1));

		delta = min(delta_1, delta_2);

		int m = 0;

	
		for (int i = 0; i < n; i++) {
			if (abs(L - points_arr[i].x) <= delta) {
				m++;
			}
		}
		delete[] points_arr_left;
		delete[] points_arr_right;
		Coordinate *M_y = new Coordinate[m];
		for (int i = 0; i < n; i++) {
			if (abs(L - points_arr[i].x) <= delta) {
				M_y[j] = points_arr[i];
				j++;
			}
		}
			
		Coordinate *new_arr = new Coordinate[m];
		
		merge_sort_y(M_y, new_arr, 0, m-1);
		
		d_m = closest_cross_pairs(new_arr, delta, m);
		delete[] new_arr;
		delete[]M_y;	
		return d_m;
		
		
	}
	
	
}


Coordinate *sort_by_x_and_y(int size,Coordinate* line){
	int count=0,n=0;
	float arr[size];
	float arr_orig[size];
	int arr_index[size];
	Coordinate *sorting = new Coordinate [size];
	
	for(int i = 0; i < size; i++){
		arr[i] = line[i].x*10+line[i].y;
		arr_orig[i] = line[i].x*10+line[i].y;
		arr_index[i]=i;
	}
	sort(arr,arr+size);
	while(count != size){
		if(arr_orig[count] == arr[n]){
			arr_index[count] = n;
			n=0;
			count++;
		}
		n++;
	}
	for(int i = 0; i < size; i++){
		sorting[i] = line[arr_index[i]];
	}
	return sorting;
}

void split_y_array( Coordinate* left_of_x , Coordinate* sorted_by_y , int size, Coordinate* left_of_y, Coordinate* right_of_y){
	int itera_right = 0 , itera_left = 0;
	for(int i = 0; i < size; i++){
		if(left_of_x[size/2-1].x < sorted_by_y[i].x ){
			cout << "right of y gets " << sorted_by_y[i].x << " "<<sorted_by_y[i].y<< endl;
			right_of_y[itera_right] = sorted_by_y[i];
			cout << "right of y is " << right_of_y[itera_right].x << " "<<right_of_y[itera_right].y<< endl;
			itera_right++;
		}
		else{
			cout << "right of y gets " << sorted_by_y[i].x << " "<<sorted_by_y[i].y<< endl;
			left_of_y[itera_left] = sorted_by_y[i];
			cout << "left of y gets " << left_of_y[itera_left].x << "  "<<left_of_y[itera_left].y << endl;
			itera_left++;
		}

	}
}
