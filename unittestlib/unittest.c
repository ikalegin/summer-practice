#include "../practicelib/practicelib.h"
#include <stdio.h>
#include <stdlib.h>
#define ASSERT(condition, message){ \
if ((condition)) {\
	printf("ASSERT FAILED: %s\n", message); \
	exit(EXIT_FAILURE); \
} \
else { \
	printf("ASSERT SUCCEEDED\n"); \
} \
}

int main() {
	double Ax, Bx, Cx, Ay, By, Cy, Dx, Dy;
	int expected_output, obtainted_output;
	double expAx[10] = { 1, 1, -9.2, -6.67, 2, -20, -7.23, 4.6, 5.131, 12};
	double expBx[10] = { 2, 2, -5, -12.02, 7, 6, 12.741, 6.3, 9.427,10};
	double expCx[10] = { 5, 3, -3.36, -1.13, 12, -9, -6.31, 12.14, 7.77,8};
	double expAy[10] = { 1, 1, 14.2, -3.335, 0, -5, 2.23, -1.02,7.863,13};
	double expBy[10] = { 5, 2, 10, -6.01, -10, 21, 9.216, 4.38, 4.237,9};
	double expCy[10] = { 3, 3, 8.36, -0.565, -20, 17, 8.12, 2.58, 6.12, 7};
	double expDx[3] = {7.78, 6, 10};
	double expDy[3] = { 4.38, 7.13,10 };
	int expOut[10] = { 1, 0, 0, 0, 0, 1, 1, 0, 1, 2};

	//TEST OF POSSIBILITY OF CREATING A TRIANGLE

	for (int i = 0; i < 7; i++) {
		expected_output = expOut[i];
		Ax = expAx[i], Bx = expBx[i], Cx = expCx[i], Ay = expAy[i], By = expBy[i], Cy = expCy[i];
		obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
		ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");
	}

	// TEST OF DIRECTION OF POINT

	for (int i = 7; i < 10; i++) {
		expected_output = expOut[i];
		Ax = expAx[i], Bx = expBx[i], Cx = expCx[i], Ay = expAy[i], By = expBy[i], Cy = expCy[i], Dx = expDx[i - 7], Dy = expDy[i - 7];
		obtainted_output = isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy);
		ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");
	}
	return 0;
}
