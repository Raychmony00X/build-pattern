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
	m_query.map[column].push_back(value);
	return *this;
}