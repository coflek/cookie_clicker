#include <stdint.h>
#include <cmath>
#include <string>
#include <vector>

#include "game_constants.h"
#include "building.h"
#include "tokenizer.h"

namespace Building
{
	Building::Building() {}

	Building::Building(enum Constants::BuildingType type, std::string& data) : 
		type_(type) {
		std::vector<std::string> values = Tokenizer::split(data, '|');
		uint8_t index = 0;
		for (auto val : values) {
			switch (index) {
			case 0:
				owned_ = std::stoul(val, nullptr, 10);
				break;
			case 1:
				bought_ = std::stoul(val, nullptr, 10);
				break;
			case 2:
				cookies_produced_ = std::stoull(val, nullptr, 10);
				break;
			case 3:
				unused_ = std::stoul(val, nullptr, 10);
				break;
			}
			++index;
		}
	}

	double Building::CalculateCost(void) const {
		return CalculateCost(1);
	}

	double Building::CalculateCost(uint32_t wanted) const {
		if (wanted <= owned_) return 0;
		return Constants::BASE_BUILDING_COST[type_] * (pow(1.15, wanted) - pow(1.15, owned_)) / 0.15;
	}

	double Building::CalculateCps(void) const {
		return Constants::BASE_BUILDING_CPS[type_];
	}
}