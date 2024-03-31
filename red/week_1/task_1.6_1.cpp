#include "test_runner.h"
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
    public:
    Table (size_t string, size_t column) {
        matrix.assign(string, vector<T>(column));
        string_number = string;
        column_number = column;
    } 

    vector<T>&  operator[](size_t value) {
        return matrix[value];
    }

    const vector<T>&  operator[](size_t value) const {
        return matrix[value];
    }

    void Resize(size_t new_string, size_t new_column) {
        T copy_matrix[string_number][column_number];
        for (int i = 0; i < string_number; i++) {
            for (int j = 0; j < column_number; j++) {
                copy_matrix[i][j] = matrix[i][j];
            }
        }
        matrix.assign(new_string, vector<T>(new_column));
        int valid_string = 0;
        int valid_column = 0;
        if (new_string > string_number) {
            valid_string = string_number;
        } else {
            valid_string = new_string;
        }

        if (new_column > column_number) {
            valid_column = column_number;
        } else {
            valid_column = new_column;
        }

        for (int i = 0; i < valid_string; i++) {
            for (int j = 0; j < valid_column; j++) { 
                matrix[i][j] = copy_matrix[i][j];
            }
        }
        string_number = new_string;
        column_number = new_column;
    }

    const pair<size_t, size_t> Size() const {
        return make_pair(string_number, column_number);
    }
    private:
    vector<vector<T>> matrix;
    size_t string_number;
    size_t column_number;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
  t.Resize(4, 5);
  ASSERT_EQUAL(t.Size().first, 4u);
  ASSERT_EQUAL(t.Size().second, 5u);
}

int main() {

  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
