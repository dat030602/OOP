#pragma once
#include "CreditCardAccount.h"
class RewardCardAccount :public CreditCardAccount
{
    float rewardRate;
    int currentPoints;
public:
    RewardCardAccount();
    RewardCardAccount(const RewardCardAccount&);
    RewardCardAccount(double, double, double, double, double, float, int);
    ~RewardCardAccount();
    double getCurrentPoints();
    bool charge(double);
    void payWithPoints(int);
    void TaoTaiKhoan();
    void XuatThongTin();
    void thanhtoan(double, string);
};