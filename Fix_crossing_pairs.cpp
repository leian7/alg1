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
	cout << "\nENTERED FIND MIN DIST FUNCT \n";
	int k = 0;
	float curr_min = 0.0, min = 0.0;
	cout << " total number N passed in " << n << endl;
	float* arr;

   	if (n == 2) {
		arr	= new float[1];
	}

	else
		arr = new float[n];

	for (int i = 0; i < n-1; i++){
		for (int l = i+1; l < n; l++){
			//cout << "TIME " << k << endl;
			//cout << "\n the two points passing in is : "<<points_arr[i].x <<"     "<< points_arr[i].y << endl;
			//cout << "\n the two points passing in is : "<<points_arr[l].x <<"     "<< points_arr[l].y << endl;
			curr_min = sqrtf( (pow((points_arr[i].x - points_arr[l].x) , 2) + pow((points_arr[i].y - points_arr[l].y) , 2 )) );
			arr[k] = curr_min;
			cout << "arr[k] is " << arr[k]<< endl;
			k++;			
		}
	}
	if(n!=2){
		sort(arr, arr+n);
	}

	/*for (int i =0; i<n; i++){
		cout <<"this is the for loop after sort " <<arr[i] << endl;
	}*/
	min = arr[0];
	//cout <<"BEFORE RETURN"<< min << endl;
	delete [] arr;	
	cout << "EXIT FIND MIN DIST FUNCT \n";
	return min;
}

float find_L(Coordinate *points_arr, int n) {
	cout << "\nENTERED find_L(Coordinate *points_arr, int n)\n";
	float L;
	Coordinate *new_arr = new Coordinate[n];
	merge_sort_x(points_arr, new_arr, 0, n-1);
	L = points_arr[n/2].x;
	delete[] new_arr;
	cout << "EXIT find_L(Coordinate *points_arr, int n)\n";
	return L;
}

/* Divides array of points into a left and right array according to a dividing
 * line L
 */
void split_array(Coordinate *points_arr, Coordinate *points_arr_left, Coordinate *points_arr_right, int n, int L) {
	cout << "\nENTERED split_array\n";
	
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
	cout << "EXIT split_array\n";
	
}

float closest_cross_pairs(Coordinate *M_y, float delta, int m) {
	cout << "\nENTERED closest_cross_pairs\n";
	float d_m = delta;
	float d;
	int i, j;
	for (i = 1; i < m-1; i++) {
		j = i + 1;
		while (abs((M_y[j].y - M_y[i].y)) <= delta && j <= m) {
			cout << "\nM_y[i]: " << M_y[i].x << ", " << M_y[i].y << endl;
			cout << "\nM_y[j]: " << M_y[j].x << ", " << M_y[j].y << endl;
			d = sqrtf( (pow((M_y[i].x - M_y[j].x) , 2) + pow((M_y[i].y - M_y[j].y) , 2 )) );
			cout << "\n d IS " << d << '\n';
			d_m = min(d, d_m);
			//cout << "\n inside the while loop number i : " << i << endl;
			//cout << "\n in while loop number j : " << j << endl;
			//cout << "\n inside the while d_m IS " << d_m << '\n';
			j++;
		}
	}
	cout << "\nd_m IS " << d_m << '\n';
	cout << "EXIT closest_cross_pairs\n";
	return d_m;
}


