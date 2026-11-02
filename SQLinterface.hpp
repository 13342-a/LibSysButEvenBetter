//interface for polymorphism for MySQL vs SQLite
#include <string>
#include <vector>
#include <optional>

namespace Util
{
	class ISQLManager
	{
	public:
		virtual ~ISQLManager() = default;

		virtual bool connect() = 0;

		using Entry = std::vector<std::string>;
		using QueryRes = std::vector<Entry>;
		//result of query, nullopt if fail
		virtual std::optional<QueryRes> query(const std::string& query) const = 0;

		virtual bool disconnect() = 0;

		virtual std::string& getErr() = 0;

		virtual std::string& getName() = 0;
	};
}