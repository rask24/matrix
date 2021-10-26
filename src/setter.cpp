#include "matrix.hpp"

//void rowReserve(int size);
//void colReserve(int size);
//void rowResize(int size);
//void colResize(int size);

void Matrix::rowReserve(int size) {
	if (size <= m_rowCapacity) {
		return;
	}
	int cap = 1;
	while (cap < size) {
		cap *= 2;
	}
	m_rowCapacity = cap;
	int **tmp_data = new int* [cap];
	for (int i = 0; i < m_rowSize; ++i) {
		tmp_data[i] = m_data[i];
	}
	delete [] m_data;
	m_data = tmp_data;
}

void Matrix::colReserve(int size) {
	if (size <= m_colCapacity) {
		return;
	}
	int cap = 1;
	while (cap < size) {
		cap *= 2;
	}
	m_colCapacity = cap;
	for (int i = 0; i < m_rowSize; ++i) {
		int *tmp_data = new int [cap];
		for (int j = 0; j < m_colSize; ++j) {
			tmp_data[j] = m_data[i][j];
		}
		delete m_data[i];
		m_data[i] = tmp_data;
	}
}

void Matrix::rowResize(int size) {
	if (size <= m_rowSize) {
		return;
	}
	rowReserve(size);
	m_rowSize = size;
}

void Matrix::colResize(int size) {
	if (size <= m_colSize) {
		return;
	}
	colReserve(size);
	m_colSize = size;
}

void Matrix::zeros() {
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] = 0;
		}
	}
}

void Matrix::ones() {
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] = 1;
		}
	}
}

void Matrix::identity() {
	if (m_rowSize != m_colSize) {
		std::cerr << "error: This is NOT square Matrix." << std::endl;
		return;
	}
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] = (i == j) ? 1 : 0;
		}
	}
}

void Matrix::scalar(int c) {
	if (m_rowSize != m_colSize) {
		std::cerr << "error: This is NOT square Matrix." << std::endl;
		return;
	}
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			m_data[i][j] = (i == j) ? c : 0;
		}
	}
}
