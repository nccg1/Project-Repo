#include <iostream>
using namespace std;

class PaymentMethod {
public:
    virtual void process(double amount) = 0;   
};


class CardPayment : public PaymentMethod {
public:
    void process(double amount) override {
        cout << "Card Payment: $" << amount << " charged to card." << endl;
    }
};

class CashPayment : public PaymentMethod {
public:
    void process(double amount) override {
        cout << "Cash Payment: $" << amount << " received in cash." << endl;
    }
};

int main() {
    PaymentMethod* payment1 = new CardPayment();
    payment1->process(150.75);

    CashPayment payment2;
    payment2.process(40.00);
   
    return 0;
}