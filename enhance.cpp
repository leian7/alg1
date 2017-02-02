#include "function.cpp"

int main(int argc, char* argv[]) {
	int size = 0;
	float min;
	
	ifstream f;
	f.open(argv[1]);
	string pairs;
	while (getline(f, pairs)){
		size++;
	}
	f.close();
	Coordinate *sorted_x = new Coordinate [size];
	Coordinate *sorted_y = new Coordinate [size];
	Coordinate *new_arr = new Coordinate[size];

	f.open(argv[1]);

	for(int i = 0; i < size; i++){
		f >> sorted_x[i].x;
		f >> sorted_x[i].y;	
	}
	f.close();

	merge_sort_x(sorted_x, new_arr, 0, n-1);
	merge_sort_y(new_arr, sorted_y, 0, n-1);

	min = find_closest_pair(sorted_x, size);
/*	min = find_closest_pair(sorted_x, size);
	cout << " Minimum : " << min << endl;	
	//sorted_x = sort_by_x_and_y(size,sorted_x);
	set< pair<Coordinate,Coordinate> >::iterator it;
	for(it=st.begin(); it!=st.end(); ++it){
		//first is x, y is the second element in one point.
		if(sqrtf( pow(it->first.x - it->second.x , 2) + pow(it->first.y - it->second.y , 2))!=min  ){
			st.erase(it);
		}

	}
	for(int i=0; i < 1; i++){
		cout<<"("<<st.begin()->first.x<<" "<<st.begin()->first.y<<")"<<"("<<st.begin()->second.x<<" "<<st.begin()->second.y<<")"<<endl;
		count++;
	} */
	delete[]sorted_x;
	return 0;
}
