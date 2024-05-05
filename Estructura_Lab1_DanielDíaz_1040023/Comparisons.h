#pragma once
#include "Apartment.h"

class Comparisons : Apartment
{
public:
	Comparisons();
	Comparisons(std::vector <Apartment> NewApartments, std::vector <std::string> NewRequirements);
	int CheckR(int index, std::string req, std::vector <Apartment> Apartments);
	int CheckL(int index, std::string req, std::vector <Apartment> Apartments);
	void createClosenessScore();
	int getBestCase();

private:
	std::vector <Apartment> Apartments;
	std::vector <std::string> Requirements;

};

