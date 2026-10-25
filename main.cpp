#include "sql_select_query_builder.h"

int main() {
	SqlSelectQueryBuilder query_builder;	
	query_builder.AddColumn("name")
		.AddColumn("name")
		.AddFrom("students")
		.AddWhere("id", "42")
		.AddWhere("name", "John");

	query_builder.BuildQuery();

	return 0;
}