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
#include "DataParse.h"
using namespace std;

DataEngine *db = NULL;
FILE *fp = NULL;
TSMarketDataField *pDepthMarketData = NULL;

//mongocxx::instance inst{};
mongocxx::client conn = mongocxx::client(mongocxx::uri("mongodb://localhost:27017"));
mongocxx::collection collection = conn["test"]["TSMarketDataField"];

map<string, string> ts;
//map<KeyValue> kv;

void find_all() {

}

class TestMongodbEngine : public testing::Test
{
 public:
  static void SetUpTestCase()
  {
    db = MongodbEngine::getInstance();
    db->setLibname("test");
    db->setTablename("TSMarketDataField");
    fp = fopen("../test/data.csv", "r");
    if (fp == NULL) {
      perror("no file");
      exit(1);
    }
    pDepthMarketData = new TSMarketDataField();
  }
  static void TearDownTestCase()
  {
    collection.delete_many({});
    fclose(fp);
  }
  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
    delete pDepthMarketData;
    ts.clear();
    //kv.clear();
  }
};

TEST_F(TestMongodbEngine, insert_one)
{
  //fread(pDepthMarketData, sizeof(TSMarketDataField), 1, fp);
  for (int i=0; i<100; i++){
    memset(pDepthMarketData, 0, sizeof(pDepthMarketData));
    pDepthMarketData->Volume = i;
    parseFrom(ts, *pDepthMarketData);
    db->insert_one(ts);
  }
}

TEST_F(TestMongodbEngine, insert_many)
{
  //fread(pDepthMarketData, sizeof(TSMarketDataField), 1, fp);
  for (int i=0; i<100; i++){
    
  }
}

int main(int argc,char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}