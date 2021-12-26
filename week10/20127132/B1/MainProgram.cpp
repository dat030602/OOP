#include "CashBackCardAccount.h"
#include "CreditCardAccount.h"
#include "PaymentAccount.h"
#include "PaymentHistory.h"
#include "RewardCardAccount.h"

PaymentAccount account;
int NamNhuan(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int SoNgayTrongThang(int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 2)
	{
		if (NamNhuan(year))
			return 29;
		return 28;
	}
	return 30;
}
void NgayTiepTheo(int& day, int& month, int& year)
{
	if (month != 12 && day == SoNgayTrongThang(month, year))
	{
		day = 0;
		month++;
	}
	else if (month == 12 && day == SoNgayTrongThang(month, year))
	{
		day = 0;
		month = 1;
		year++;
	}
	else if (month == 2)
	{
		if (day == 28)
		{
			day = 0;
			month++;
		}
		else if (NamNhuan(year))
		{
			if (day == 29)
			{
				day = 0;
				month++;
			}
		}
	}
	day++;
}
void run()
{
	int count1 = 0, count2 = 0;
	int choose;
	//Lấy ngày phát hành làm bắt đầu
	string temp = account.GetNgayPhatHanh();
	int day = account.getNumber(temp[0]) * 10 + account.getNumber(temp[1]);
	int month = account.getNumber(temp[3]) * 10 + account.getNumber(temp[4]);
	int year = account.getNumber(temp[6]) * 1000 + account.getNumber(temp[7]) * 100 +
		account.getNumber(temp[8]) * 10 + account.getNumber(temp[9]);
	while (1)
	{
		if (account.lenght() > 0)
		{
			if (count1 == 30 || count2 == 15)
			{
				//trả nợ
				cout << "Ngay Den Han: ";
				cout << day << "/" << month << "/" << year << endl;
				cout << "Ban Co Muon Thanh Toan So Tien The Tin Dung Khong(1: Co, 2: Khong): ";
				cin >> choose;
				while (choose != 1 && choose != 2)
				{
					cout << "Nhap Lai: ";
					cin >> choose;
				}
				if (choose == 1)
				{
					cout << "Ban Muon Thanh Toan Toan Bo Hay Toi Thieu (1: Toan Bo, 2: Toi Thieu): ";
					cin >> choose;
					while (choose != 1 && choose != 2)
					{
						cout << "Nhap Lai: ";
						cin >> choose;
					}
					account.payment(choose, to_string(day) + "/" + to_string(month) + "/" + to_string(year));
					count1 = count2 = -1;
				}
			}
			if (day == 15)
			{
				//sao kê
				cout << "Ngay Sao Ke: ";
				cout << day << "/" << month << "/" << year << endl;
				account.showHistory();
			}
		}
		NgayTiepTheo(day, month, year);
		if (count2 != 0)
			count2++;
		if (count1 == 30)
		{
			//mỗi 30 ngày hỏi có muốn tạo thêm tài khoản không
			count1 = -1;
			count2++;
			cout << "Ban Co Muon Them The Tin Dung (1: Co, 2: Khong): ";
			cin >> choose;
			while (choose != 1 && choose != 2)
			{
				cout << "Nhap Lai: ";
				cin >> choose;
			}
			if (choose == 1)
			{
				cout << "1. The Tich Diem\n";
				cout << "2. The Hoan Tien\n";
				cout << "Chon: ";
				cin >> choose;
				CreditCardAccount* acc;
				if (choose == 1)
					acc = new RewardCardAccount();
				else
					acc = new CashBackCardAccount();
				acc->TaoTaiKhoan();
				account.addCreditCardAccount(acc);
			}
		}
		if (count1 % 4 == 0)
		{
			//mỗi 4 ngày thì sử dụng thẻ 1 lần
			if (account.lenght() > 0 && account.lenght() <= 6)
			{
				cout << "Ban Co Muon Su Dung Tin Dung (1: Co, 2: Khong): ";
				cin >> choose;
				while (choose != 1 && choose != 2)
				{
					cout << "Nhap Lai: ";
					cin >> choose;
				}
				if (choose == 1)
				{
					double amount;
					account.showListCard();
					cout << "Chon Su Dung The So: ";
					cin >> choose;
					cout << "So Tien: ";
					cin >> amount;
					account.thanhtoan(choose, amount, to_string(day) + "/" + to_string(month) + "/" + to_string(year));
					account.showHistory();
				}
			}
		}
		count1++;
	}
}
int main()
{
	int choose = 1;
	while (1)
	{
		cout << "Tao Tai Khoan Thanh Toan\n";
		cin >> account;
		run();
		return 0;
	}
}