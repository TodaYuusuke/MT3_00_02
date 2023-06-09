#pragma once
#include <Matrix4x4.h>
#include <Novice.h>

// 加算
Matrix4x4 Add(Matrix4x4& m1, Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			result.m[y][x] = m1.m[y][x] + m2.m[y][x];
		}
	}
	return result;
}
// 減算
Matrix4x4 Subtract(Matrix4x4& m1, Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			result.m[y][x] = m1.m[y][x] - m2.m[y][x];
		}
	}
	return result;
}
// 乗算
Matrix4x4 Multiply(Matrix4x4& matrix, float& other) {
	Matrix4x4 result{};
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			result.m[y][x] = matrix.m[y][x] * other;
		}
	}
	return result;
}
Matrix4x4 Multiply(Matrix4x4& m1, Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			result.m[y][x] = (m1.m[y][0] * m2.m[0][x]) +
							(m1.m[y][1] * m2.m[1][x]) +
							(m1.m[y][2] * m2.m[2][x]) +
							(m1.m[y][3] * m2.m[3][x]);
		}
	}
	return result;
}

// 行列式を返す関数
float Determinant(Matrix4x4 matrix) {
	// 行列式
	return (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3]) +
		(matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1]) +
		(matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2]) -

		(matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1]) -
		(matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3]) -
		(matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2]) -
		
		(matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3]) -
		(matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1]) -
		(matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2]) +
		
		(matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1]) +
		(matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3]) +
		(matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2]) +
		
		(matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3]) +
		(matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1]) +
		(matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2]) -
		
		(matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1]) -
		(matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3]) -
		(matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2]) -
		
		(matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0]) -
		(matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0]) -
		(matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0]) +
		
		(matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0]) +
		(matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0]) +
		(matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0]);
}
// 逆行列を返す関数
Matrix4x4 Inverse(Matrix4x4 matrix) {
	Matrix4x4 result{};

	result.m[0][0] = (matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3]) + (matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1]) + (matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2])
		- (matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1]) - (matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3]) - (matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2]);
	result.m[0][1] = - (matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][3]) - (matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][1]) - (matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][2])
		+ (matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][1]) + (matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][3]) + (matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][2]);
	result.m[0][2] = (matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][3]) + (matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][1]) + (matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][2])
		- (matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][1]) - (matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][3]) - (matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][2]);
	result.m[0][3] = -(matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3]) - (matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1]) - (matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2])
		+ (matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1]) + (matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3]) + (matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2]);

	result.m[1][0] = -(matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3]) - (matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0]) - (matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2])
		+ (matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0]) + (matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3]) + (matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2]);
	result.m[1][1] = (matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][3]) + (matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][0]) + (matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][2])
		- (matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][0]) - (matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][3]) - (matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][2]);
	result.m[1][2] = -(matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][3]) - (matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][0]) - (matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][2])
		+ (matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][0]) + (matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][3]) + (matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][2]);
	result.m[1][3] = (matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3]) + (matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0]) + (matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2])
		- (matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0]) - (matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3]) - (matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2]);

	result.m[2][0] = (matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3]) + (matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0]) + (matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1])
		- (matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0]) - (matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3]) - (matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1]);
	result.m[2][1] = -(matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][3]) - (matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][0]) - (matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][1])
		+ (matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][0]) + (matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][3]) + (matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][1]);
	result.m[2][2] = (matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][3]) + (matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][0]) + (matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][1])
		- (matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][0]) - (matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][3]) - (matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][1]);
	result.m[2][3] = -(matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3]) - (matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0]) - (matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1])
		+ (matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0]) + (matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3]) + (matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1]);

	result.m[3][0] = -(matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2]) - (matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0]) - (matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1])
		+ (matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0]) + (matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2]) + (matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1]);
	result.m[3][1] = (matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][2]) + (matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][0]) + (matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][1])
		- (matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][0]) - (matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][2]) - (matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][1]);
	result.m[3][2] = -(matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][2]) - (matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][0]) - (matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][1])
		+ (matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][0]) + (matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][2]) + (matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][1]);
	result.m[3][3] = (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2]) + (matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0]) + (matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1])
		- (matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0]) - (matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2]) - (matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);

	float constant = 1.0f / Determinant(matrix);
	return Multiply(result, constant);
}
// 転置行列を返す関数
Matrix4x4 Transpose(Matrix4x4 matrix) {
	Matrix4x4 result{};
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			result.m[y][x] = matrix.m[x][y];
		}
	}
	return result;
}

// 単位行列の作成
static Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 result{};
	for (int i = 0; i < 4; i++) {
		result.m[i][i] = 1;
	}
	return result;
}

// 描画用定数
const int kRowHeight = 20;
const int kColumnWidth = 60;

// 4x4行列の表示
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {


	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + (row + 1) * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}
