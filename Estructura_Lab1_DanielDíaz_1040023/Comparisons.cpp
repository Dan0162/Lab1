#include "pch.h"
#include "Comparisons.h"

Comparisons::Comparisons()
{

}

Comparisons::Comparisons(std::vector <Apartment> NewApartments, std::vector <std::string> NewRequirements)
{
	Apartments = NewApartments;
	Requirements = NewRequirements;
}

int Comparisons::CheckR(int index, std::string req, std::vector <Apartment> Apartments)
{

	int stepsTaken = 0;
	Apartment::Business currBusiness;

	for (int i = index; i < Apartments.size(); i++)
	{
		for (int j = 0; j < Apartments[i].getBusinessesSize(); j++)
		{
			currBusiness = Apartments[i].getBusiness(j);

			if (currBusiness.name == req && currBusiness.isAvailable == true)
			{
				return stepsTaken;
			}
		}
		stepsTaken++;
	}

	return -1;
}
int Comparisons::CheckL(int index, std::string req, std::vector <Apartment> Apartments)
{
	
	int stepsTaken = 0;
	Apartment::Business currBusiness;

	for (int i = index; i > -1; i--)
	{
		for (int j = 0; j < Apartments[i].getBusinessesSize(); j++)
		{
			currBusiness = Apartments[i].getBusiness(j);

			if (currBusiness.name == req && currBusiness.isAvailable == true)
			{
				return stepsTaken;
			}
		}
		stepsTaken++;
	}
	return -1;
}

void Comparisons::createClosenessScore()
{
	int ClosenessScore;
	int CheckedR, CheckedL;
	
	for (int i = 0; i < Apartments.size(); i++)
	{
		ClosenessScore = 0;

		for (int j = 0; j < Requirements.size(); j++)
		{		
			
			CheckedR = CheckR(i, Requirements[j], Apartments);
			CheckedL = CheckL(i, Requirements[j], Apartments);

			if ((CheckedL == -1) && (CheckedR == -1))
			{
				ClosenessScore = -1;
				j = Requirements.size();
			}
			else if (CheckedL == -1)
			{
				ClosenessScore += CheckedR;
			}
			else if (CheckedR == -1)
			{
				ClosenessScore += CheckedL;
			}
			else if (CheckedL < CheckedR)
			{
				ClosenessScore += CheckedL;
			}
			else if (CheckedL > CheckedR)
			{
				ClosenessScore += CheckedR;
			}
			else if (CheckedL == CheckedR)
			{
				ClosenessScore += CheckedR;
			}

			Apartments[i].setClosenessScore(ClosenessScore);
		}	
	}
}

int Comparisons::getBestCase()
{
	std::vector<Apartment> bestcases;
	std::vector<int> bestcasesIndex;
	int min = INT_MAX;

	for (int i = 0; i < Apartments.size(); i++)
	{
		if (Apartments[i].getClosenessScore() < min)
		{
			min = Apartments[i].getClosenessScore();
		}
	}

	if (min != -1)
	{
		for (int i = 0; i < Apartments.size(); i++)
		{
			if (Apartments[i].getClosenessScore() == min)
			{
				bestcases.push_back(Apartments[i]);
				bestcasesIndex.push_back(i);
			}
		}
	}
	else
	{
		return -1;
	}

	if (bestcases.size() > 1)
	{
		std::vector <int> highestMovement;
		int highestMovIndividual = 0;

		for (int i = 0; i < bestcasesIndex.size(); i++)
		{
			highestMovIndividual = 0;
			for (int j = 0; j < Requirements.size(); j++)
			{

				int CheckedR = CheckR(bestcasesIndex[i], Requirements[j], Apartments);
				int CheckedL = CheckL(bestcasesIndex[i], Requirements[j], Apartments);

				if (CheckedR == -1)
				{
					if (CheckedL > highestMovIndividual)
					{
						highestMovIndividual = CheckedL;
					}
				}
				else if (CheckedL == -1)
				{
					if (CheckedR > highestMovIndividual)
					{
						highestMovIndividual = CheckedR;
					}
				}
				else
				{
					if (CheckedR < CheckedL)
					{
						if (CheckedR > highestMovIndividual)
						{
							highestMovIndividual = CheckedR;
						}
					}
					else
					{
						if (CheckedL > highestMovIndividual)
						{
							highestMovIndividual = CheckedL;
						}
					}
				}
				
			}
			highestMovement.push_back(highestMovIndividual);

		}

		int lowestMovement = INT_MAX;

		for (int i = 0; i < highestMovement.size(); i++)
		{
			if (highestMovement[i] < lowestMovement)
			{
				lowestMovement = highestMovement[i];
			}
		}

		for (int i = 0; i < highestMovement.size(); i++)
		{
			if (highestMovement[i] == lowestMovement)
			{
				return bestcasesIndex[i];
			}
		}


	}
	else
	{
		return bestcasesIndex[0];
	}

	


}



