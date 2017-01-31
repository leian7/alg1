#include "../utility.cpp"
int main_1()
{
	Coordinate *points_arr = new Coordinate[5];
	Coordinate *points_left = new Coordinate[5/2]; // 2 elts
	Coordinate *points_right = new Coordinate[5/2 + 1]; // 3 elts

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

	split_array(points_arr, points_left, points_right, 5, L);

	cout << "left arr: " << '\n';
	for (int i = 0; i < 2; i++) {
		cout << points_left[i].x << ", " << points_left[i].y << '\n';
	}

	cout << "right arr: " << '\n';
	for (int i = 0; i < 3; i++) {
		cout << points_right[i].x << ", " << points_right[i].y << '\n';
	}

	delete[] points_arr;
	delete[] points_left;
	delete[] points_right;

	return 0;
}
