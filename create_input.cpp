#include "functions.cpp"
#include <ctime>

int main(int argc, char* argv[]) {
	srand((unsigned)time(0));
	float rand1;
	float rand2;
	for (int i = 0; i < atoi(argv[1]); i++) {
		rand1 = rand() % atoi(argv[1]);
		rand2 = rand() % atoi(argv[1]);

		ofstream out("input100.txt", fstream::out | fstream::app);
		out << rand1 << " " << rand2 << " " << endl;
		out.close();
	}
	return 0;
}
