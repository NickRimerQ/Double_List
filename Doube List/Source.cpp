#include "Header.h"
#include "Double_List.cpp"


int main()
{
	Double_List<int> art;
	for (int i = 0; i < 5; i++)
	{
		art.push_back(i);
	}
	art.push_front(33);
	art.pop_back();
	art.insert(22, 3);
	for (int i = 0; i < art.GetSize(); i++)
	{
		cout << art[i] << endl;
	}
	cout << "-------------" << endl;
	cout << art.isEmpty() << endl;
	return 0;
	
}