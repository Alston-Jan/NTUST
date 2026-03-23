#include "HotDogStand.h"
#include <iostream>

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	standId = NULL;
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id)
{
	standId = id;
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount) 
{
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand() 
{
	totalSellAmount = 0;
}

void HotDogStand::justSold() 
{
	hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	std::cout << standId << " " << hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount() 
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() 
{
	return totalSellAmount;
}