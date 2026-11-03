#include "MySQLManager.hpp"

#include <string>
#include <mysqlx/xdevapi.h>

using namespace Util;

MySQLManager::MySQLManager(const std::string& dbName, const std::string& userName, const std::string& pwd) :
	dbname(dbName), username(userName), pwd(pwd) {

}

using Entry = std::vector<std::string>;
using QueryRes = std::vector<Entry>;
//result of query, nullopt if fail
std::optional<QueryRes> MySQLManager::query(const std::string& query) const {
	return std::nullopt;
}