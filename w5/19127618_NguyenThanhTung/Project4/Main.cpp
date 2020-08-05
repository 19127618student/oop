#include "Header.h"

int QLTM::kk = 0;
int ThuMuc::k = 0;
int main()
{

	QLTM C("C:");
	ThuMuc bt("Bai tap:");
	ThuMuc lt("Ly thuyet:");
	ThuMuc btc("Bai tap C:");

	btc.addFile(new TapTin("Bt2.cpp", 1.280));
	bt.addFolder(new ThuMuc(btc));
	bt.addFile(new TapTin("BT1.doc", 123.456));
	bt.addFile(new TapTin("Bt2.xls", 23.456));
	lt.addFile(new TapTin("ch1.ppt", 34567));
	C.addTM(new ThuMuc(bt));
	C.addTM(new ThuMuc(lt));

	cout << endl;
	menu(C, bt, lt, btc);
	return 0;
}

