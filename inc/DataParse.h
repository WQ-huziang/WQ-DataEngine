#ifndef DATAPARSE_H_
#define DATAPARSE_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "/opt/rapidjson/include/rapidjson/document.h"
#include "/opt/rapidjson/include/rapidjson/writer.h"
#include "/opt/rapidjson/include/rapidjson/stringbuffer.h"

#include "wzdatastruct.h"
#include "transportstruct.h"

using namespace rapidjson;
using std::map;
using std::vector;
using std::string;
using std::pair;

inline int parseTo(map<string, string> &my_map, string &json)
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
			delete[] num_value;
		}
		else
		{
			tmp.second = itr->value.GetString();
		}
		my_map.insert(tmp);
	}
	return 0;
}

inline int parseFrom(map<string, string> &my_map, TSMarketDataField &res)
{
	char *num_value = new char[20];

	my_map.insert(pair<string, string>("TradingDay", res.TradingDay));
	my_map.insert(pair<string, string>("InstrumentID", res.InstrumentID));

	sprintf(num_value, "%f", res.LastPrice);
	my_map.insert(pair<string, string>("LastPrice", num_value));
	sprintf(num_value, "%f", res.PreSettlementPrice);
	my_map.insert(pair<string, string>("PreSettlementPrice", num_value));
	sprintf(num_value, "%f", res.PreClosePrice);
	my_map.insert(pair<string, string>("PreClosePrice", num_value));
	sprintf(num_value, "%f", res.PreOpenInterest);
	my_map.insert(pair<string, string>("PreOpenInterest", num_value));
	sprintf(num_value, "%f", res.OpenPrice);
	my_map.insert(pair<string, string>("OpenPrice", num_value));
	sprintf(num_value, "%f", res.HighestPrice);
	my_map.insert(pair<string, string>("HighestPrice", num_value));
	sprintf(num_value, "%f", res.LowestPrice);
	my_map.insert(pair<string, string>("LowestPrice", num_value));
	sprintf(num_value, "%d", res.Volume);
	my_map.insert(pair<string, string>("Volume", num_value));
	sprintf(num_value, "%f", res.Turnover);
	my_map.insert(pair<string, string>("Turnover", num_value));
	sprintf(num_value, "%f", res.OpenInterest);
	my_map.insert(pair<string, string>("OpenInterest", num_value));
	sprintf(num_value, "%f", res.ClosePrice);
	my_map.insert(pair<string, string>("ClosePrice", num_value));
	sprintf(num_value, "%f", res.SettlementPrice);
	my_map.insert(pair<string, string>("SettlementPrice", num_value));
	sprintf(num_value, "%f", res.UpperLimitPrice);
	my_map.insert(pair<string, string>("UpperLimitPrice", num_value));
	sprintf(num_value, "%f", res.LowerLimitPrice);
	my_map.insert(pair<string, string>("LowerLimitPrice", num_value));

	my_map.insert(pair<string, string>("UpdateTime", res.UpdateTime));
	sprintf(num_value, "%d", res.UpdateMillisec);
	my_map.insert(pair<string, string>("UpdateMillisec", num_value));
	sprintf(num_value, "%f", res.BidPrice1);
	my_map.insert(pair<string, string>("BidPrice1", num_value));
	sprintf(num_value, "%d", res.BidVolume1);
	my_map.insert(pair<string, string>("BidVolume1", num_value));
	sprintf(num_value, "%f", res.AskPrice1);
	my_map.insert(pair<string, string>("AskPrice1", num_value));
	sprintf(num_value, "%d", res.AskVolume1);
	my_map.insert(pair<string, string>("AskVolume1", num_value));

	delete[] num_value;
	return 0;
}

inline int parseFrom(map<string, string> &my_map, WZRtnOrderField &res)
{
	char *num_value = new char[20];

	my_map.insert(pair<string, string> ("BrokerID", res.BrokerID));
	my_map.insert(pair<string, string> ("UserID", res.UserID));
	my_map.insert(pair<string, string> ("ParticipantID", res.ParticipantID));
	my_map.insert(pair<string, string> ("InvestorID", res.InvestorID));
	my_map.insert(pair<string, string> ("BusinessUnit", res.BusinessUnit));
	my_map.insert(pair<string, string> ("InstrumentID", res.InstrumentID));
	my_map.insert(pair<string, string> ("OrderRef", res.OrderRef));
	my_map.insert(pair<string, string> ("ExchangeID", res.ExchangeID));

	sprintf(num_value, "%f", res.LimitPrice);
	my_map.insert(pair<string, string> ("LimitPrice", num_value));
	sprintf(num_value, "%d", res.VolumeTraded);
	my_map.insert(pair<string, string> ("VolumeTraded", num_value));
	sprintf(num_value, "%d", res.VolumeTotal);
	my_map.insert(pair<string, string> ("VolumeTotal", num_value));
	sprintf(num_value, "%d", res.VolumeTotalOriginal);
	my_map.insert(pair<string, string> ("VolumeTotalOriginal", num_value));
	sprintf(num_value, "%c", res.TimeCondition);
	my_map.insert(pair<string, string> ("TimeCondition", num_value));
	sprintf(num_value, "%c", res.VolumeCondition);
	my_map.insert(pair<string, string> ("VolumeCondition", num_value));
	sprintf(num_value, "%c", res.OrderPriceType);
	my_map.insert(pair<string, string> ("OrderPriceType", num_value));
	sprintf(num_value, "%c", res.Direction);
	my_map.insert(pair<string, string> ("Direction", num_value));
	sprintf(num_value, "%c", res.OffsetFlag);
	my_map.insert(pair<string, string> ("OffsetFlag", num_value));
	sprintf(num_value, "%c", res.HedgeFlag);
	my_map.insert(pair<string, string> ("HedgeFlag", num_value));
	sprintf(num_value, "%c", res.OrderStatus);
	my_map.insert(pair<string, string> ("OrderStatus", num_value));
	sprintf(num_value, "%d", res.RequestID);
	my_map.insert(pair<string, string> ("RequestID", num_value));

	delete[] num_value;
	return 0;
}

inline int parseFrom(map<string, string> &my_map, TSRtnOrderField &res)
{
	char *num_value = new char[20];
	my_map.insert(pair<string, string> ("InstrumentID", res.InstrumentID));
	my_map.insert(pair<string, string> ("OrderRef", res.OrderRef));

	sprintf(num_value, "%f", res.LimitPrice);
	my_map.insert(pair<string, string> ("LimitPrice", num_value));
	sprintf(num_value, "%d", res.VolumeTraded);
	my_map.insert(pair<string, string> ("VolumeTraded", num_value));
	sprintf(num_value, "%d", res.VolumeTotal);
	my_map.insert(pair<string, string> ("VolumeTotal", num_value));
	sprintf(num_value, "%d", res.VolumeTotalOriginal);
	my_map.insert(pair<string, string> ("VolumeTotalOriginal", num_value));

	sprintf(num_value, "%c", res.Direction);
	my_map.insert(pair<string, string> ("Direction", num_value));
	sprintf(num_value, "%c", res.OffsetFlag);
	my_map.insert(pair<string, string> ("OffsetFlag", num_value));
	sprintf(num_value, "%c", res.OrderStatus);
	my_map.insert(pair<string, string> ("OrderStatus", num_value));

	delete[] num_value;
	return 0;
}

#endif