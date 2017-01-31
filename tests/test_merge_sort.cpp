#include "../utility.cpp"
int main_1()
{
	Coordinate *points_arr = new Coordinate[5];

	points_arr[0].x = 1.1;
	points_arr[1].x = 6.6;
	points_arr[2].x = 5.5;
	points_arr[3].x = 3.3;
	points_arr[4].x = 28;
	points_arr[0].y = 4.4;
	points_arr[1].y = 2.2;
	points_arr[2].y = 8.8;
	points_arr[3].y = 9.9;
	points_arr[4].y = 0.1;

	float L;
	L = find_L(points_arr, 5);
	cout << L << '\n';

	delete[] points_arr;

	return 0;
}
