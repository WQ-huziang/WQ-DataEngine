//
//
// Author : huziang
// this is a file include function struct to document

// struct TSMarketDataField
// {
//     char_13  	TradingDay;            //交易日
//     char_31  	InstrumentID;          //合约代码
//     double   	LastPrice;             //最新价
//     double   	PreSettlementPrice;    //上次结算价
//     double   	PreClosePrice;         //昨收盘
//     double   	PreOpenInterest;       //昨持仓量
//     double   	OpenPrice;             //今开盘
//     double   	HighestPrice;          //最高价
//     double   	LowestPrice;           //最低价
//     int      	Volume;                //数量
//     double   	Turnover;              //成交金额
//     double   	OpenInterest;          //持仓量
//     double   	ClosePrice;            //今收盘
//     double   	SettlementPrice;       //本次结算价
//     double   	UpperLimitPrice;       //涨停板价
//     double   	LowerLimitPrice;       //跌停板价
//     char_13  	UpdateTime;            //最后修改时间
//     int      	UpdateMillisec;        //最后修改毫秒
//     double   	BidPrice1;             //申买价一
//     int      	BidVolume1;            //申买量一
//     double   	AskPrice1;             //申卖价一
//     int      	AskVolume1;            //申卖量一
// };

#ifndef WZUTIL_TODOCUMENT_H_
#define WZUTIL_TODOCUMENT_H_

using bsoncxx::builder::stream::document;

void toDocument(const map<string, string> md, document *doc) {
	map<string, string>::iterator it;
	for(it = md.begin; it != md.end(); it++){
		(*doc) << it->first << it->second;
	}
	(*doc) << bsoncxx::builder::stream::finalize;
}

void toDocument(const vector<map<string, string>> & vmd, vector<document> & docs) {
	int length = vTSMd.size();
	for(int index=0; index<length; index++){
		document doc;
		toDocument(vTSMd[index], doc);
		docs.push_back(doc);
	}
}

//key: column name
//value: lowerbound & upperbound
//ID: instrument id
void toDocument(vector<KeyValue> &find, const char ID[20], document *doc) {
	vector<KeyValue>::iterator it;
	for(it = find.begin; it != find.end(); it++){
		if(it -> maxvalue != ""){
			if(strlen(ID) != 0){
				(*doc) << it ->key << bsoncxx::builder::stream::open_document
						<< "$gte" << it->minvalue
						<< "$lte" << it->maxvalue
						<< bsoncxx::builder::stream::close_document
						<< "InstrumentID" << ID
						<< bsoncxx::builder::stream::finalize;
			} else {
				(*doc) << it->key << bsoncxx::builder::stream::open_document
						<< "$gte" << it->minvalue
						<< "$lte" << it->maxvalue
						<< bsoncxx::builder::stream::close_document
						<< bsoncxx::builder::stream::finalize;
			}
		} else {
			(*doc) << it->key << it->minvalue << "InstrumentID" << ID << bsoncxx::builder::stream::finalize;
		}
	}
}

//update one
void toDocument(KeyValue *find, vector<KeyValue> & value, document *doc_find, document *doc_update){
	if(find -> maxvalue != ""){
		(*doc_find) << find->key << bsoncxx::builder::stream::open_document
					<< "$gte" << find->minvalue
					<< "$lte" << find->maxvalue
					<< bsoncxx::builder::stream::close_document
					<< bsoncxx::builder::stream::finalize;
	} else {
		(*doc_update) << find->key << find->minvalue << bsoncxx::builder::stream::finalize;
	}
	int length = value.size();
	for(int index=0; index<length; index++){
		(*doc_update) << "$set" << bsoncxx::builder::stream::open_document
									<< value[index]->key << value[index]->minvalue
									<< bsoncxx::builder::stream::close_document
									<< bsoncxx::builder::stream::finalize;
	}
}


#endif  // WZUTIL_TODOCUMENT_H_
