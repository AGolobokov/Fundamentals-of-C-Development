#include <map>
#include <iostream>

using namespace std;

class Function {
public:
    void AddPart(char ch, double new_value){
        if (ch == '-') {
            operands[ch] = new_value;
        }
        else if (ch == '+') {
            operands[ch] = new_value;
        } else if (ch == '*') {
            operands[ch] = new_value;
        }
    };
    
    double Apply(double value) const {
        char ch_n = '-';
        char ch_p = '+';
        char ch_s = '*';
        char ch_d = '/';
        for (auto op : operands) {
            if (op.first == ch_n) {
                value = value - op.second;
            } else if (op.first == ch_p) {
                value = value + op.second;
            } else if (op.first == ch_s) {
                value = value * op.second;
            } else if (op.first == ch_d) {
                value = value / op.second;
            }
        }
        return value;
    };
    
    void Invert(){
        char ch_n = '-';
        char ch_p = '+';
        char ch_s = '*';
        char ch_d = '/';
        double pl = (double)operands.at(ch_p);//36
        double ng = (double)operands.at(ch_n);//10
        double sp = (double)operands.at(ch_s);//10
        operands.erase(ch_n);
        operands.erase(ch_p);
        operands.erase(ch_s);
        operands[ch_n] = pl;
        operands[ch_p] = ng;
        operands[ch_d] = sp;

    };

private:
map <char, double> operands;
};


struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);                  // * 4
  function.AddPart('-', image.freshness * params.b);// -2*2
  function.AddPart('+', image.rating * params.c);// + 6*6 = 36
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl; //(52 -36 + 4() /4 = 5
  return 0;
}