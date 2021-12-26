#pragma once
#include "PaymentHistory.h"
#include "CreditCardAccount.h"

class PaymentAccount
{
	string SoTaiKhoan;
	double SoDu;
	string NgayPhatHanh;
	vector<PaymentHistory> LichSuGiaoDich;
	//Nợ kỳ trước
	double SoNo;
	vector<CreditCardAccount*> m_creditCard;
public:
	PaymentAccount();
	PaymentAccount(const PaymentAccount&);
	PaymentAccount(string, double, string, vector<PaymentHistory>);
	~PaymentAccount();
	int lenght();
	int getNumber(char);
	double getBalance();
	string GetNgayPhatHanh();
	bool transferTo(double amount);
	void showHistory();
	void showListCard();
	void thanhtoan(int, double, string);
	void addCreditCardAccount(CreditCardAccount*);
	void payment(int, string);
	friend istream& operator>> (istream&, PaymentAccount&);
	friend ostream& operator<< (ostream&, PaymentAccount&);
};