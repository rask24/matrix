#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

class Matrix {
	private:
		int m_rowSize;
		int m_colSize;
		int m_rowCapacity;
		int m_colCapacity;
		int **m_data;
		bool m_isSquare;
		int m_maxDigit;

		int numOfDigit(int num);

		static const int INV = 10000000;
	public:
		Matrix();
		Matrix(int rowSize, int colSize);
		Matrix(int rowSize, int colSize, int val);
		Matrix(const Matrix &m);

		int rowSize() const;
		int colSize() const;
		int rowCapacity() const;
		int colCapacity() const;
		bool isSquare() const;
		int at(int row, int col) const;
		int trace() const;

		void rowReserve(int size);
		void colReserve(int size);
		void rowResize(int size);
		void colResize(int size);
		void zeros();
		void ones();
		void identity();
		void scalar(int c);

		int *operator[](int row) const;
		int *&operator[](int row);
		Matrix &operator*(int c);
		Matrix &operator=(const Matrix &mat);
		Matrix operator+(const Matrix &mat);
		Matrix operator-(const Matrix &mat);
		void operator*=(int c);
		Matrix operator*(const Matrix &mat);

		void print() const;
		void type() const;
		void dev() const;
};

#endif
