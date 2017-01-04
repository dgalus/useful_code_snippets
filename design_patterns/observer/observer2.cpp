#include <iostream>
#include <string>
#include <list>
#include <unistd.h>

#define ZMNIEJSZANIE_CISNIENIA_1 6
#define ZMNIEJSZANIE_CISNIENIA_2 6

class Pacjent; // klasa obserwowana

class Miernik
{
public:
	virtual void update(Pacjent *) = 0;
};

class Pacjent
{
private:
	std::list<Miernik *> mierniki;
public:
	virtual ~Pacjent(){}
	virtual void attach(Miernik* m)
	{
		mierniki.push_back(m);
	}
	virtual void detach(Miernik* m)
	{
		mierniki.remove(m);
	}
	virtual void notify()
	{
		for(std::list<Miernik *>::iterator it = mierniki.begin(); it != mierniki.end(); it++)
		{
			(*it)->update(this);
		}
	}
};

// obserwator
class PacjentObserwowany : public Pacjent
{
private:
	int cisnienie1;
	int cisnienie2;
public:
	PacjentObserwowany() {
		cisnienie1 = 60;
		cisnienie2 = 30;
	}
	void ustaw()
	{
		cisnienie1 += ZMNIEJSZANIE_CISNIENIA_1;
		cisnienie2 += ZMNIEJSZANIE_CISNIENIA_2;
	}
	void ustaw(int a, int b)
	{
		if(a == 0)
		{
			cisnienie1 = b;
		}
		else
		{
			cisnienie2 = b;
		}
	}
	int getcisnienie1()
	{
		return cisnienie1;
	}
	int getcisnienie2()
	{
		return cisnienie2;
	}
};

class Cisnieniomierz1 : public Miernik
{
public:
	void update(Pacjent* p)
	{
		PacjentObserwowany *m = dynamic_cast<PacjentObserwowany *>(p);
		if(m)
		{
			std::cout << "Cisnienie skurczowe = " << m->getcisnienie1() << std::endl;
			if(m->getcisnienie1() > 90)
			{
				std::cout << "Cisnienie zbyt wysokie. Odpoczywam." << std::endl;
				m->ustaw(0, 60);
				sleep(2);
				this->update(p);
			}
		}
	}
};

class Cisnieniomierz2 : public Miernik
{
public:
	void update(Pacjent* p)
	{
		PacjentObserwowany *m = dynamic_cast<PacjentObserwowany *>(p);
		if(m)
		{
			std::cout << "Cisnienie rozkurczowe = " << m->getcisnienie2() << std::endl;
			if(m->getcisnienie2() > 60)
			{
				std::cout << "Cisnienie rozkurczowe zbyt wysokie. Odpoczywam." << std::endl;
				m->ustaw(1, 30);
				sleep(2);
				this->update(p);
			}
		}
	}
};

void menu()
{
	std::cout << "1) Menu" << std::endl;
	std::cout << "2) Biegnij" << std::endl;
	std::cout << "3) Stop" << std::endl;
}

int main()
{
	PacjentObserwowany* pacjent = new PacjentObserwowany();
	Miernik* cis1 = new Cisnieniomierz1();
	Miernik* cis2 = new Cisnieniomierz2();
	pacjent->attach(cis1);
	pacjent->attach(cis2);
	menu();
	int men = 0;
	while(men != 3)
	{
		std::cin >> men;
		switch(men)
		{
		case 1:
			menu();
			break;
		case 2:
			pacjent->ustaw();
			pacjent->notify();
			break;
		case 3:
			std::cout << "Koniec." << std::endl;
		}
	}
	delete cis1;
	delete cis2;
	delete pacjent;
}
