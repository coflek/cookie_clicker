#ifndef _GAME_CONSTANTS_H_
#define _GAME_CONSTANTS_H_

#include <stdint.h>
#include <string>

namespace Constants
{
	enum BuildingType : int {
		Cursor = 0,
		Grandma,
		Farm,
		Mine,
		Factory,
		Bank,
		Temple,
		WizardTower,
		Shipment,
		AlchemyLab,
		Portal,
		TimeMachine,
		AntimatterCondenser,
		Prism,
		BUILDING_COUNT
	};

	static std::string BuildingNames[] = {
		"Cursor",
		"Grandma",
		"Farm",
		"Mine",
		"Factory",
		"Bank",
		"Temple",
		"Wizard Tower",
		"Shipment",
		"Alchemy Lab",
		"Portal",
		"Time Machine",
		"Antimatter Condenser",
		"Prism"
	};

	static uint64_t BASE_BUILDING_COST[] = {
		15,
		100,
		1100,
		12000,
		130000,
		1400000,
		20000000,
		330000000,
		5100000000,
		75000000000,
		1000000000000,
		14000000000000,
		170000000000000,
		2100000000000000
	};

	static double BASE_BUILDING_CPS[] = {
		0.1,
		1,
		8,
		47,
		260,
		1400,
		7800,
		44000,
		260000,
		1600000,
		10000000,
		65000000,
		430000000,
		2900000000
	};
}

#endif /* _GAME_CONSTANTS_H_ */