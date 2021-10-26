#include "matrix.hpp"

Matrix::Matrix()
	: m_rowSize(0)
	, m_colSize(0)
	, m_rowCapacity(0)
	, m_colCapacity(0)
	, m_data(NULL)
	, m_isSquare(false)
	, m_maxDigit(0)
{
}

Matrix::Matrix(int rowSize, int colSize)
	: m_rowSize(rowSize)
	, m_colSize(colSize)
	, m_rowCapacity(rowSize)
	, m_colCapacity(colSize)
	, m_isSquare(rowSize == colSize)
	, m_maxDigit(1)
{
	if (rowSize < 0 or colSize < 0) {
		std::cerr << "rowSize or colSize is NOT positive integer." << std::endl;
		exit(1);
		//m_rowSize = 0;
		//m_colSize = 0;
		//m_rowCapacity = 0;
		//m_colCapacity = 0;
		//return;
	}
	m_data = new int* [rowSize];
	for (int i = 0; i < rowSize; ++i) {
		m_data[i] = new int [colSize];
	}
}

Matrix::Matrix(int rowSize, int colSize, int val)
	: m_rowSize(rowSize)
	, m_colSize(colSize)
	, m_rowCapacity(rowSize)
	, m_colCapacity(colSize)
	, m_isSquare(rowSize == colSize)
	, m_maxDigit(numOfDigit(val))
{
	if (rowSize < 0 or colSize < 0) {
		std::cerr << "rowSize or colSize is NOT positive integer." << std::endl;
		exit(1);
		//m_rowSize = 0;
		//m_colSize = 0;
		//m_rowCapacity = 0;
		//m_colCapacity = 0;
		return;
	}
	m_data = new int* [rowSize];
	for (int i = 0; i < rowSize; ++i) {
		m_data[i] = new int [colSize];
		for (int j = 0; j < colSize; ++j) {
			m_data[i][j] = val;
		}
	}
}

Matrix::Matrix(const Matrix &mat)
	: m_rowSize(mat.m_rowSize)
	, m_colSize(mat.m_colSize)
	, m_rowCapacity(mat.m_rowCapacity)
	, m_colCapacity(mat.m_colCapacity)
	, m_isSquare(mat.m_isSquare)
	, m_maxDigit(mat.m_maxDigit)
{
	m_data = new int* [m_rowCapacity];
	for (int i = 0; i < m_rowSize; ++i) {
		m_data[i] = new int [m_colCapacity];
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] = mat.m_data[i][j];
		}
	}
}
