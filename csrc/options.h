#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <string>

namespace Options {
	class Options{
	private:
		bool particles_;
		bool numbers_;
		bool auto_save_;
		bool offline_mode_;
		bool milk_;
		bool fancy_graphics_;
	public:
		Options();
		Options(const std::string& options);
	};
}

#endif /* _OPTIONS_H_ */