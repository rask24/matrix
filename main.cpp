#include "matrix.hpp"

int main() {
	Matrix m(2, 3, 3);
	Matrix n(2, 3, 5);
	Matrix j = m - n;
	m.print();
	n.print();
	j.print();
#ifdef LEAKS
	system("leaks matrix_main");
#endif
	return 0;
}
