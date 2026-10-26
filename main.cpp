#include "sql_select_query_builder.h"

int main() {
	SqlSelectQueryBuilder query_builder;	
	query_builder.AddColumn("name")
		.AddColumn("name")
		.AddFrom("students")
		.AddWhere("id", "42")
		.AddWhere("name", "John");

	query_builder.BuildQuery();

	std::cout << std::endl;

	std::vector<std::string> v = { "phone", "age" };
	std::unordered_map<std::string, std::string> my_map = { { "phone",   "unknown"   },
	{ "age", "21" } };

	query_builder.AddColumns(v)
		.AddWhere(my_map);

	query_builder.BuildQuery();

	return 0;
}