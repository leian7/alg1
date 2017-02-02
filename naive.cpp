#include "functions.cpp"
int main(int argc, char* argv[]) {
	int size,count = 1;
	float min;
	
	ifstream f;
	f.open(argv[1]);
	string pairs;
	while (getline(f, pairs)){
		size++;
	}
	f.close();
	Coordinate *line = new Coordinate [size];
	
	f.open(argv[1]);

	for(int i = 0; i < size; i++){
		f >> line[i].x;
		f >> line[i].y;	
	}
	
	min = naive_closest_pair(line, size);
	ofstream out("output_divideandconquer.txt");
	out << " Minimum : " << min << endl;	
	set< pair<Coordinate,Coordinate> >::iterator it;
	for(it=st.begin(); it!=st.end(); ++it){
		//first is x, y is the second element in one point.
		if(sqrtf( pow(it->first.x - it->second.x , 2) + pow(it->first.y - it->second.y , 2))!=min  ){
			st.erase(it);
		}

	}
	out<<"("<<st.begin()->first.x<<" "<<st.begin()->first.y<<")"<<"("<<st.begin()->second.x<<" "<<st.begin()->second.y<<")"<<endl;
	out.close();
	delete[]line;
	return 0;
}
