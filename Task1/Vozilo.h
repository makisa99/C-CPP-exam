#include <iostream>

using namespace std;

class Vozilo
{
public:
	Vozilo();
	Vozilo(int brMotora, int brSasije);
	~Vozilo();
	int getBrMotora() const;
	void setBrMotora(int brMotora);
	int getBrSasije() const;
	void setBrSasije(int brSasije);

	virtual void info() = 0;
protected:
	int brMotora;
	int brSasije;
};

class Automobil : public Vozilo
{
public:
	Automobil();
	Automobil(int brMotora, int brSasije, int brMesta);
	int getBrMesta() const;
	void setBrMesta(int brMesta);
	~Automobil();
	void info() override;
private:
	int brMesta;
};

class Kamion : public Vozilo
{
public:
	Kamion();
	Kamion(int brMotora, int brSasije, int maxTeret);
	int getMaxTeret() const;
	void setMaxTeret(int maxTeret);
	~Kamion();
	void info() override;
private:
	int maxTeret;
};