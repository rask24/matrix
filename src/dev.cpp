#include "matrix.hpp"

void Matrix::dev() const {
	std::cout << "row size    : " << m_rowSize << std::endl;
	std::cout << "row col     : " << m_colSize << std::endl;
	std::cout << "row capacity: " << m_rowCapacity << std::endl;
	std::cout << "row capacity: " << m_colCapacity << std::endl;
	std::cout << "row address : " << m_data << std::endl;
	for (int i = 0; i < m_rowSize; ++i) {
		std::cout << "col address : " << i << "->" << m_data[i] << std::endl;
	}
}
