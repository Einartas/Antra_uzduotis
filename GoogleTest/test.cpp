#include "pch.h"
#include "../Antra_uzduotis/Funkcijos.cpp"
#include "../Antra_uzduotis/Funkcijos.h"
#include "../Antra_uzduotis/Generavimas.cpp"
#include "../Antra_uzduotis/Generavimas.h"

TEST(Vardo_Setteris, CheckSetter)
{
	studentas name;
	name.set_vardas("vardenis");
	ASSERT_EQ(name.vardas(),"vardenis");
}

TEST(Priskyrimas, CheckAssignment)
{
	studentas name, name2;
	name.set_vardas("vardenis");
	name2 = name;
	ASSERT_EQ(name2.vardas(), "vardenis");
}

TEST(Kopijavimas, CheckCopy)
{
	studentas name;
	name.set_vardas("vardenis");
	studentas name2(name);
	ASSERT_EQ(name2.vardas(), "vardenis");
}