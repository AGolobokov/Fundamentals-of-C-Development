#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
    ostringstream output1;
    PRINT_VALUES(output1, 14, "red belt");
    ASSERT_EQUAL(output1.str(), "14\nred belt\n");
    ostringstream output2;
    PRINT_VALUES(output2,"\\n",12);
    ASSERT_EQUAL(output2.str(), "\\n\n12\n");
  }, "PRINT_VALUES usage example");
}
