#include "Funkcijos.h"
#include "Generavimas.h"

int main()
{
	int wh = 3;
		std::cout << "Rasyti duomenis ranka (0), skaityti is failo (1), laiko matavimas (2) : " << std::endl;
		std::cin >> wh;

	if (wh == 0)
	{
		int n = 0;
		cout << "Iveskite kiek studentu: ";
		cin >> n;

		if (n < 1 || n > 100)
		{
			//cout << "Netinkamas simbolis arba kiekis! Iveskite skaiciu daugiau uz 0: ";
			{
				while (!(cin >> n) || n < 1 || n > 100)
				{
					cout << "Netinkamas simbolis arba kiekis! Iveskite skaiciu daugiau uz 0: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
		}

		studentas s;
		studentas* dm = new studentas[n];
		for (int i = 0; i < n; i++)
		{
			input(dm[i]);
		}

		cout << "------------------------------------------------------" << std::endl;

		for (int i = 0; i < n; i++)
		{
			output(dm[i], i);
		}

		cout << "------------------------------------------------------" << std::endl;

		delete[] dm;
	}

	if (wh == 1)
	{
		std::vector<std::string> data;
		int eilutes = 0;

		std::ofstream O ("kursiokaiRESULT.txt");

		bool result = file("kursiokai.txt", data);
		data.erase(data.begin());

		if (result)
		{
			for (std::string& line : data)
			{
				eilutes++;
			}
		}

		int space = 0;
		for (auto el : data)
		{
			for (int i = 0; i < el.length(); i++)
			{
				if (i != el.length() - 1)
				{
					if ((el.at(i) == ' ') && (el.at(i + 1) != ' ')) space++;
				}
			}
			break;
		}

		std::stringstream S;
		string vardas, pavarde, tmp;
		int pazymiai = 0, p = 0, a = 1;
		std::vector<studentas> list;
		studentas stud;

		for (auto& line : data)
		{
				S.clear();
				S << line;
				S >> stud.vardas >> stud.pavarde;
				for (int i = 0; i < (space - 2); i++)
				{
					S >> p;
					pazymiai += p;
					stud.mark.push_back(p);
				}
				S >> stud.egzaminas;
				stud.galutinis = 0.4 * (pazymiai / (space - 2)) + 0.6 * stud.egzaminas;
				sort(stud.mark.begin(), stud.mark.end());
				if ((space-2) % 2)
				{
					stud.mediana = (stud.mark[(space-2) / 2] + stud.mark[((space-2) / 2 + 1)]) / 2;
				}
				else
				{
					stud.mediana = stud.mark[(space-2) / 2];
				}
				pazymiai = 0;
				stud.mark.clear();
				list.push_back(stud);
		}

		data.clear();
		sort(list.begin(), list.end(), compare_vardas);


		O << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis vid" << std::left << std::setw(20) << "Galutinis med" << std::endl << std::endl;

		for (auto el : list)
		{
			O << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.galutinis << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.mediana << std::endl;

		}

		O.close();
	}

	if (wh == 2)
	{

		std::stringstream S;
		std::string name, sur;
		int n=0, np=0, fl=0;
		studentas stud;
		std::vector<studentas> list;
		std::vector<studentas> geri;
		std::vector<studentas> blogi;
		auto start = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();
		clock_t tStart = 0;

		cout << "Kurti faila (0), skaityti is esamo failo (1): " << std::endl;
		cin >> fl;

		if (fl == 0)
		{
			cout << "Kiek bus studentu? : " << std::endl;
			cin >> n;
			cout << "Kiek studentas turi pazymiu? : " << std::endl;
			cin >> np;

			clock_t tStart = clock();

			mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
			int_distribution dist(1, 10);

			std::ofstream O("..\\..\\Generavimas.txt");

			start = std::chrono::steady_clock::now();

			for (int i = 0; i < n; i++)
			{
				generate_name(name, sur);
				S << name << " " << sur;

				for (int j = 0; j < np; j++)
				{
					S << " " << dist(mt);
				}

				S << std::endl;
				O << S.str();
				S.str("");
			}
			O.close();

			end = std::chrono::steady_clock::now();
			cout << "Generavimas su " << n << " studentu ir " << np << " pazymiu uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;
		}

		std::vector<std::string> data;
		bool result = file("..\\..\\Generavimas.txt", data);

		if (fl == 1)
		{
			clock_t tStart = clock();
			if (result)
			{
				for (std::string& line : data)
				{
					n++;
				}
			}
			int space = 0;
			for (auto el : data)
			{
				for (int i = 0; i < el.length(); i++)
				{
					if (i != el.length() - 1)
					{
						if ((el.at(i) == ' ') && (el.at(i + 1) != ' ')) space++;
					}
				}
				break;
			}
			np = space - 1;
		}

		int p=0, pazymiai=0;
		std::ofstream G("..\\..\\Gerieciai_vector.txt");
		std::ofstream B("..\\..\\Blogieciai_vector.txt");

		B << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis vid" << std::left << std::setw(20) << "Galutinis med" << std::endl << std::endl;
		G << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis vid" << std::left << std::setw(20) << "Galutinis med" << std::endl << std::endl;

		start = std::chrono::steady_clock::now();

		for (auto& line : data)
		{
			S.str("");
			S << line;
			S >> stud.vardas >> stud.pavarde;
			for (int i = 0; i < (np - 3); i++)
			{
				S >> p;
				pazymiai += p;
				stud.mark.push_back(p);
			}
			S >> stud.egzaminas;
			stud.galutinis = 0.4 * (pazymiai / (np - 3)) + 0.6 * stud.egzaminas;
			sort(stud.mark.begin(), stud.mark.end());
			sort(stud.mark.begin(), stud.mark.end());
			if ((np - 3) % 2)
			{
				stud.mediana = (stud.mark[(np - 3) / 2] + stud.mark[((np - 3) / 2 + 1)]) / 2;
			}
			else
			{
				stud.mediana = stud.mark[(np - 3) / 2];
			}
			pazymiai = 0;
			stud.mark.clear();
			list.push_back(stud);
		}

		end = std::chrono::steady_clock::now();
		cout << "Failo su "<< n <<" studentu nuskaitymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		start = std::chrono::steady_clock::now();
		sort(list.begin(), list.end(), compare_mark);
		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu rusiavimas sort funkcija uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		start = std::chrono::steady_clock::now();
		for (auto el = list.end(); el != list.begin(); el--)
		{
			if (el->galutinis >= 5)
			{
				geri.push_back(*el);
				list.pop_back();
			}
		}
		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu rusiavimas i dvi kategorijas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		data.clear();

		start = std::chrono::steady_clock::now();

		for (auto el : geri)
		{
			G << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.galutinis << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.mediana << std::endl;
		}
		for (auto el : list)
		{
			B << std::left << std::setw(20) << el.vardas << std::left << std::setw(20) << el.pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.galutinis << std::left << std::setw(20) << std::fixed << std::setprecision(2) << el.mediana << std::endl;
		}

		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu isvedimas i naujus failus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		B.close();
		G.close();

		printf("Visos programos darbo laikas: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	}

	system("pause");
}