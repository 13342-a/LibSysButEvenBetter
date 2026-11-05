#include "SQLiteManager.hpp"

#include "sqlite3.h"

#include <string>
#include <vector>
#include <optional>
#include <stdexcept>

using namespace Util;

SQLiteManager::SQLiteManager(const std::string& name) : name(name), db(nullptr) {
	connect();
}

SQLiteManager::~SQLiteManager() {
	disconnect();
}

void SQLiteManager::connect() {
	if (db) return;

	if (sqlite3_open_v2(name.c_str(), &db, generalFlag, nullptr) != SQLITE_OK) {
		disconnect();
		throw std::runtime_error("Error: Database " + name + " cannot be opened.");
	}
}

void SQLiteManager::disconnect() {
	if (!db) return;

	sqlite3_close_v2(db);
	db = nullptr;
}

std::string SQLiteManager::getErr() const {
	if (!db) {
		throw std::runtime_error("Error: Database is not connected.");
	}
	std::string errMsg = sqlite3_errmsg(db);
	return errMsg;
}

std::string SQLiteManager::getName() const {
	return name;
}

using Entry = std::vector<std::string>;
using QueryRes = std::vector<Entry>;
//result of query, nullopt if fail
std::optional<QueryRes> SQLiteManager::query(const std::string& query) const {
	return std::nullopt;
}