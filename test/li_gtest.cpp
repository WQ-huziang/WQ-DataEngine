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

map<string, string> ts;
map<string, string> ts2;
vector<map<string, string>> dataset;
vector<KeyValue> filter;
//map<KeyValue> kv;

void find_all() {

}

class TestMongodbEngine : public testing::Test
{
 public:
  static void SetUpTestCase()
  {
    db = MongodbEngine::getInstance();
    db->init();
    db->setLibname("test");
    db->setTablename("TSMarketDataField2");
    fp = fopen("../test/data.csv", "r");
    if (fp == NULL) {
      perror("no file");
      exit(1);
    }
    pDepthMarketData = new TSMarketDataField();
  }
  static void TearDownTestCase()
  {
    //collection.delete_many({});
    fclose(fp);
  }
  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
    // delete pDepthMarketData;
    ts.clear();
    //kv.clear();
  }
};

bool ione(){

  
  return true;
}

// TEST_F(TestMongodbEngine, insert_one)
// {
//   for(int i=0; i<100; i++){
//     cout << i << endl;
//     memset(pDepthMarketData, 0, sizeof(pDepthMarketData));
//     pDepthMarketData->Volume = 999;
//     parseFrom(ts, *pDepthMarketData);
//     db->insert_one(ts);
//   }
//   map<string, string> ts2;
//   KeyValue kv;
//   kv.key = "Volume";
//   kv.minvalue = "50";
//   kv.maxvalue = "";
//   filter.push_back(kv);
//   char *instrumentid = {"\0"};
//   db->find_one(ts2, filter, instrumentid);
//   map<string, string>::iterator it1 = ts.begin();
//   map<string, string>::iterator it2 = ts2.begin();
//   cout << ts2.size() << endl;
//   for(; it1 != ts.end(), it2 != ts2.end(); it1++, it2++){
//     // cout << it1->first << ": " << it1->second << endl;
//     cout << it2->first << ": " << it2->second << endl;
//   }
// }

// TEST_F(TestMongodbEngine, insert_many)
// {
//   //fread(pDepthMarketData, sizeof(TSMarketDataField), 1, fp);
//   for (int i=700; i<800; i++){
//     memset(pDepthMarketData, 0, sizeof(pDepthMarketData));
//     pDepthMarketData->Volume = i;
//     pDepthMarketData->LastPrice = i;
//     parseFrom(ts, *pDepthMarketData);
//     dataset.push_back(ts);
//     ts.clear();
//   }
//   cout << dataset.size() << endl;
//   db->insert_many(dataset);
// }

// TEST_F(TestMongodbEngine, find_one)
// {
//   KeyValue kv;
//   kv.key = "Volume";
//   kv.minvalue = "50";
//   kv.maxvalue = "";
//   filter.push_back(kv);
//   char *instrumentid = {"\0"};
//   db->find_one(ts, filter, instrumentid);
//   map<string, string>::iterator it = ts.begin();
//   for(; it != ts.end(); it++){
//     cout << it->first << ": " << it->second << endl;
//   }
// }

// // virtual int find_many(vector<map<string, string>> &, const vector<KeyValue> &, const char ID[20] = "\0") = 0;
TEST_F(TestMongodbEngine, find_many)
{
  KeyValue kv1, kv2;
  kv1.key = "Volume";
  kv1.minvalue = "999";
  kv1.maxvalue = "";
  filter.push_back(kv1);
  char *instrumentid = {"\0"};
  vector<map<string, string>> dataset2;
  db->find_many(dataset2, filter, instrumentid);
  vector<map<string, string>>::iterator it = dataset2.begin();
  cout << dataset2.size() << endl;
  for(; it != dataset2.end(); it++){
    map<string, string> temp = *it;
    map<string, string>::iterator titr = temp.begin();
    for(; titr != temp.end(); titr++){
      cout << titr->first << ": " << titr->second << endl;
    }
  }
}

// TEST_F(TestMongodbEngine, del_one)
// {
//   KeyValue kv;
//   kv.key = "Volume";
//   kv.minvalue = "999";
//   filter.push_back(kv);
//   char *instrumentid = {"\0"};
//   // vector<map<string, string>> dataset2;
//   db->delete_many(filter, instrumentid);

// }

int main(int argc,char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}