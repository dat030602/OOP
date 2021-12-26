#include "PaymentAccount.h"

PaymentAccount::PaymentAccount()
{
	SoTaiKhoan = "";
	SoDu = 0;
	SoNo = 0;
	NgayPhatHanh = "";
	LichSuGiaoDich.clear();
}

PaymentAccount::PaymentAccount(const PaymentAccount& ps)
{
	this->SoTaiKhoan = ps.SoTaiKhoan;
	this->SoDu = ps.SoDu;
	this->SoNo = ps.SoNo;
	this->NgayPhatHanh = ps.NgayPhatHanh;
	this->LichSuGiaoDich = ps.LichSuGiaoDich;
}

PaymentAccount::PaymentAccount(string SoTaiKhoan, double SoDu, string NgayPhatHanh, vector<PaymentHistory> LichSuGiaoDich)
{
	this->SoTaiKhoan = SoTaiKhoan;
	this->SoDu = SoDu;
	this->NgayPhatHanh = NgayPhatHanh;
	this->LichSuGiaoDich = LichSuGiaoDich;
}

PaymentAccount::~PaymentAccount()
{
	SoTaiKhoan = "";
	SoDu = 0;
	SoNo = 0;
	NgayPhatHanh = "";
	LichSuGiaoDich.clear();
	for (int i = 0; i < m_creditCard.size(); i++)
	{
		delete m_creditCard[i];
		m_creditCard[i] = nullptr;
	}
}

void PaymentAccount::showHistory()
{
	for (int i = 0; i < m_creditCard.size(); i++)
	{
		SoNo += m_creditCard[i]->getLatePenalty() + m_creditCard[i]->getBalance();
		m_creditCard[i]->setBalance(0);
		m_creditCard[i]->showHistory();
	}
	if (m_creditCard.size() != 0)
		SoNo *= (100 - m_creditCard[0]->getInterestRate()) / 100;
	int size = LichSuGiaoDich.size();
	for (int i = 0; i < size; i++)
		LichSuGiaoDich[i].showHistory();
	cout << endl;

	for (int i = 0; i < m_creditCard.size(); i++)
		m_creditCard[i]->showHistory();

	cout.precision(0);
	cout << "So Tien Con No: " << fixed << SoNo << endl;
}

double PaymentAccount::getBalance()
{
	return SoDu;
}

string PaymentAccount::GetNgayPhatHanh()
{
	return NgayPhatHanh;
}

int PaymentAccount::getNumber(char a)
{
	return a - '0';
}

bool PaymentAccount::transferTo(double amount)
{
	if (SoDu >= amount)
	{
		SoDu -= amount;
		return true;
	}
	return false;
}

istream& operator>> (istream& is, PaymentAccount& ps)
{
	cout << "Nhap So Tai Khoan: ";
	is >> ps.SoTaiKhoan;
	cout << "Nap Tien: ";
	is >> ps.SoDu;
	cout << "Ngay Tao Tai Khoan: ";
	is >> ps.NgayPhatHanh;
	return is;
}
ostream& operator<< (ostream& os, PaymentAccount& ps)
{
	os << "So Tai Khoan: " << ps.SoTaiKhoan << endl;
	os.precision(0);
	os << "So Du Tai Khoan: " << fixed << ps.SoDu << endl;
	os << "Ngay Phat hanh: " << ps.NgayPhatHanh << endl;
	return os;
}

void PaymentAccount::payment(int choose, string date)
{
	if (choose == 1)
	{
		double temp = 0;
		for (int i = 0; i < m_creditCard.size(); i++)
			temp += m_creditCard[i]->getBalance();
		double pay = SoDu - temp - SoNo;
		if (pay >= 0)
		{
			if (transferTo(temp + SoNo))
			{
				cout << "Cam On Ban Da Thanh Toan\n";
				LichSuGiaoDich.push_back(PaymentHistory(SoTaiKhoan, temp + SoNo, "Tra Tien The Tin Dung", date));
				for (int i = 0; i < m_creditCard.size(); i++)
					m_creditCard[i]->setBalance(0);
				SoNo = 0;
			}
			else
				cout << "Tai Khoan Khong Du De Thanh Toan\n";
		}
		else
			cout << "Tai Khoan Khong Du De Thanh Toan\n";
	}
	else if (choose == 2)
	{
		double temp = 0;
		for (int i = 0; i < m_creditCard.size(); i++)
			temp += m_creditCard[i]->getBalance();
		double temp1;
		cout << "Nhap So Tien Muon Tra: ";
		cin >> temp1;
		while (temp1 < temp * 5 / 100)
		{
			cout << "Nhap Lai So Tien Muon Tra: ";
			cin >> temp1;
		}
		double pay = SoDu - temp1;
		if (pay >= 0)
		{
			if (transferTo(temp1))
			{
				cout << "Cam On Ban Da Thanh Toan\n";
				LichSuGiaoDich.push_back(PaymentHistory(SoTaiKhoan, temp, "Tra Tien The Tin Dung", date));
				for (int i = 0; i < m_creditCard.size(); i++)
					m_creditCard[i]->setBalance(0);
				SoNo = SoNo + temp - temp1;
			}
			else
				cout << "Tai Khoan Khong Du De Thanh Toan\n";
		}
		else
			cout << "Tai Khoan Khong Du De Thanh Toan\n";
	}
}

void PaymentAccount::addCreditCardAccount(CreditCardAccount* a)
{
	m_creditCard.push_back(a);
}

int PaymentAccount::lenght()
{
	return m_creditCard.size();
}

void PaymentAccount::showListCard()
{
	for (int i = 0; i < m_creditCard.size(); i++)
		cout << i + 1 << ". "<<	m_creditCard[i]->LaySoThe() << endl;
}

void PaymentAccount::thanhtoan(int choose, double amount, string date)
{
	m_creditCard[choose - 1]->thanhtoan(amount, date);
}