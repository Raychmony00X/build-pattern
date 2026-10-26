#include "sql_select_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
	m_query.map[column];
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
	m_query.table = table;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) {
	m_query.map[column] = value;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
	for (const auto& it : columns) {
		m_query.map[it];
	}

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::unordered_map<std::string, std::string>& kv) noexcept {
	m_query.map = std::move(kv);

	return *this;
}