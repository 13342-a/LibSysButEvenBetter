#include "SQLManager.hpp"

#include <string>
#include <mysqlx/xdevapi.h>

using namespace Util;

SQLManager::SQLManager() {

}

using Entry = std::vector<std::string>;
using QueryRes = std::vector<Entry>;
//result of query, nullopt if fail
std::optional<QueryRes> SQLManager::query(const std::string& query) {

} 