#include "XeThuongMai.h"
#include "MauXe.h"
#include "NhaMayOto.h"

int main()
{
	NhaMayOto a;
	cin >> a;
	cout << a;
	XeThuongMai b("Fadil", "Den", "Tieu Chuan", 950000000.00, "55A5-99999");
	XeThuongMai c("Fadil", "Den", "Cao Cap", 10000000000.00, "55A5-11111");
	XeThuongMai d("LuxA", "Den", "Cao Cap", 10000000000.00, "55A5-22222");
	cout << "Xe Truoc Khi Bang:\n";
	cout << b << endl << c << endl << d << endl;
	b = c;
	d = c;
	cout << "Xe Sau Khi Bang:\n";
	cout << b << endl << c << endl << d << endl;
	XeThuongMai xeA("LuxA", "Den", "TieuChuan", 950000000.00, "55A5-55555");
	cout << "Mua XeA\n";
	xeA.CapNhatBienSoXe("22A2-55555");
	xeA = xeA - 5.5;
	cout << xeA << endl;

}