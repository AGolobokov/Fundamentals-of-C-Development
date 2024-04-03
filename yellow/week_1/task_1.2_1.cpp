#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
    public:

    Matrix () {
        matrix.assign(0, vector<int>(0));
        rows_number = 0;
        column_number = 0;
    } 

    Matrix(int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("out_of_range");
        } else {
            if (num_rows == 0 || num_cols == 0) {
                num_rows = 0;
                num_cols = 0;
            }
            matrix.assign(num_rows, vector<int>(num_cols));
            rows_number = num_rows;
            column_number = num_cols;
        }
    } 

    vector<int>&  operator[](int value) {
        return matrix[value];
    }

    const vector<int>&  operator[](int value) const {
        return matrix[value];
    }

    void Reset(int new_rows, int new_columns) {
        if (new_rows < 0 || new_columns < 0) {
            throw out_of_range("out_of_range");
        } else {
            if (new_rows == 0 || new_columns == 0) {
                new_rows = 0;
                new_columns = 0;
            }
            matrix.assign(new_rows, vector<int>(new_columns));
            rows_number = new_rows;
            column_number = new_columns;
        }
    }

    int At(int x, int y) const {
        if (x >= rows_number || y >= column_number || x < 0 || y < 0) {
            throw out_of_range("out_of_range");
        } else {
            return matrix[x][y];
        }
    }

    int& At(int x, int y) {
        if (x >= rows_number || y >= column_number || x < 0 || y < 0) {
            throw out_of_range("out_of_range");
        } else {
            return matrix[x][y];
        }
    }

    int GetNumRows() const {
        return rows_number;
    }
    
    int GetNumColumns() const {
        return column_number;
    }

    private:
    vector<vector<int>> matrix;
    int rows_number;
    int column_number;
};

istream& operator>>(istream& stream, Matrix &m) {
    int x = 0;
    int y = 0;
    stream >> x;
    stream >> y;
    m.Reset(x, y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int z = 0;
            stream >> z;
            m[i][j] = z;
        }
    }
    return stream;
};

ostream& operator<<(ostream& stream, const Matrix &m) {
    stream << m.GetNumRows();
    stream << " ";
    stream << m.GetNumColumns();
    stream << endl;
    for (int i = 0; i < m.GetNumRows(); i++) {
        for (int j = 0; j < m.GetNumColumns(); j++) {
            stream << m.At(i, j) << " ";
        }
        stream << endl;
    }
    return stream;
};

bool operator==(const Matrix &lhs, const Matrix &rhs){
    if (lhs.GetNumRows() != rhs.GetNumRows()) {
        return false;
    }
    if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
        return false;
    }
    for (int i = 0; i < lhs.GetNumRows(); i++) {
        for (int j = 0; j < lhs.GetNumColumns(); j++) {
             if (lhs[i][j] != rhs[i][j]) {
                return false;
             }
        }
    }
    return true;
};

Matrix operator+(const Matrix &lhs, const Matrix &rhs){
    if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns())) {
        throw invalid_argument("Invalid syntax");
    }

    Matrix m(lhs.GetNumRows(), lhs.GetNumColumns());
    for (int i = 0; i < lhs.GetNumRows(); i++) {
        for (int j = 0; j < lhs.GetNumColumns(); j++) {
            m[i][j] = (lhs[i][j]+ rhs[i][j]);
        }
    }
    return m;

};

int main() {
  Matrix one;
  Matrix two;
  Matrix three;
  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
