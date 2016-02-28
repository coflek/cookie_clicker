#ifndef _COOKIE_SAVE_H_
#define _COOKIE_SAVE_H_

#include <string>
#include <stdint.h>

#include "options.h"
#include "building.h"

namespace Cookie
{
	enum Blocks :uint8_t {
		VERSION = 0,
		RESERVED,
		TIMESTAMPS,
		OPTIONS,
		STATS,
		BUILDINGS,
		UPGRADES,
		ACHIEVEMENTS
	};

	enum GrandMatriarchStatus : uint8_t
	{
		Appeased = 0,
		Awoken = 1,
		Displeased = 2,
		Angered = 3
	};

	class CookieSave
	{
	private:
		std::string version_;

		std::string reserved_;

		uint64_t session_start_timestamp_;
		uint64_t legacy_start_timestamp_;
		uint64_t savegame_timestamp_;
		std::string bakery_name_;

		Options::Options options_;
		//uint8_t option_flags; /* particles, numbers, autosave, offline mode (0 offline, 1 online), milk, fancy graphics */

		uint64_t cookies_in_bank_;
		uint64_t cookies_baked_;
		uint64_t hand_made_cookies_;
		uint32_t missed_golden_cookies_;
		int8_t background_color_;
		int8_t milk_type;
		uint64_t forfeited_cookies_;
		GrandMatriarchStatus grandmatriarch_status_;
		uint8_t next_upgrade_to_research_;
		uint32_t elder_pledges_bought_;
		uint32_t elder_pledge_time_left_;
		uint32_t next_upgrade_;
		int32_t research_time_left;
		uint32_t reset_count_;
		uint32_t golden_cookies_;
		uint64_t withered_cookies_;
		uint32_t wrinklers_popped_;

		Building::Building buildings_[Constants::BuildingType::BUILDING_COUNT];

	public:
		CookieSave(void);
		bool Load(std::string save_game);
	};
}

#endif /* _COOKIE_SAVE_H_ */

/*
011101
// 0 - particles
// 1 - numbers
// 1 - automatically save
// 1 - offline mode (0 means offline, 1 means online)
// 0 - milk
// 1 - fancy graphics

19810703888477384;232154241051907840;4218;2120;24564619087288988;9632;-1;-1;45326046739823870;0;11;107852;0;-1;2;207;1656259545394620;175
// 19810703888477384 - Cookies in bank
// 232154241051907840 - Cookies baked (this session)
// 4218 - Big cookie clicks
// 2120 - Golden cookie clicks (all time)
// 24564619087288988 - Hand-made cookies
// 9632 - Missed golden cookies (removed feature)
// -1 - Background color (never implemented)
// -1 - Milk type (never implemented)
// 45326046739823870 - Cookies forfeited by resetting
// 0 - Grandmatriarchs status (0=Appeased, 1=Awoken, 2=Displeased, 3=Angered)
// 11 - Elder Pledges bought
// 107852 - Elder Pledge time left (minutes * 1800)
// 0 - Next upgrade to research
// -1 - Research time left (minutes * 1800)
// 2 - Number of resets
// 207 - Golden cookie clicks (this session)
// 1656259545394620 - Cookies withered (sucked by wrinkler)
// 175 - Wrinklers popped

219,220,25128184169839,0;216,216,64729416294516,0;180,180,7033459448,0;168,169,22279979110,0;159,159,75346744514,0;150,150,182832240409,0;139,140,651206881531,0;143,143,11123847712297,0;121,122,120436061607417,0;112,112,1119454662710064,0;
// Each building has its own section, separated by semicolons
// The pattern repeats, so I will only use Cursor as an example
// In this case, the section for Cursor is 219,220,25128184169839,0
// 219 - amount owned
// 220 - amount bought (include ones that were sold)
// 25128184169839 - total cookies produced
// 0 - specialUnlocked (not yet implemented, dungeon related)

4503599627370495;4503599627370495;4503599627370495;4503573749070335;2814337448673279;171798691455
// Convert each number separated by semicolons with this converter
// Take off the first and last 1 of each result and reverse the order
// Separate every 2 digits with a space
// 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
// 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
// 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11
// 11 11 11 11 00 11 11 00 00 10 00 11 00 11 11 11 00 11 11 11 11 11 11 11 11
// 11 11 11 11 11 11 11 11 11 00 11 11 11 11 11 11 11 11 00 11 11 11 11 11 00
// 11 11 11 00 11 11 11 11 11 11 11 11 11 11 11 11 11 00
// Each 2 digits represents an upgrade (order shown at bottom of this page)
// The first digit is whether the upgrade is unlocked (requirements met)
// The second digit is whether the upgrade is bough

4503599627370495;2313303743266815;2047
// Do the same procedure as the Upgrades above, except for separation
// 11111111111111111111111111111111111111111111111111
// 11111111111111111111011111111111111011111101100000
// 111111111
// Each digit represents an achievement (order shown at bottom of this page)


*/