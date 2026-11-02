#include "sqlite3.h"

#include <string>

namespace Util
{
	class SQLiteManager
	{
		sqlite3* db;
		std::string name;
	public:
		SQLiteManager(const std::string& name);
		~SQLiteManager();


	};
}