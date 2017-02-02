#include "functions.cpp"

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
	Coordinate *line = new Coordinate [size];
	
	Coordinate *sorted_x = new Coordinate [size];
	Coordinate *sorted_y = new Coordinate [size];
	Coordinate *left_x = new Coordinate [size/2];
	
	Coordinate *right_x = new Coordinate [size/2];
	float L = 0;
	f.open(argv[1]);

	for(int i = 0; i < size; i++){
		f >> line[i].x;
		f >> line[i].y;	
	}
	f.close();
cout << "\n\nBEFORE MERGE SORTING X AND Y\n\n";	
	merge_sort_x(line,sorted_x, 0, size-1 );
	merge_sort_y(line,sorted_y, 0, size-1 );

	L = find_L(line,size);

	split_array(line,left_x,right_x,size,L );	

	Coordinate* right_of_y = new Coordinate[size/2];
	Coordinate* left_of_y = new Coordinate[size/2];

	split_y_array(left_x,sorted_y,size, left_of_y, right_of_y);

	cout << "Left of y: \n";
	for(int i = 0; i < size/2; i++){
		cout << "("<< left_of_y[i].x << " " << left_of_y[i].y << " )\n";
	}
	cout << "Right of y: \n";
	for(int i = 0; i < size/2; i++){
		cout << "("<< right_of_y[i].x << " " << right_of_y[i].y << " )\n";
	}
	cout << "before deleting line" << endl;
	/*	
	min = find_closest_pair(line, size);
	cout << " Minimum : " << min << endl;	
	//line = sort_by_x_and_y(size,line);
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
	}*/
	delete[]line;
	delete[]right_of_y;
	delete[]left_of_y;
	delete[]right_x;
	delete[]left_x;
	delete[]sorted_y;
	delete[]sorted_x;
	return 0;
}
