/*
����: summerpractice.cpp
��������
�����: ������� �.�.
�������: ����������, ��������� �� ����� � ������������
���� ��������: 10.06.21
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "..\practicelib\practicelib.h"
int main() {
	setlocale(LC_ALL, "RUS");
	double Ax = 0, Bx = 0, Cx = 0, Ay = 0, By = 0, Cy = 0, Dx = 0, Dy = 0;
	printf("������� ���������� ����� A: ");
	scanf_s("%lf%lf", &Ax, &Ay);
	printf("������� ���������� ����� B: ");
	scanf_s("%lf%lf", &Bx, &By);
	printf("������� ���������� ����� C: ");
	scanf_s("%lf%lf", &Cx, &Cy);
	if (istriangle(Ax, Bx, Cx, Ay, By, Cy) == 0) {
		printf("����������� ������� �� ����������. ����� ������� ������ ������");
		exit(EXIT_FAILURE);
	}
	printf("������� ���������� ������ �����: ");
	scanf_s("%lf%lf", &Dx, &Dy);
	if (isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy) == 0) {
		printf("����� �� ������ � �����������");
	}
	else if (isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy) == 1) {
		printf("����� ����� � ������������");
	}
	else if (isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy) == 2) {
		printf("����� ����� �� ������� ������������");
	}
}