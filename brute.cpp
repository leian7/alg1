#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Coordinate {
	float x;
	float y;
};

int main(int argc, char* argv[]) {
	int size = 0;
	float min = 0;
	float d;

	ifstream f;
	f.open(argv[1]);
	string pairs;
	while (getline(f, pairs)){
		size++;
	}
	f.close();

	f.open(argv[1]);

	Coordinate *points_arr = new Coordinate [size];
	Coordinate *pair = new Coordinate[2];

	for(int i = 0; i < size; i++){
		f >> points_arr[i].x;
		f >> points_arr[i].y;	
	}
	f.close();
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size-1; j++) {
			if (i == 0 && j == 1) {
				min = sqrtf(pow((points_arr[i].x - points_arr[j].x), 2) + pow((points_arr[i].y - points_arr[j].y), 2));
			}
			d = sqrtf(pow((points_arr[i].x - points_arr[j].x), 2) + pow((points_arr[i].y - points_arr[j].y), 2));
			if (d < min) {
				min = d;
				pair[0] = points_arr[i];
				pair[1] = points_arr[j];
			}
		}
	}
	
	ofstream out("output_bruteforce.txt");	
	out << min << endl;
	out << pair[0].x << ", " << pair[0].y << " " << pair[1].x << ", " << pair[1].y << endl;
	out.close();

	delete[] points_arr;
	delete[] pair;

	return 0;
}
