#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <cmath>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

struct studentas
{
	string vardas, pavarde;
	std::vector<int> mark;
	int pazymiai = 0, egzaminas = 0, vidurkis = 0;
	double galutinis = 0, mediana = 0;
};

void input(studentas& temp);

bool file(std::string failas, std::vector<std::string>& data);

void output(studentas& temp, int y);

bool compare_vardas(const studentas& a, const studentas& b);

bool compare_mark(const studentas& a, const studentas& b);
