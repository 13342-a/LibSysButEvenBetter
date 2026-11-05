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
		sqlite3* db;
		std::string name;
	public:
		SQLiteManager(const std::string& name);
		~SQLiteManager();

		using Entry = std::vector<std::string>;
		using QueryRes = std::vector<Entry>;
		//result of query, nullopt if fail
		std::optional<QueryRes> query(const std::string& query) const override;

		bool connect() override;

		bool disconnect() override;

		std::string& getErr() const override;

		std::string& getName() const override;
	};
}