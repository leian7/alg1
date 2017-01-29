#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Coordinate{
	int x;
	int y;

};

struct Distance{
	int x;
	int y;
	float dis;
};


int main(){

	int size = 0, count = 0, i = 0, arrayCount = 0, arraySize = 0;
	double dis = 0;
	char c;
	ifstream f;
	f.open("example.input");
	while( f.get(c) ){
		if(isdigit(c)){
			count++;
			size = count / 2;
		}
	}
	cout << " The size of Array: " << size << endl;
	Coordinate *line = new Coordinate [size];
	f.close();
	c = 'a';
	count = 0;
	ifstream file;
	file.open("example.input");
	for(int i = 0; i < size; i++){
		file >> line[i].x;
		file >> line[i].y;	
	}
	for(int o = 0; o < size; o++){
		cout << " x is " << line[o].x << " y is " << line[o].y << endl;
	}
	for(int i=size-1; i > 0; i--){
		arraySize += i;
	}
	cout << arraySize << endl;
	Distance *Sorted = new Distance [arraySize];
	int k = 0 ;
	for(int i=0; i < size-1; i++){
		for(int l=i+1; l < size; l++){
			k++;
			dis = sqrt( (pow((line[i].x - line[l].x), 2)+(pow((line[i].y - line[l].y), 2))));
			Sorted[k-1].x = i; 
			Sorted[k-1].y = l;
			Sorted[k-1].dis = dis;
		}
	}
	float temp=0;	
	for(int i=0; i < arraySize-1; i++){
		for(int l=i+1; l < arraySize; l++){
			if(Sorted[i].dis > Sorted[l].dis){
				temp = Sorted[i].dis;
				Sorted[i].dis = Sorted[l].dis;
				Sorted[l].dis = temp;
				temp = Sorted[i].x;
				Sorted[i].x = Sorted[l].x;
				Sorted[l].x = temp;
				temp = Sorted[i].y;
				Sorted[i].y = Sorted[l].y;
				Sorted[l].y = temp;



			}
		}
	}
	for(int i=0; i < arraySize; i++){
				cout << " x : " << Sorted[i].x << " y : " << Sorted[i].y << " distances : " << Sorted[i].dis << endl;
	}
	return 0;
	delete [] line;

}



/*
int main(){

	string line;
	ifstream myfile("example.input");
	if(myfile.is_open()){
		while(getline(myfile,line)){
			cout << line << '\n';
		}
		myfile.close();
	
	}
	else cout << "Unable to open the file\n";

	return 0;

}
*/

