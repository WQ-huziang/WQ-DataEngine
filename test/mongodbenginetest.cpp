//
//
// Author : huziang
// this is a mongodb engine test file
// test function:
//   insert_one
//   insert_many
//   update_one
//   update_many
//   find_one
//   find_many

#include <iostream>
#include <map>
#include <gtest/gtest.h>
#include "WZMongodbEngine.h"
#include "ThostFtdcMdApi.h"
using namespace std;

inline struct TSMarketDataField parserFrom(const CThostFtdcDepthMarketDataField &req){
  TSMarketDataField rtn;
  strcpy(rtn.TradingDay, req.TradingDay);
  strcpy(rtn.InstrumentID, req.InstrumentID);
  rtn.LastPrice = req.LastPrice;
  rtn.PreSettlementPrice = req.PreSettlementPrice;
  rtn.PreClosePrice = req.PreClosePrice;
  rtn.PreOpenInterest = req.PreOpenInterest;
  rtn.OpenPrice = req.OpenPrice;
  rtn.HighestPrice = req.HighestPrice;
  rtn.LowestPrice = req.LowestPrice;
  rtn.Volume = req.Volume;
  rtn.Turnover = req.Turnover;
  rtn.OpenInterest = req.OpenInterest;
  rtn.ClosePrice = req.ClosePrice;
  rtn.SettlementPrice = req.SettlementPrice;
  rtn.UpperLimitPrice = req.UpperLimitPrice;
  rtn.LowerLimitPrice = req.LowerLimitPrice;
  strcpy(rtn.UpdateTime, req.UpdateTime);
  rtn.UpdateMillisec = req.UpdateMillisec;
  rtn.BidPrice1 = req.BidPrice1;
  rtn.BidVolume1 = req.BidVolume1;
  rtn.AskPrice1 = req.AskPrice1;
  rtn.AskVolume1 = req.AskVolume1;
  return rtn;
}

DataEngine *db = NULL;


class TestMongodbEngine : public testing::Test
{
 public:
  static void SetUpTestCase()
  {
    db = MongodbEngine::getInstance();
  }
  static void TearDownTestCase()
  {
  }
  virtual void SetUp()
  {

  }
  virtual void TearDown()
  {

  }
};

TEST_F(TestMongodbEngine, SizeOF)
{
    ASSERT_TRUE(db == NULL);
}

int main(int argc,char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}