#include <iostream>
#include <string>
#include "IzuzetakFile.h"

using namespace std;

void izmeni(string str1) {
	size_t pos = string::npos;
	string toReplace = "JABUKA";
	string toReplace2 = "jabuka";
	int naso = 0;
	try {
		while ((pos = str1.find(toReplace)) != string::npos)
		{
			str1.replace(pos, toReplace.length(), "KRUSKA");
			naso = 1;
		}

		while ((pos = str1.find(toReplace2)) != string::npos)
		{
			str1.replace(pos, toReplace2.length(), "kruska");
			naso = 1;
		}
		if (naso == 0) {
				throw IzuzetakFile("StringNemaTekst");
		}
		cout << str1 << endl;
		//Prva 4 i poslednjih 6 karaktera: 
		string prva4 = str1.substr(0, 4);
		cout << "Prva cetiri karaktera novog stringa: " << prva4 << endl;

		string poslednjih6 = str1.substr(str1.length() - 6, 6);
		cout << "Poslednjih sest karaktera novog stringa: " << poslednjih6 << endl << endl;
	}
	catch (IzuzetakFile & e)
	{
		cerr << "String ne sadrzi reci koje treba da sadrzi. " << e.GetError() << endl;
	}

	
	
}

int main() {
	//Treci zadatak
	izmeni("JABUKA 123 jabuka nekarecduzaodsest");
	izmeni("JABUKA 12adasd3 jabuka MarioFerketic3599");
	izmeni("Ovde nema reci koje se traze");
	return 0;
}