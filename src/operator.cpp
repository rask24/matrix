#include "matrix.hpp"

int *Matrix::operator[](int row) const {
	return m_data[row];
}

int *&Matrix::operator[](int row) {
	return m_data[row]; 
}

Matrix &Matrix::operator=(const Matrix &mat) {
	m_rowSize = mat.m_rowSize;
	m_colSize = mat.m_colSize;
	m_rowCapacity = mat.m_rowCapacity;
	m_colCapacity = mat.m_colCapacity;
	m_data = mat.m_data;
	m_isSquare = mat.m_isSquare;
	return *this;
}

Matrix Matrix::operator+(const Matrix &mat) {
	if (m_rowSize != mat.m_rowSize or m_colSize != mat.m_colSize) {
		std::cerr << "operator +: matrix size in NOT the same" << std::endl;
		exit(1);
	}
	Matrix ret(mat);
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			ret.m_data[i][j] += m_data[i][j];
		}
	}
	return ret;
}

Matrix Matrix::operator-(const Matrix &mat) {
	if (m_rowSize != mat.m_rowSize or m_colSize != mat.m_colSize) {
		std::cerr << "operator +: matrix size in NOT the same" << std::endl;
		exit(1);
	}
	Matrix ret(mat);
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			ret.m_data[i][j] -= m_data[i][j];
		}
	}
	return ret;
}

Matrix &Matrix::operator*(int c) {
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] *= c;
		}
	}
	return *this;
}

void Matrix::operator*=(int c) {
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] *= c;
		}
	}
}

Matrix Matrix::operator*(const Matrix &mat) {
	if (m_colSize != mat.m_rowSize) {
		std::cerr << "error: Matrix Size is INVALID for multiple." << std::endl;
		exit(1);
	}
	Matrix ret(m_rowSize, mat.m_colSize);
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < mat.m_colSize; ++j) {
			for (int k = 0; k < m_colSize; ++k) {
				ret.m_data[i][j] += m_data[i][k] * mat.m_data[k][j];
			}
		}
	}
	return ret;
}
