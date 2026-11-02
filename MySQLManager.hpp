#include <mysqlx/xdevapi.h>
#include <string>
#include <optional>
#include <vector>

namespace Util
{
	class MySQLManager {
		std::string dbname;
		std::string username;
		std::string pwd;
	public:
		MySQLManager(const std::string& dbName, const std::string& userName, const std::string& pwd);
		~MySQLManager() = default;
		MySQLManager(MySQLManager& other) = default;
		MySQLManager& operator= (MySQLManager& other) = default;

		using Entry = std::vector<std::string>;
		using QueryRes = std::vector<Entry>;
		//result of query, nullopt if fail
		std::optional<QueryRes> query(const std::string& query) const;
	};
}