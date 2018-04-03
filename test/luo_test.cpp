#include <iostream>
#include <WZMongodbEngine.h>
#include <map>
#include <vector>
#include "DataParse.h"
#include "transportstruct.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

DataEngine *db = NULL;

WZRtnOrderField my_data_1;

int main()
{

	db = MongodbEngine::getInstance();
	db->setLibname("test");
	db->setTablename("WZRtnOrderField");

	// int i;
	// map<string, string> my_map;
	// for (i=0; i<10; i++)
	// {
	// 	my_map.clear();
	// 	memset(&my_data_1, 0, sizeof(my_data_1));
	// 	my_data_1.VolumeTotal = i;
	// 	parseFrom(my_map, my_data_1);
	// 	db->insert_one(my_map);
	// }

	vector<map<string, string>> my_find_result;
	vector<KeyValue> my_find_condition;
	my_find_condition.clear();
	KeyValue temp ;
	temp.key = "VolumeTotal";
	temp.minvalue = "0";
	temp.maxvalue = "9";
	my_find_condition.push_back(temp);
	db->find_many(my_find_result, my_find_condition);
	for (auto &it_1 :my_find_result)
	{
		for (auto &it_2 : it_1)
		{
			cout << it_2.first << " " << it_2.second << endl;
		}
		
	}

	return 0;
}
