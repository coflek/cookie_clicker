#include <string>
#include <vector>
#include "cookie_save.h"
#include "base64.h"
#include "tokenizer.h"

#include <iostream>

namespace Cookie
{
	CookieSave::CookieSave(void) { }

	bool CookieSave::Load(std::string save_game) {
		const std::string SAVE_END = "%21END%21";
		const std::string EQUALS = "%3D";
		char *decoded = new char[save_game.length() * 3 / 4 + 1];

		std::fill(decoded, decoded + save_game.length() * 3 / 4 + 1, 0);

		/* prepare save for decoding  - remove % 21END % 21 from the end, replace " % 3D" with = */
		uint32_t save_end_index = save_game.find(SAVE_END);
		save_game = save_game.replace(save_end_index, save_end_index + SAVE_END.length(), "");
		uint32_t equals_index = save_game.find(EQUALS);
		while (equals_index != std::string::npos) {
			save_game = save_game.replace(equals_index, equals_index + EQUALS.length(), "=");
			equals_index = save_game.find(EQUALS);
		}

		Base64::decode(save_game, decoded);

		std::vector<std::string> tokens = Tokenizer::split(decoded, '|');
		uint8_t block_index = 0;
		for (auto t : tokens) {
			switch (block_index) {
			case Blocks::VERSION:
				version_ = t;
				break;
			case Blocks::RESERVED:
				reserved_ = t;
				break;
			case Blocks::TIMESTAMPS:
			{
				std::vector<std::string> values = Tokenizer::split(t, ';');
				uint8_t ts_index = 0;
				for (auto val : values) {
					if (ts_index == 0) {
						session_start_timestamp_ = std::stoull(val, nullptr, 10);
					}
					else if (ts_index == 1) {
						legacy_start_timestamp_ = std::stoull(val, nullptr, 10);
					}
					else if (ts_index == 2) {
						savegame_timestamp_ = std::stoull(val, nullptr, 10);
					}
					else if (ts_index == 3) {
						bakery_name_ = val;
					}
					ts_index++;
				}
				break;
			}
			case Blocks::OPTIONS:
				// ignore, current description does not fit the read values
				options_ = Options::Options(t);
				break;
			case Blocks::STATS:
				break;
			case Blocks::BUILDINGS:
			{
				std::vector<std::string> values = Tokenizer::split(t, ';');
				uint8_t building_index = 0;
				for (auto val : values) {
					buildings_[building_index] = Building::Building((enum Constants::BuildingType)building_index, val);
					++building_index;
				}
				break;
			}
			case Blocks::UPGRADES:
				break;
			case Blocks::ACHIEVEMENTS:
				break;
			}
			++block_index;
		}

		delete[] decoded;

		return true;
	}
}

