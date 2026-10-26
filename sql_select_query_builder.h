#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

struct Query {
	std::string table;
	std::unordered_map<std::string, std::string> map;
};

class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder() = default;

	SqlSelectQueryBuilder& AddColumn(const std::string& column);

	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;

	SqlSelectQueryBuilder& AddFrom(const std::string& table);

	SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value); 

	SqlSelectQueryBuilder& AddWhere(std::unordered_map<std::string, std::string>& kv) noexcept;

	~SqlSelectQueryBuilder() = default;

	void BuildQuery() {
		std::cout << "\"" << "Select ";
		for (const auto& [column, values] : m_query.map) {
			std::cout << column << " ";
		}

		std::cout << "FROM " << m_query.table << " WHERE ";
		bool first = true;
		for (const auto& [column, values] : m_query.map) {
			if (!first) std::cout << " AND ";
			first = false;

			std::cout << column << "=";
			for (const auto& value : values) {
				std::cout << value;
			}
		}

		std::cout << "\"" << std::endl;
	}

private:
	Query m_query;
};