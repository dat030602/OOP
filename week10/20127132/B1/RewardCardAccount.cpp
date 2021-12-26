#include "RewardCardAccount.h"

RewardCardAccount::RewardCardAccount()
{
    rewardRate = 0.2;
    currentPoints = 0;
}
RewardCardAccount::RewardCardAccount(const RewardCardAccount& ps) :CreditCardAccount(ps)
{
    this->rewardRate = ps.rewardRate;
    this->currentPoints = ps.currentPoints;
}

RewardCardAccount::RewardCardAccount(double creditLimit, double interestRate, double minPayment, double latePenalty, double balance,
    float rewardRate, int currentPoints) :
    CreditCardAccount(creditLimit, interestRate, minPayment, latePenalty, balance)
{
    this->rewardRate = rewardRate;
    this->currentPoints = currentPoints;
}

RewardCardAccount::~RewardCardAccount()
{
    rewardRate = 0;
    currentPoints = 0;
}

double RewardCardAccount::getCurrentPoints()
{
    return currentPoints;
}

bool RewardCardAccount::charge(double amount)
{
    if (CreditCardAccount::charge(amount))
    {
        amount *= rewardRate;
        currentPoints += (int)amount;
        return true;
    }
    return false;
}

void RewardCardAccount::payWithPoints(int pAmount)
{
    if (pAmount <= currentPoints)
        currentPoints -= pAmount;
}

void RewardCardAccount::TaoTaiKhoan()
{
    CreditCardAccount::TaoTaiKhoan();
    cout << "Nhap Ti Le Hoan Diem: ";
    cin >> rewardRate;
    cout << "Nhap So Diem Hien Tai: ";
    cin >> currentPoints;
}
void RewardCardAccount::XuatThongTin()
{
    CreditCardAccount::XuatThongTin();
    cout << "Ti Le Hoan Diem: " << rewardRate << endl;
    cout << "So Diem Hien Tai: " << currentPoints << endl;
}

void RewardCardAccount::thanhtoan(double amount, string date)
{
    if (charge(amount))
        payWithPoints(amount);
    cout << "Noi Dung: ";
    string temp;
    cin.ignore();
    getline(cin, temp);
    LichSuGiaoDich.push_back(PaymentHistory(SoThe, amount, temp, date));
}