// MOVE THIS TO SOME NAIVE.CPP LATER
float find_closest_pair(Coordinate *points_arr, int n) {
	cout << "\nENTERED find_closest_pair\n";
	
	float L, delta_1, delta_2, delta, d_m, minimum;
	int j = 0;
	// We know size of M_y must be smaller than total num of points.

	if (n <= 3) {
		cout << "n is less than 3\n";
		cout << " n in if statement "<< n << endl;
		for (int i = 0; i < n; i++) {
			cout << "point (" << i << points_arr[i].x << ", " << points_arr[i].y <<")\n" ;
		}
		minimum = find_min_dist(points_arr, n);

		cout << "\nminimum in n<=3 base case" << minimum << endl;
		return 	minimum ;
	}

	else {
		cout << "n is greater than 3\n";
		L = find_L(points_arr, n);
		cout << "L is " << L << '\n';

		Coordinate *points_arr_left = new Coordinate[n/2];
		Coordinate *points_arr_right;
		if (n % 2 == 0) {
			cout << n << " is even\n";
			points_arr_right = new Coordinate[n/2];
		}
		else {
			cout << n << " is odd\n";
			points_arr_right = new Coordinate[(n/2) + 1];
		}

		split_array(points_arr, points_arr_left, points_arr_right, n, L);

		for (int a = 0; a<(n/2); a++){
			cout << " array left side " << "(" << points_arr_left[a].x <<","<< points_arr_left[a].y << ")\n";

		}
		if (n % 2 == 0) {
			for (int a = 0; a<(n/2); a++){
				//cout << "\n\n IF \n\n";
				cout << " array right side " << "(" << points_arr_right[a].x <<","<< points_arr_right[a].y << ")\n";
	
			}	
		}
		else {
			for (int a = 0; a<(n/2 + 1); a++){
				//cout << "\n\n ELSE \n\n";
				cout << " array right side " << "(" << points_arr_right[a].x <<","<< points_arr_right[a].y << ")\n";
	
			}
		}
		delta_1 = find_closest_pair(points_arr_left, n/2);
		if (n % 2 == 0)
			delta_2 = find_closest_pair(points_arr_right, n/2);
		else
			delta_2 = find_closest_pair(points_arr_right, (n/2+1));

		delta = min(delta_1, delta_2);
		// Cout the numbers for deltas
		cout << "\ndelta_1 "<< delta_1 << " \ndelta_2 " << delta_2 <<"\ndelta " << delta << endl<<endl; 

		int m = 0;

		for (int i = 0; i < n; i++) {
			if (abs(L - points_arr[i].x) <= delta) {
				m++;
				//cout << "abs(L - points_arr[i].x) :  " << abs(L - points_arr[i].x) << endl; 
				//cout << " L in abs(L - points_arr[i].x) " <<  L << endl;
				//cout << " Index i "<< i <<" for points_arr[i].x : \n";
			}
		}
		delete[] points_arr_left;
		delete[] points_arr_right;
		cout << "m is " << m << endl;
		Coordinate *M_y = new Coordinate[m];
		for (int i = 0; i < n; i++) {
			if (abs(L - points_arr[i].x) <= delta) {
				M_y[j] = points_arr[i];
				/*M_y[j].x = points_arr[i].x;
				M_y[j].y = points_arr[i].y;*/
				//cout << " L after counting size " <<  L << endl;
				cout << "\nM_y["<<j<<"].x "<< M_y[j].x<< endl;
				cout << "\nM_y["<<j<<"].y "<< M_y[j].y<< endl;
				j++;
			}
		}
		for (int i = 0; i < m; i++) {
			cout << "\nM_y[" << i << "] ( "<< M_y[i].x <<" , "<< M_y[i].y<<" ) "<< endl;
		}
		cout << "j is "<< j << endl;
		
		if(j>0){
			
			Coordinate *new_arr = new Coordinate[m];
			
			merge_sort_y(M_y, new_arr, 0, m-1);
			for (int i = 0; i < m; i++) {
				cout << "\nnew_arr[" << i << "] ( "<< new_arr[i].x <<" , "<< new_arr[i].y <<" ) "<< endl;
			}
			d_m = closest_cross_pairs(new_arr, delta, m);
		/*	
			 */
			for (int i = 0; i < m; i++) {
				cout << "\nnew_arr[" << i << "] ( "<< new_arr[i].x <<" , "<< new_arr[i].y <<" ) "<< endl;
			}
			delete[] new_arr;
			cout << "EXIT find_closest_pair\n";
			delete[]M_y;	
			return d_m;
		}
		else{
			cout << "EXIT find_closest_pair\n";
			delete[]M_y;	
			return delta;
		}
		
		
	}
	
	
}

/*	float minimum=0.0;
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
	delete[]array; */



int main() {
	int size;
	ifstream f;
	f.open("example.input");
	string pairs;
	while (getline(f, pairs)){
		size++;
	}
	f.close();
	//cout << " The lines of file: " << size << endl;
	Coordinate *line = new Coordinate [size];
	//	c = 'a';
	//	ifstream file;
	//file.open("example.input");
	f.open("example.input");

	for(int i = 0; i < size; i++){
		f >> line[i].x;
		f >> line[i].y;	
		//cout << " In the second time "<<endl;
	}
	/*for(int o = 0; o < size; o++){
		cout << "( " << line[o].x <<" , "<< line[o].y << ")" << endl;
	}*/
	find_closest_pair(line, size);
	delete[]line;
		return 0;
}
