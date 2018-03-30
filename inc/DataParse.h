#ifndef DATAPARSE_H_
#define DATAPARSE_H_

#include <vector>
#include "/opt/rapidjson/include/rapidjson/document.h"
#include "/opt/rapidjson/include/rapidjson/writer.h"
#include "/opt/rapidjson/include/rapidjson/stringbuffer.h"
#include <string>
#include <map>

using namespace rapidjson;
using namespace std;

int parseTo(map<string, string> &my_map, string &json)
{
	Document doc;
    doc.Parse((char*)json.c_str());

    pair<string, string> tmp;
	for (Value::ConstMemberIterator itr = doc.MemberBegin();
    	itr != doc.MemberEnd(); ++itr)
	{
		tmp.first = itr->name.GetString();
		if (itr->value.GetType() == 6) 
		{
			char *num_value = new char[20];
			sprintf(num_value, "%f", itr->value.GetDouble());
			tmp.second = num_value;
		}
		else
		{
			tmp.second = itr->value.GetString();
		}
		my_map.insert(tmp);
	}
	return 0;
}

#endif