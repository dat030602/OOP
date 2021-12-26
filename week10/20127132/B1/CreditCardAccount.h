#pragma once
#include "PaymentHistory.h"

class CreditCardAccount
{
protected:
	string SoThe;
	string NgayPhatHanh;
	string TaiKhoanLienKet;
	//Hạn mức tín dụng
	double creditLimit;
	//Lãi suất
	double interestRate;
	//Thanh toán tối thiểu
	double minPayment;
	//Phí trả chậm 
	double latePenalty;
	//Số dư hiện tại
	double balance;
	//Lịch Sử Giao Dịch
	vector<PaymentHistory> LichSuGiaoDich;
public:
	CreditCardAccount();
	CreditCardAccount(const CreditCardAccount&);
	CreditCardAccount(double, double, double, double, double);
	~CreditCardAccount();
	string LaySoThe();
	double getBalance();
	double getInterestRate();
	double getMinPayment();
	double getLatePenalty();
	void setBalance(double);
	void setMinPayment(double);
	bool charge(double amount);
	void payment(double amount);
	double SoTienConNo();
	virtual void thanhtoan(double, string) = 0;
	virtual void setLichSuGiaoDich(PaymentHistory);
	virtual void showHistory();
	virtual void TaoTaiKhoan();
	virtual void XuatThongTin();
};