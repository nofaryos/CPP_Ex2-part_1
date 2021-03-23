#include "Direction.hpp"
#include <string>
#include <map>

namespace ariel{
	class Board{
		private:
		
		std::map<std::string, std::string> messages;
		int c;
		
		public:
		
		Board(){
			c = 0;
		}
		~Board(){}
		
		void post(unsigned int row, unsigned int col, Direction d, const std::string &s);
		
		std::string read(unsigned int row, unsigned int col, Direction d, unsigned int length);
		
		void show();
	};
};
		