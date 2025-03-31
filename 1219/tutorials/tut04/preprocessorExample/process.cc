#include <iostream>
using namespace std;

#define TheGovernment 1
#if TheGovernment == 2
void gov(){ cout << "Have you ever seen a baby pidgeon?" << endl;}
#else
void gov(){ cout << "jUST A NORMAL DAY" << endl;}
#endif

int main(){
	#ifdef MODE1
	std::cout << "FLAG1" << std::endl;
	std::string message = "im debugging :D";
	#endif
	#ifndef MODE1
	std::cout << "REGMODE" << std::endl;
	std::string message = "Im gonna SegFault :D";
	int *p = nullptr;
	*p = 1;
	#endif
	std::cout << message << std::endl;
	gov();
}
