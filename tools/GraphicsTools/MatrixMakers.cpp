#include "stdafx.h"
#include "MatrixMakers.h"
#include "Matrix.h"
#include "Vector.h"
#include <math.h>

Matrix* modelMatrix(Matrix* r, Vector3* p) {
	Matrix* temp = new Matrix(r->rows + 1, r->cols + 1);
	for (int i = 0; i < r->rows; ++i) {
		int j;
		for (j = 0; j < r->cols; ++j) {
			temp->set(i, j, r->get(i, j));
		}
		temp->set(i, j, p->vector[i]);
	}
	temp->set(temp->rows - 1, temp->cols - 1, 1);
	return temp;
}

Matrix* viewMatrix(Vector3* P, Vector3* N, Vector3* V) {
	Matrix *m = new Matrix(4,4);

	Vector3 n = *N * (-1.0 / N->magnitude());
	Vector3 u = (V->cross(&(*N * -1.0))) * (1 / ((V->cross(N)).magnitude()));
	Vector3 v = n.cross(&u);

    for (int i = 0; i < 3; ++i)
    {
		m->set(0, i, u.vector[i]);
		m->set(1, i, v.vector[i]);
		m->set(2, i, n.vector[i]);
		m->set(3, i, 0);
    }

	m->set(0, 3, -1.0 * u.dot(P));
	m->set(1, 3, -1.0 * v.dot(P));
	m->set(2, 3, -1.0 * n.dot(P));
	m->set(3, 3, 1.0);

    return m;
}

Matrix* rotateMatrix(float thetaDeg, char axis) {
	float thetaRad = thetaDeg * (3.14159 / 180.0);
	float matrixX[9] = {1, 0, 0, 0, cos(thetaRad), sin(thetaRad), 0, -1.0 * sin(thetaRad), cos(thetaRad)};
	float matrixY[9] = {cos(thetaRad), 0, -1.0 * sin(thetaRad), 0, 1, 0, sin(thetaRad), 0, cos(thetaRad)};
	float matrixZ[9] = {cos(thetaRad), sin(thetaRad), 0, -1.0 * sin(thetaRad), cos(thetaRad), 0, 0, 0, 1};

	switch (axis) {
	case 'x':
	case 'X':
		return new Matrix(3, 3, matrixX);
	case 'y':
	case 'Y':
		return new Matrix(3, 3, matrixY);
	case 'z':
	case 'Z':
		return new Matrix(3, 3, matrixZ);
	default:
		return new Matrix(3, 3);
	}
}

Matrix* translateMatrix(float x, float y, float z) {
	float matrix[3] = {x, y, z};
	return new Matrix(3, 1, matrix);
}

Matrix* perspectiveMatrix() {
	// TODO: Implement.
	return NULL;
}

Matrix* viewportMatrix() {
	// TODO: Implement.
	return NULL;
}