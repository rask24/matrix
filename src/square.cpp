#include "matrix.hpp"

int Matrix::trace() const {
	if (!m_isSquare) {
		std::cerr << "error: This is NOT square Matrix." << std::endl;
		return INV;
	}
	int ret = 0;
	for (int i = 0; i < m_rowSize; ++i) {
		ret += m_data[i][i];
	}
	return ret;
}
