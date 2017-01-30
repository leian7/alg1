#include "../utility.cpp"
int main_1()
{
	Coordinate *points_arr = new Coordinate[4];
	Coordinate *new_arr = new Coordinate[4];

	points_arr[0].x = 1.1;
	points_arr[1].x = 6.6;
	points_arr[2].x = 5.5;
	points_arr[3].x = 3.3;
	points_arr[0].y = 4.4;
	points_arr[1].y = 2.2;
	points_arr[2].y = 8.8;
	points_arr[3].y = 9.9;
	merge_sort_y(points_arr, new_arr, 0, 3);
	cout << "here is new_arr y\n";
	for (int i = 0; i < 4; i++) {
		cout << new_arr[i].y << '\n';
	}
	cout << '\n';

	cout << "here is points_arr y\n";
	for (int i = 0; i < 4; i++) {
		cout << points_arr[i].y << '\n';
	}

	merge_sort_x(points_arr, new_arr, 0, 3);
	cout << "here is new_arr x\n";
	for (int i = 0; i < 4; i++) {
		cout << new_arr[i].x << '\n';
	}
	cout << '\n';

	cout << "here is points_arr x\n";
	for (int i = 0; i < 4; i++) {
		cout << points_arr[i].x << '\n';
	}

	delete[] points_arr;
	delete[] new_arr;

	return 0;
}
