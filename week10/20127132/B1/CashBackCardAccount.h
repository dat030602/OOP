#include "CreditCardAccount.h"

class CashBackCardAccount : public CreditCardAccount
{
    float cashBackRate;
    int currentCashBack;
public:
    CashBackCardAccount();
    CashBackCardAccount(const CashBackCardAccount&);
    CashBackCardAccount(double, double, double, double, double, float, int);
    ~CashBackCardAccount();
    double getCurrentCashBack();
    bool charge(double);
    void redeemCashBack();
    void TaoTaiKhoan();
    void XuatThongTin();
    void thanhtoan(double, string);
};