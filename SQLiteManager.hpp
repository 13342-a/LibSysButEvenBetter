#pragma once

#include "SQLinterface.hpp"

#include "sqlite3.h"

#include <string>
#include <vector>
#include <optional>

namespace Util
{
	class SQLiteManager : public ISQLManager
	{
		static constexpr bool done = false;
		static constexpr short generalFlag = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
		sqlite3* db;
		std::string name;
	public:
		SQLiteManager(const std::string& name);
		~SQLiteManager();

		SQLiteManager(const SQLiteManager& other) = delete;
		SQLiteManager& operator= (const SQLiteManager& other) = delete;

		SQLiteManager(SQLiteManager&& other) = delete;
		SQLiteManager& operator= (SQLiteManager&& other) = delete;

		using Entry = std::vector<std::string>;
		using QueryRes = std::vector<Entry>;
		//result of query, nullopt if fail
		std::optional<QueryRes> query(const std::string& query) const override;

		void connect() override;

		void disconnect() override;

		std::string getErr() const override;

		std::string getName() const override;
	};
}