#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}

/*
 Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
 */

class INotifier {
public:
    virtual void Notify(const string& message) const = 0;
};


class SmsNotifier: public INotifier 
{
public:
    SmsNotifier(string number_) {
        number = number_;
    }
    void Notify(const string& message) const override {
        SendSms(number, message);
    };
    string number;
};

class EmailNotifier: public INotifier 
{
public:
    EmailNotifier(string mail_) {
        mail = mail_;
    };
    void Notify(const string& message) const override {
        SendEmail(mail, message);
    };
    string mail;
};


void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}