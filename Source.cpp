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
	for (int i = 0; i < art.GetSize(); i++)
	{
		cout << art[i] << endl;
	}
	return 0;
}