#include "functions.cpp"

int main(int argc, char* argv[]) {
	int size = 0, count = 0;
	float min;

	ifstream f;
	f.open(argv[1]);
	string pairs;
	while (getline(f, pairs)){
		size++;
	}
	cout << "size is " << size << endl;
	f.close();
	cout << "allocate mem" << endl;
	Coordinate *sorted_x = new Coordinate [size];
	Coordinate *sorted_y = new Coordinate [size];
	Coordinate *new_arr = new Coordinate[size];

	f.open(argv[1]);

	for(int i = 0; i < size; i++){
//		cout << "in the for loop" << endl;
		f >> sorted_x[i].x;
		f >> sorted_x[i].y;	
	}
	cout << "out of for loop" << endl;
	f.close();
	/* Timing algorithm */
	cout << "start timing" << endl;
	typedef struct timeval time;
	time stop, start;
	gettimeofday(&start, NULL);
	cout << "first merge x" << endl;
	merge_sort_x(sorted_x, new_arr, 0, size-1);
	cout << "first merge y" << endl;
	merge_sort_y(new_arr, sorted_y, 0, size-1);

	min = enhance_closest_pair(sorted_x,sorted_y, size);
	ofstream out ("output_enhance_dnc.txt");
	out << "Minimum : "<< min << endl;
	set< pair<Coordinate,Coordinate> >::iterator it;
	for(it=st.begin(); it!=st.end(); ++it){
		//first is x, y is the second element in one point.
		if(sqrtf( pow(it->first.x - it->second.x , 2) + pow(it->first.y - it->second.y , 2))!=min  ){
			st.erase(it);
		}

	}
	gettimeofday(&stop, NULL);
	cout << "micro: " << stop.tv_usec-start.tv_usec << endl;

	out<<"("<<st.begin()->first.x<<" "<<st.begin()->first.y<<")"<<"("<<st.begin()->second.x<<" "<<st.begin()->second.y<<")"<<endl;
	out.close();
	delete[]sorted_x;
	delete[]sorted_y;
	delete[]new_arr;
	return 0;
}
