#include "../utility.cpp"
int main()
{
	float answer;
	Coordinate *points_arr = new Coordinate[10];
/*	Coordinate *points_left = new Coordinate[5/2]; // 2 elts
	Coordinate *points_right = new Coordinate[5/2 + 1]; // 3 elts
*/
	points_arr[0].x = 0;
	points_arr[0].y = 0.5;

	points_arr[1].x = 5;
	points_arr[1].y = 5.5;

	points_arr[2].x = 9.5;
	points_arr[2].y = 8;

	points_arr[3].x = 8;
	points_arr[3].y = 9;

	points_arr[4].x = 1;
	points_arr[4].y = 8;

	points_arr[5].x = 1;
	points_arr[5].y = 7;

	points_arr[6].x = 9;
	points_arr[6].y = 5;

	points_arr[7].x = 4;
	points_arr[7].y = 0;

	points_arr[8].x = 9;
	points_arr[8].y = 6;

	points_arr[9].x = 9;
	points_arr[9].y = 7;

	answer = find_closest_pair(points_arr, 10);
	cout << "min dist between a pair " << answer << '\n';
/*	float L;
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

	delete[] points_left;
	delete[] points_right;
*/
	delete[] points_arr;
	return 0;
}
