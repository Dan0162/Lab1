#pragma once
#include <iostream>
#include <vector>

class Apartment
{
public:
	struct Business
	{
		std::string name;
		bool isAvailable;
	};

public:
	Apartment();
	Business setApartment(std::string name, bool isAvailable);
	bool isEmpty();
	void pushBusiness(Business movableBusiness);
	int getBusinessesSize();
	Business getBusiness(int index);
	void setClosenessScore(int newClosenessScore);
	int getClosenessScore();

	

private:	
	std::vector <Business> Businesses;
	int ClosenessScore = 0;
};

