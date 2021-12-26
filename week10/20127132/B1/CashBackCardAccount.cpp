#include "CashBackCardAccount.h"

CashBackCardAccount::CashBackCardAccount()
{
    cashBackRate = 0;
    currentCashBack = 0;
}

CashBackCardAccount::CashBackCardAccount(const CashBackCardAccount& ps) :CreditCardAccount(ps)
{
    this->cashBackRate = ps.cashBackRate;
    this->currentCashBack = ps.currentCashBack;
}

CashBackCardAccount::CashBackCardAccount(double creditLimit, double interestRate, double minPayment, double latePenalty,
    double balance, float cashBackRate, int currentCashBack) :
    CreditCardAccount(creditLimit, interestRate, minPayment, latePenalty, balance)
{
    this->cashBackRate = cashBackRate;
    this->currentCashBack = currentCashBack;
}

CashBackCardAccount::~CashBackCardAccount()
{
    cashBackRate = 0;
    currentCashBack = 0;
}

double CashBackCardAccount::getCurrentCashBack()
{
    return currentCashBack;
}

bool CashBackCardAccount::charge(double amount)
{
    if (CreditCardAccount::charge(amount))
    {
        amount *= cashBackRate;
        currentCashBack += (int)amount;
        return true;
    }
    return false;
}
void CashBackCardAccount::redeemCashBack()
{
    balance -= currentCashBack;
    currentCashBack = 0;
}

void CashBackCardAccount::TaoTaiKhoan()
{
    CreditCardAccount::TaoTaiKhoan();
    cout << "Nhap Ti Le Hoan Tien: ";
    cin >> cashBackRate;
    cout << "Nhap So Du Hien Tai: ";
    cin >> currentCashBack;
}
void CashBackCardAccount::XuatThongTin()
{
    CreditCardAccount::XuatThongTin();
    cout << "Ti Le Hoan Tien: " << cashBackRate << endl;
    cout << "So Du Hien Tai: " << currentCashBack << endl;
}

void CashBackCardAccount::thanhtoan(double amount, string date)
{
    if (charge(amount))
        redeemCashBack();
    cout << "Noi Dung: ";
    string temp;
    cin.ignore();
    getline(cin, temp);
    LichSuGiaoDich.push_back(PaymentHistory(SoThe,amount, temp, date));
}