// GraphicsTools.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"
#include "MatrixMakers.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix* Mvw = viewMatrix(&Vector3(10, 10, 10), &Vector3(-1, -1, -1), &Vector3(0, 0, 1));
	Matrix* Mpersp = perspectiveMatrix(6, -4, 4, -4, 4, -5, -25);
	Matrix* Mviewport = viewportMatrix(-100, 100, -100, 100);

	Mvw->print("Mvw");
	Mpersp->print("Mpersp");
	Mviewport->print("Mviewport");

	delete Mvw, Mpersp, Mviewport;

	return 0;
}

