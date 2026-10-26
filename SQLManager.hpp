#include <mysqlx/xdevapi.h>
#include <string>
#include <optional>
#include <vector>

namespace Util
{
	class SQLManager {
		std::string dbname;
		std::string username;
		std::string pwd;
	public:
		SQLManager(const std::string& dbName, const std::string& userName, const std::string& pwd);
		~SQLManager() = default;
		SQLManager(SQLManager& other) = default;
		SQLManager& operator= (SQLManager& other) = default;

		using Entry = std::vector<std::string>;
		using QueryRes = std::vector<Entry>;
		//result of query, nullopt if fail
		std::optional<QueryRes> query(const std::string& query); 
	};
}