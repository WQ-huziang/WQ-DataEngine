#include "DataParse.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string json = "{\"project\":\"rapidjson\",\"stars\":10}";
	map<string, string> temp;
	int ret = parseTo(temp, json);
	for (map<string, string>::iterator itr = temp.begin(); itr != temp.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}

	return 0;
}