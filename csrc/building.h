#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <stdint.h>
#include "game_constants.h"

namespace Building
{
	class Building
	{
	private:
		enum Constants::BuildingType type_;
		uint32_t owned_;
		uint32_t bought_;
		uint64_t cookies_produced_;
		uint32_t unused_;

	public:
		Building();
		Building(enum Constants::BuildingType type, std::string& data);
		Building(enum Constants::BuildingType type, uint32_t owned, uint32_t bought, uint64_t cookies_produced, uint32_t unused);
		
		double CalculateCost(void) const;
		double CalculateCost(uint32_t wanted) const;

		double CalculateCps(void) const;
	};
}

#endif /* _BUILDING_H_ */