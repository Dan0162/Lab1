#include "pch.h"
#include "Apartment.h"


Apartment::Apartment()
{

}

void Apartment::pushBusiness(Apartment::Business movableBusiness)
{	
	Businesses.push_back(movableBusiness);
}

bool Apartment::isEmpty()
{
	return Businesses.empty();
}

Apartment::Business Apartment::setApartment(std::string name, bool isAvailable)
{
	Business currBusiness;	
	
	currBusiness.name = name;
	currBusiness.isAvailable = isAvailable;

	return currBusiness;
}

int Apartment::getBusinessesSize()
{
	return Businesses.size();
}

Apartment::Business Apartment::getBusiness(int index)
{
	return Businesses[index];
}

void Apartment::setClosenessScore(int newClosenessScore)
{
	ClosenessScore = newClosenessScore;
}

int Apartment::getClosenessScore()
{
	return ClosenessScore;
}
