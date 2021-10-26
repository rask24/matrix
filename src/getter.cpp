#include "matrix.hpp"

int Matrix::rowSize() const {
	return m_rowSize;
}

int Matrix::colSize() const {
	return m_colSize;
}

int Matrix::rowCapacity() const {
	return m_rowCapacity;
}

int Matrix::colCapacity() const {
	return m_colCapacity;
}

bool Matrix::isSquare() const {
	return m_isSquare;
}

int Matrix::at(int row, int col) const {
	if (row < 0 or m_rowSize <= row or col < 0 or m_colSize <= col) {
		return INV;
	}
	return m_data[row][col];
}
