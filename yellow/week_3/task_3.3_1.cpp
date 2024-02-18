#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {

    bool check_plus = false;
    bool check_country_code = false;
    bool check_city_code = false;
    bool check_local_number_ = false;
    int insize = international_number.size();
    bool capture_country_code = false;
    bool capture_local_number = false;

    if (international_number[0] == '+') {
        check_plus = true; 
        int line_counter = 0;
        for (int i = 1; i < insize; i++) {
            if (international_number[i] == '-') {
                line_counter++;
            }
            if (line_counter == 0) {
                this->country_code_ = this->country_code_ + international_number[i];
                check_country_code = true;
            } else if (line_counter == 1) {
                if (capture_country_code) {
                    this->city_code_ = this->city_code_ + international_number[i];
                    check_city_code = true;
                }
                if (international_number[i] == '-' && capture_country_code == false) {
                    capture_country_code = true;
                }
            } else if (line_counter >= 2) {
                if (capture_local_number) {
                    this->local_number_ = this->local_number_ + international_number[i];
                    check_local_number_ = true;
                }
                if (international_number[i] == '-' && capture_local_number == false) {
                    capture_local_number = true;
                }
            } 
        }  
    }

    if (check_plus == false || check_country_code == false || check_city_code == false || check_local_number_ == false) {
        throw invalid_argument("some error");
    }

}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
};

string PhoneNumber::GetCityCode() const {
    return city_code_;
};

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
};

string PhoneNumber::GetInternationalNumber() const {
    string internationalNumber = "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
    return internationalNumber;
};


// int main() {
//     PhoneNumber pn1("+7-495-111-22-33");
//     cout << "CountryCode " <<pn1.GetCountryCode() << endl;
//     cout << "CityCode " << pn1.GetCityCode() << endl;
//     cout << "LocalNumber " <<pn1.GetLocalNumber() << endl;
//     cout << "InternationalNumber " <<pn1.GetInternationalNumber() << endl;

//     PhoneNumber pn2("+7-495-1112233");
//     cout << "CountryCode " <<pn2.GetCountryCode() << endl;
//     cout << "CityCode " << pn2.GetCityCode() << endl;
//     cout << "LocalNumber " <<pn2.GetLocalNumber() << endl;
//     cout << "InternationalNumber " <<pn2.GetInternationalNumber() << endl;

//     PhoneNumber pn3("+1-2-coursera-cpp");
//     cout << "CountryCode " <<pn3.GetCountryCode() << endl;
//     cout << "CityCode " << pn3.GetCityCode() << endl;
//     cout << "LocalNumber " <<pn3.GetLocalNumber() << endl;
//     cout << "InternationalNumber " <<pn3.GetInternationalNumber() << endl;


//     return 0;
// }