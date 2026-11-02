#include "MySQLManager.hpp"

#include <string>
#include <mysqlx/xdevapi.h>

using namespace Util;

MySQLManager::MySQLManager(const std::string& dbName, const std::string& userName, const std::string& pwd) :
	dbname(dbName), username(userName), pwd(pwd) {

}

//result of query, nullopt if fail
std::optional<MySQLManager::QueryRes> MySQLManager::query(const std::string& query) const {
	return std::nullopt;
}