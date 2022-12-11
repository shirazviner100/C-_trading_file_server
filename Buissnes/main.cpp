#include "menu.h"


int main()
{
	KS * myBusiness= new KS;

	/*
	Address add("Israel", "Tel Aviv", "Ben Gurion", "56477", 12, 1);

	Client * ophir = new Client("ophir1", "ophir Viner", add, "1234");
	*myBusiness += *(ophir);
	delete ophir;

	Client * shiraz = new Client("shiraz100", "Shiraz Viner", add, "1234");
	*myBusiness += *(shiraz);
	delete shiraz;

	Seller * kim = new Seller("Kim", "kim111", "1234", add);
	*myBusiness += *(kim);
	delete kim;

	Seller * moti = new Seller("Moti", "moti123", "1234", add);
	*myBusiness += *(moti);
	delete moti;

	ClientSeller * barbi = new ClientSeller("barbi", "barbi the queen", add, "1234");
	*myBusiness += *(barbi);
	delete barbi;
	*/

	Menu myMenu(myBusiness);
	myMenu.mainMenu();

	system("pause");
}


