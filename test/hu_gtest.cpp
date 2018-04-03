//
//
// Author : huziang
// this is a mongodb engine test file
// test function:
//   insert_one
//   insert_many
//   find_one
//   find_many

#include <iostream>
#include <cmath>
#include <map>
#include <gtest/gtest.h>
#include "WZMongodbEngine.h"
#include "DataParse.h"
using namespace std;

#define ASSERT_DOUBLE(a, b) ASSERT_TRUE(abs(a - b) < 0.00001)

DataEngine *db = NULL;
FILE *fp = NULL;
TSMarketDataField *pDepthMarketData = NULL;

mongocxx::client conn;
mongocxx::collection collection;

class TestMongodbEngine : public testing::Test
{
 public:
  static void SetUpTestCase()
  {
    db = MongodbEngine::getInstance();
    db->init();
    db->setLibname("test");
    db->setTablename("TSMarketDataField");

    pDepthMarketData = new TSMarketDataField();
    conn = mongocxx::client(mongocxx::uri("mongodb://localhost:27017"));
    collection = conn["test"]["TSMarketDataField"];
    collection.delete_many({});
  }
  static void TearDownTestCase()
  {
    collection.delete_many({});
    fclose(fp);
  }
  virtual void SetUp()
  {
    fp = fopen("../test/data.csv", "r");
    if (fp == NULL) {
      perror("no file");
      exit(1);
    }
  }
  virtual void TearDown()
  {
  }
};

// insert and then get must equal
TEST_F(TestMongodbEngine, insert_one1)
{
  fread(pDepthMarketData, sizeof(TSMarketDataField), 1, fp);
  map<string, string> ts;
  vector<KeyValue> cond;
  // if (pDepthMarketData != NULL) {
  //   cerr << pDepthMarketData->SettlementPrice << endl;
  //   char temp[10000];
  //   sprintf(temp, "%lf", pDepthMarketData->SettlementPrice);
  //   cout << temp << endl;
  // }
  parseFrom(ts, *pDepthMarketData);

  // insert one
  db->insert_one(ts);
  ts.clear();
  int num = db->find_one(ts, cond, pDepthMarketData->InstrumentID);
  cout << "NUM:" << num << endl;
  // test return value
  ASSERT_TRUE(num == 1);

  // test string value
  // ASSERT_STREQ(pDepthMarketData->TradingDay, ts["TradingDay"].c_str());
  // ASSERT_STREQ(pDepthMarketData->InstrumentID, ts["InstrumentID"].c_str());
  // ASSERT_STREQ(pDepthMarketData->UpdateTime, ts["UpdateTime"].c_str());

  // test double value
  // double d;
  // sscanf(ts["LastPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->LastPrice);
  // sscanf(ts["PreSettlementPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->PreSettlementPrice);
  // sscanf(ts["PreClosePrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->PreClosePrice);
  // sscanf(ts["PreOpenInterest"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->PreOpenInterest);
  // sscanf(ts["OpenPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->OpenPrice);
  // sscanf(ts["HighestPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->HighestPrice);
  // sscanf(ts["LowestPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->LowestPrice);
  // sscanf(ts["Turnover"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->Turnover);
  // sscanf(ts["OpenInterest"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->OpenInterest);
  // sscanf(ts["ClosePrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->ClosePrice);
  // sscanf(ts["SettlementPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->SettlementPrice);
  // sscanf(ts["UpperLimitPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->UpperLimitPrice);
  // sscanf(ts["LowerLimitPrice"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->LowerLimitPrice);
  // sscanf(ts["BidPrice1"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->BidPrice1);
  // sscanf(ts["AskPrice1"].c_str(), "%lf", &d);
  // ASSERT_DOUBLE(d, pDepthMarketData->AskPrice1);

  // test int value
  // int i;
  // sscanf(ts["Volume"].c_str(), "%d", &i);
  // ASSERT_EQ(i, pDepthMarketData->Volume);
  // sscanf(ts["UpdateMillisec"].c_str(), "%d", &i);
  // ASSERT_EQ(i, pDepthMarketData->UpdateMillisec);
  // sscanf(ts["BidVolume1"].c_str(), "%d", &i);
  // ASSERT_EQ(i, pDepthMarketData->BidVolume1);
  // sscanf(ts["AskVolume1"].c_str(), "%d", &i);
  // ASSERT_EQ(i, pDepthMarketData->AskVolume1);
}


TEST_F(TestMongodbEngine, insert_one2)
{
  // for (int i=0; i<100; i++){
  //   if (fread(pDepthMarketData, sizeof(TSMarketDataField), 1, fp) == -1) {
  //     break;
  //   }
  //   parseFrom(ts, *pDepthMarketData);
  //   db->insert_one(ts);
  // }
}

TEST_F(TestMongodbEngine, insert_many)
{
  //fread(pDepthMarketData, sizeof(TSMarketDataField), 1, fp);
  // for (int i=0; i<100; i++){

  // }
}

int main(int argc,char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}