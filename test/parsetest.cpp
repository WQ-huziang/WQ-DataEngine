#include "DataParse.h"
#include <map>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	TSMarketDataField a;
	memset(&a, 0, sizeof(a));
	sprintf(a.TradingDay, "%s", "20180320");

	map<string, string> temp;
	int ret = parseFrom(temp, a);

	for (map<string, string>::iterator itr = temp.begin(); itr != temp.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}

	return 0;
}