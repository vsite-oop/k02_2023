#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

struct Student
{
public:
	std::string ime;
	std::string prezime;
	std::array<int, 4> bodovi;
	int ukupniBodovi;

	friend std::ostream& operator<<(std::ostream& os, const Student& student)
	{
		os << student.ime[0] << ". " << student.prezime << student.ukupniBodovi << ocjena(brojBodova(student)) << std::endl;
	}
};

int brojBodova(const Student& st)
{
	int bodovi = 0;
	for (int i = 0; i < 4; i++)
	{
		if (st.bodovi[i] < 0) return -1;
		bodovi += st.bodovi[i];
	}
	return bodovi;
}

int ocjena(int bb)
{
	if (bb >= 43) return 5;
	if (bb >= 35) return 4;
	if (bb >= 27) return 3;
	if (bb >= 20) return 2;
	return 1;
}

struct comp
{
	bool operator() (const Student& s1, const Student& s2)
	{
		return s1.bodovi < s2.bodovi;
	}
};



int main()
{
	std::string imeDatoteke;
	std::cout << "Upisite ime datoteke: ";
	std::cin >> imeDatoteke;

	std::ifstream ulaznaDatoteka(imeDatoteke);
	std::vector<Student> studenti;
	std::string ucitaniPodatak;
	while (std::getline(ulaznaDatoteka, ucitaniPodatak))
	{
		std::istringstream iss(ucitaniPodatak);
		Student st;
		iss >> st.ime >> st.prezime >> st.bodovi[0] >> st.bodovi[1] >> st.bodovi[2] >> st.bodovi[3];
		st.ukupniBodovi = brojBodova(st);
		if (st.ukupniBodovi >= 0) studenti.push_back(st);
	}
	std::sort(studenti.begin(), studenti.end(), comp());



	ulaznaDatoteka.close();
}
