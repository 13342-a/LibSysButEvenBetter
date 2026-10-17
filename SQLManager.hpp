#include <mysqlx/xdevapi.h>
#include <string>

namespace Util
{
	class SQLManager {
		std::string dbname;
		std::string username;
		std::string pwd;
	public:
		SQLManager();
		~SQLManager() = default;
		SQLManager(SQLManager& other) = default;
		SQLManager& operator= (SQLManager& other) = default;
	
	
	};
}