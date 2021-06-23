#include "practicelib.h"
int istriangle(double Ax, double Bx, double Cx, double Ay, double By, double Cy) {
	double isit = (Ay - By) * Cx + (Bx - Ax) * Cy + (Ax * By - Bx * Ay);
	if (isit <= 0.00001 && isit >= 0.00) {
		return 0;
	}
	else
		return 1;
}
int isintriangle(double Ax, double Bx, double Cx, double Ay, double By, double Cy, double Dx, double Dy) {
	long double par1, par2, par3;
	par1 = ((Ax - Dx) * (By - Ay)) - ((Bx - Ax) * (Ay - Dy));
	par2 = ((Bx - Dx) * (Cy - By)) - ((Cx - Bx) * (By - Dy));
	par3 = ((Cx - Dx) * (Ay - Cy)) - ((Ax - Cx) * (Cy - Dy));
	if (par1 * par2 > 0 && par2 * par3 > 0) {
		return 1;
	}
	else if (par1 == 0 || par2 == 0 || par3 == 0) {
		return 2;
	}
	else return 0;
}