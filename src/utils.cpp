#include "matrix.hpp"

void Matrix::print() const {
	for (int i = 0; i < m_rowSize; ++i) {
		for (int j = 0; j < m_colSize; ++j) {
			std::cout << m_data[i][j];
			if (j != m_colSize - 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Matrix::type() const {
	if (m_rowSize == m_colSize) {
		std::cout << m_rowSize << "th square Matrix" << std::endl;
	} else {
		std::cout << "size: " << m_rowSize << "x" << m_colSize << std::endl;
	}
}

int Matrix::numOfDigit(int num) {
	int ret = 0;
	while (num) {
		++ret;
		num /= 10;
	}
	return ret;
}
