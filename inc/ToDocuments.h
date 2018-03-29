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

void toDocument(const TSMarketDataField* pMd, document *doc) {
	(*doc) << "TradingDay" << pMd->TradingDay
				<< "InstrumentID" << pMd->InstrumentID
				<< "LastPrice" << pMd->LastPrice
				<< "PreSettlementPrice" << pMd->LastPrice
				<< "PreClosePrice" << pMd->PreClosePrice
				<< "PreOpenInterest" << pMd->PreOpenInterest
				<< "OpenPrice" << pMd->OpenPrice
				<< "HighestPrice" << pMd->HighestPrice
				<< "LowestPrice" << pMd->LowestPrice
				<< "Volume" << pMd->Volume
				<< "Turnover" << pMd->Turnover
				<< "OpenInterest" << pMd->OpenInterest
				<< "ClosePrice" << pMd->ClosePrice
				<< "SettlementPrice" << pMd->SettlementPrice
				<< "UpperLimitPrice" << pMd->UpperLimitPrice
				<< "LowerLimitPrice" << pMd->LowerLimitPrice
				<< "UpdateTime" << pMd->UpdateTime
				<< "UpdateMillisec" << pMd->UpdateMillisec
				<< "BidPrice1" << pMd->BidPrice1
				<< "BidVolume1" << pMd->BidVolume1
				<< "AskPrice1" << pMd->AskPrice1
				<< "AskVolume1" << pMd->AskVolume1
				<< bsoncxx::builder::stream::finalize;
}

void toDocument(const vector<TSMarketDataField*> & vTSMd, vector<document> & docs) {
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
void toDocument(const string key, const pair<string, string> value, const char ID[20], document *doc) {
	if(pair.second != ""){
		(*doc) << key << bsoncxx::builder::stream::open_document
					<< "$gte" << pair.first
					<< "$lte" << pair.second
					<< bsoncxx::builder::stream::close_document
					<< bsoncxx::builder::stream::finalize;
	}
	else{
		(*doc) << key << pair.first << bsoncxx::builder::stream::finalize;
	}
}


#endif  // WZUTIL_TODOCUMENT_H_
