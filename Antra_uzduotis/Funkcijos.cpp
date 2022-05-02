#include "Funkcijos.h"

bool compare_vardas(const studentas& a, const studentas& b)
{
	if (a.vardas == b.vardas) return a.pavarde < b.pavarde;
	return a.vardas < b.vardas;
}

bool compare_mark(const studentas& a, const studentas& b)
{
	if (a.galutinis == b.galutinis) return a.galutinis < b.galutinis;
	return a.galutinis < b.galutinis;
}

void output(studentas& temp, int y)
{
	if (y == 0) cout << std::left << std::setw(10) << "Vardas" << std::left << std::setw(10) << "Pavarde" << std::left << std::setw(20) << "Galutinis vid" << std::left << std::setw(10) << "Galutinis med" << std::endl;
	cout << std::left << std::setw(10) << temp.vardas << std::left << std::setw(20) << temp.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp.galutinis << std::left << std::setw(10) << std::fixed << std::setprecision(2) << temp.mediana << std::endl;
}

bool file(std::string failas, std::vector<std::string>& data)
{
	std::ifstream in(failas.c_str());

	if (!in)
	{
		std::cout << "Tokio failo nera!" << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(in, line))
	{
		data.push_back(line);
	}

	in.close();
	return true;
}

void input(studentas& temp)
{
	cout << "Iveskite varda: ";
	cin >> temp.vardas;
	cout << "Iveskite pavarde: ";
	cin >> temp.pavarde;
	int a = 1, x = 0;
	std::vector<int>m{ 0 };

	cout << "Kiek pazymiu turi studentas: ";
	cin >> x;

	if (x < 1 || x > 100)
	{
		while (!(cin >> x) || x < 0)
		{
			cout << "Netinkamas simbolis arba kiekis! Iveskite skaiciu daugiau uz 0: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
	}

	int t = 2;

	while (t != 0 && t != 1)
	{
		cout << "Ivesti rankiniu budu - 1, sugeneruoti atsitiktinai - 0: ";
		cin >> t;
	}

	if (t == 1)
	{
		for (int i = 0; i < x; i++)
		{
			cout << "Iveskite pazymi: ";
			cin >> a;
			if (a < 1 || a>10)
			{
				while (!(cin >> a))
				{
					cout << "Netinkamas simbolis arba kiekis! Iveskite skaiciu tarp 1 ir 10: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
			if (a > 0 && a < 11)
			{
				m.push_back(1);
				temp.pazymiai += a;
				m[i] = a;
			}
			else i--;
		}

		cout << "Ar ivesite dar pazymiu? Taip - iveskite pazymi, ne - iveskite 0: ";
		cin >> a;
		if (a > 0 && a < 11) m[x] = a;
		while (a != 0)
		{
			temp.pazymiai += a;
			m.push_back(1);
			x++;
			cout << "Ar ivesite dar pazymiu? Taip - iveskite pazymi, ne - iveskite 0: ";
			cin >> a;
			m[x] = a;
		}

		cout << "Iveskite egzamino bala: ";
		cin >> temp.egzaminas;

		if (temp.egzaminas < 1 || temp.egzaminas > 10)
		{
			while (!(cin >> temp.egzaminas) || temp.egzaminas < 1 || temp.egzaminas > 10)
			{
				cout << "Netinkamas balas! Iveskite tarp 1 ir 10: " << std::endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
		}

		temp.galutinis = (temp.pazymiai / x) * 0.4 + temp.egzaminas * 0.6;
		m[x] = temp.egzaminas;
	}

	else
	{
		cout << "Generuojama atsitiktinai intervale (0, 10)" << std::endl;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(1, 10);

		for (int i = 0; i < x; i++)
		{
			a = distr(gen);
			m.push_back(1);
			temp.pazymiai += a;
			m[i] = a;
		}

		temp.egzaminas = distr(gen);
		temp.galutinis = (temp.pazymiai / x) * 0.4 + temp.egzaminas * 0.6;
		m[x] = temp.egzaminas;
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = i + 1; j < x; j++)
		{
			if (m[i] > m[j])
			{
				a = m[i];
				m[i] = m[j];
				m[j] = a;
			}
		}
	}
	if (x % 2)
	{
		temp.mediana = (m[x / 2] + m[(x / 2 + 1)]) / 2;
	}
	else
	{
		temp.mediana = m[x / 2];
	}
}
