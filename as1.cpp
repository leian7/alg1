#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <utility>
using namespace std;

struct Coordinate{
	float x;
	float y;

};

struct Distance{
	int x;
	int y;
	float dis;
};


int main(){

	int size = 0,  i = 0, arrayCount = 0, arraySize = 0;
	double dis = 0;
	//char c;
	ifstream f;
	f.open("example.input");
	string pairs;
    	while (getline(f, pairs))
        	size++;
	f.close();
    	//cout << " The lines of file: " << size << endl;
	Coordinate *line = new Coordinate [size];
//	c = 'a';
//	ifstream file;
	//file.open("example.input");
	f.open("example.input");

	for(int i = 0; i < size; i++){
		f >> line[i].x;
		f >> line[i].y;	
		//cout << " In the second time "<<endl;
	}
	
	for(int i=size-1; i > 0; i--){
		arraySize += i;
	}
	//cout << arraySize << endl;
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
			if(line[Sorted[i].x].x > line[Sorted[i].y].x){
				temp = Sorted[i].x;
				Sorted[i].x = Sorted[i].y;
				Sorted[i].y = temp;
				//cout << " THEN " << endl;
				
			}
			else if(line[Sorted[i].x].x == line[Sorted[i].y].x){
				if(line[Sorted[i].x].y > line[Sorted[i].y].y){
					swap(Sorted[i].x , Sorted[i].y);
				}		
			}

		//}
	}
	for(int i=0; i < arraySize-1; i++){
		for(int l=i+1; l < arraySize; l++){
			if(Sorted[i].dis == Sorted[l].dis){
				if(line[Sorted[i].x].x > line[Sorted[l].x].x ){
					temp = Sorted[i].x;
					Sorted[i].x = Sorted[l].x;
					Sorted[l].x = temp;
					temp = Sorted[i].y;
					Sorted[i].y = Sorted[l].y;
					Sorted[l].y = temp;	
				}
				else if(line[Sorted[i].x].x == line[Sorted[l].x].x &&  line[Sorted[i].x].y > line[Sorted[l].x].y){
					temp = Sorted[i].x;
					Sorted[i].x = Sorted[l].x;
					Sorted[l].x = temp;
					temp = Sorted[i].y;
					Sorted[i].y = Sorted[l].y;
					Sorted[l].y = temp;	

				}	
			}
		}
	}


	for(int i=0; i < arraySize-1; i++){
		if(Sorted[i].dis == Sorted[0].dis)
		cout << " ( " << line[Sorted[i].x].x << "," << line[Sorted[i].x].y << ")   " << "   ("<< line[Sorted[i].y].x <<"," <<  line[Sorted[i].y].y <<")   "<< " distances : " << Sorted[i].dis << endl;
	}
	return 0;
	delete [] line;

}

