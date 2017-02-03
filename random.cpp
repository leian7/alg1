#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

int myrandom (int i) { return std::rand()%i;}

int main () {
	std::srand ( unsigned ( std::time(0) ) );
	std::vector<int> myvector;
	std::vector<int> myvector2;

	// set some values:
	for (int i=0; i<200000; ++i) myvector.push_back(i); // 0 1 ... 19

	// using built-in random generator:
	std::random_shuffle ( myvector.begin(), myvector.end() );

	// using myrandom:
	std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

	// print out content:
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << *it <<" " << *it++ << std::endl;

/*	for (std::vector<int>::iterator it=myvector2.begin(); it!=myvector2.end(); ++it)
		std::cout << ' ' << *it; */

	return 0;
}
