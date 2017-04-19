// Fast sqrt
#include <iostream>
#include <cmath>

using namespace std;

//Inverse square root usuing Quake 3's magic number 
float M_sqrt(float number) {
	long i;
	float x2, val;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	val = number;
	i = * (long *) &val;
	i = 0x5f3759df - (i>>1);

	val = * (float *) &i;
	val = val * (threehalfs - (x2 * val * val));
	val = val * (threehalfs - (x2 * val * val));

	return 1/val;
}

// Approximation based with floating pt representation
float F_sqrt(float number) {
	int val = *(int *)&number;
	val = (1<<29) + (val>>1) - (1<<22);

	return *(float *) & val;
}

int main() {

	cout<<"Square root of 4 : "<<sqrt(4)<<" "<<M_sqrt(4)<<" "<<F_sqrt(4)<<endl;
	cout<<"Square root of 129 : "<<sqrt(129)<<" "<<M_sqrt(129)<<" "<<F_sqrt(129)<<endl;


	return 0;
}