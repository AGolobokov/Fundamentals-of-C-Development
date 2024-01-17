#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class FunnctionPart {
public:
    FunnctionPart(char _operation, double _value) : operation(_operation), value(_value) {}
    double Apply(double _value) const {
        if (operation == '+') {
            _value+=value;
        } else {
            _value-=value;
        }
        return _value;
    }
    void Invert(){ 
        if (operation == '-') {
            operation = '+';
        } else if (operation == '+') {
            operation = '-';
        }
    }
private:
char operation;
double value;    
};

class Function {
public:
    void AddPart(char ch, double new_value){
        operands.push_back(FunnctionPart(ch, new_value));
    }
    
    double Apply(double value) const {
        char ch_n = '-';
        char ch_p = '+';
        for (auto x : operands) {
            value = x.Apply(value);
        }
        return value;
    }
    
    void Invert(){
        for (auto &x : operands) {
            x.Invert();
        }
        reverse(begin(operands), end(operands));
    }
    
private:
vector <FunnctionPart> operands;
};

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('-', image.freshness * params.a + params.b);// -,  2*4 + 2 = 10
//   function.AddPart('+', image.rating * params.c);//+, 6*6 = 36
//   return function;
// };

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// };

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// };

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   cout << ComputeImageWeight(params, image) << endl;
//   cout << ComputeQualityByWeight(params, image, 46) << endl;
//   return 0;
// }
