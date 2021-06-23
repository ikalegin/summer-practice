/*
Файл: summerpractice.cpp
Практика
Автор: Калегин И.В.
Задание: Определить, находится ли точка в треугольнике
Дата создания: 10.06.21
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "..\practicelib\practicelib.h"
int main() {
	setlocale(LC_ALL, "RUS");
	double Ax = 0, Bx = 0, Cx = 0, Ay = 0, By = 0, Cy = 0, Dx = 0, Dy = 0;
	printf("Введите координаты точки A: ");
	scanf_s("%lf%lf", &Ax, &Ay);
	printf("Введите координаты точки B: ");
	scanf_s("%lf%lf", &Bx, &By);
	printf("Введите координаты точки C: ");
	scanf_s("%lf%lf", &Cx, &Cy);
	if (istriangle(Ax, Bx, Cx, Ay, By, Cy) == 0) {
		printf("Треугольник создать не получилось. Точки создают единую прямую");
		exit(EXIT_FAILURE);
	}
	printf("Введите координаты нужной точки: ");
	scanf_s("%lf%lf", &Dx, &Dy);
	if (isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy) == 0) {
		printf("Точка не входит в треугольник");
	}
	else if (isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy) == 1) {
		printf("Точка лежит в треугольнике");
	}
	else if (isintriangle(Ax, Bx, Cx, Ay, By, Cy, Dx, Dy) == 2) {
		printf("Точка лежит на стороне треугольника");
	}
}