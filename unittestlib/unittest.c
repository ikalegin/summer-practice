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

	//ТЕСТЫ НА ПРОВЕРКУ, ТРЕУГОЛЬНИК ЛИ

	for (int i = 0; i < 7; i++) {
		expected_output = expOut[i];
		Ax = expAx[i], Bx = expBx[i], Cx = expCx[i], Ay = expAy[i], By = expBy[i], Cy = expCy[i];
		obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
		ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");
	}

	// ТЕСТЫ НА ПРОВЕРКУ ВХОДИМОСТИ ТОЧКИ В ТРЕУГОЛЬНИК

	for (int i = 7; i < 10; i++) {
		expected_output = expOut[i];
		Ax = expAx[i], Bx = expBx[i], Cx = expCx[i], Ay = expAy[i], By = expBy[i], Cy = expCy[i], Dx = expDx[i - 7], Dy = expDy[i - 7];
		obtainted_output = isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy);
		ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");
	}
	/*// ТЕСТЫ НА ПРОВЕРКУ ФУНКЦИИ istriangle
	double Ax = 1, Bx = 2, Cx = 5, Ay = 1, By = 5, Cy = 3; // проверка на работоспособность
	int expected_output = 1, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = 1, Bx = 2, Cx = 3, Ay = 1, By = 2, Cy = 3; // тест на проверку работы функции на распознавание прямой в первой четверти
	expected_output = 0, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = -9.2, Bx = -5, Cx = -3.36, Ay = 14.2, By = 10, Cy = 8.36; // тест на проверку работы функции на распознавание прямой во второй четверти
	expected_output = 0, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = -6.67, Bx = -12.02, Cx = -1.13, Ay = -3.335, By = -6.01, Cy = -0.565; // тест на проверку работы функции на распознавание прямой в третьей четверти
	expected_output = 0, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = 2, Bx = 7, Cx = 12, Ay = 0, By = -10, Cy = -20; // тест на проверку работы функции на распознавание прямой в четвертой четверти
	expected_output = 0, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = -20, Bx = 6, Cx = -9, Ay = -5, By = 21, Cy = 17; // проверка на работу с отрицательными числами
	expected_output = 1, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = -7.23, Bx = 12.741, Cx = -6.31, Ay = 2.23, By = 9.216, Cy = 8.12; // проверка на работу с отрицательными числами
	expected_output = 1, obtainted_output;
	obtainted_output = istriangle(Ax, Bx, Cx, Ay, By, Cy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");


	// ТЕСТЫ НА ПРОВЕРКУ ФУНКЦИИ isintriangle
	double Dx, Dy;
	Ax = 4.6, Bx = 6.3, Cx = 12.14, Ay = -1.02, By = 4.38, Cy = 2.58, Dx = 7.78, Dy = 4.38; // проверка на невходимость точки в треугольник
	expected_output = 0, obtainted_output;
	obtainted_output = isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");

	Ax = 4.6, Bx = 6.3, Cx = 12.14, Ay = -1.02, By = 4.38, Cy = 2.58, Dx = 7.78, Dy = 4.38; // проверка на невходимость точки в треугольник
	expected_output = 0, obtainted_output;
	obtainted_output = isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy);
	ASSERT(expected_output != obtainted_output, "Test failed. Doesn't work for your coordinates.");
	*/
	return 0;
}