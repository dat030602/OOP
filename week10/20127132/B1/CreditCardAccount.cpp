#include "CreditCardAccount.h"

CreditCardAccount::CreditCardAccount()
{
	creditLimit = 30000000;
	interestRate = 0;
	minPayment = 0;
	latePenalty = 2000000;
	balance = 0;
}

CreditCardAccount::CreditCardAccount(const CreditCardAccount& ps)
{
	this->creditLimit = 30000000;
	this->interestRate = ps.interestRate;
	this->minPayment = ps.minPayment;
	this->latePenalty = 2000000;
	this->balance = ps.balance;
}

CreditCardAccount::CreditCardAccount(double creditLimit, double interestRate,
	double minPayment, double latePenalty, double balance)
{
	this->creditLimit = 30000000;
	this->interestRate = interestRate;
	this->minPayment = minPayment;
	this->latePenalty = 2000000;
	this->balance = balance;
}

CreditCardAccount::~CreditCardAccount()
{
	creditLimit = 0;
	interestRate = 0;
	minPayment = 0;
	latePenalty = 0;
	balance = 0;
}

double CreditCardAccount::getBalance()
{
	return balance;
}

double CreditCardAccount::getLatePenalty() 
{ 
	return latePenalty; 
}

bool CreditCardAccount::charge(double amount)
{
	if (amount + balance <= creditLimit)
	{
		balance += amount;
		return true;
	}
	return false;
}

string CreditCardAccount::LaySoThe()
{
	return SoThe;
}
void CreditCardAccount::payment(double amount)
{
	balance -= amount;
}

void CreditCardAccount::setBalance(double balance)
{
	this->balance = balance;
}

double CreditCardAccount::getInterestRate()
{
	return interestRate;
}

void CreditCardAccount::setMinPayment(double minPayment)
{
	this->minPayment = minPayment;
}

double CreditCardAccount::getMinPayment()
{
	return minPayment;
}

void CreditCardAccount::TaoTaiKhoan()
{
	cout << "Nhap So The: ";
	cin >> SoThe;
	cout << "Nhap Ngay Phat Hanh: ";
	cin >> NgayPhatHanh;
	cout << "Nhap So Tai Khoan Lien Ket: ";
	cin >> TaiKhoanLienKet;
	cout << "Nhap Han Muc Tin Dung: ";
	cin >> creditLimit;
	cout << "Nhap Lai Suat: ";
	cin >> interestRate;
	cout << "Nhap Thanh Toan Toi Thieu: ";
	cin >> minPayment;
	cout << "Nhap Phi Tra Cham: ";
	cin >> latePenalty;
	cout << "Nhap So Du Hien Tai: ";
	cin >> balance;
}
void CreditCardAccount::XuatThongTin()
{
	cout.precision(0);
	cout << "So The: " << SoThe << endl;
	cout << "Ngay Phat Hanh: " << NgayPhatHanh << endl;
	cout << "So Tai Khoan Lien Ket: " << TaiKhoanLienKet << endl;
	cout << "Han Muc Tin Dung: " << fixed << creditLimit << endl;
	cout << "Lai Suat: " << fixed << interestRate << endl;
	cout << "Thanh Toan Toi Thieu: " << fixed << minPayment << endl;
	cout << "Phi Tra Cham: " << fixed << latePenalty << endl;
	cout << "So Du Hien Tai: " << fixed << balance << endl;
}

void CreditCardAccount::setLichSuGiaoDich(PaymentHistory a)
{
	LichSuGiaoDich.push_back(a);
}
void CreditCardAccount::showHistory()
{
	for (int i = 0; i < LichSuGiaoDich.size(); i++)
		LichSuGiaoDich[i].showHistory();
}

double CreditCardAccount::SoTienConNo()
{
	double No = 0;
	for (int i = 0; i < LichSuGiaoDich.size(); i++)
		No += LichSuGiaoDich[i].getSoTienChuyenKhoan();
	return No * interestRate;
}