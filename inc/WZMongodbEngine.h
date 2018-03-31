//
//
// Author : huziang
// this is a mongodb database complete

#ifndef WZUTIL_WZDATAENGINE_H_
#define WZUTIL_WZDATAENGINE_H_

#include <mongocxx/client.hpp>
#include <map>
#include "WZDataEngine.h"

class MongodbEngine : public DataEngine {
 public:
  static DataEngine* getInstance();

  // type TSMarketDataField
  int insert_one(const map<string, string> &);
  int insert_many(const vector<map<string, string>> &);
  int update_one(KeyValue, vector<KeyValue> &) = 0;
  int update_many(KeyValue, vector<KeyValue> &) = 0;
  int find(vector<map<string, string>> &, vector<KeyValue> &, const char ID[20] = "\0");
  // int find(vector<TSMarketDataField*> &, vector<KeyValue> &, const char ID[20] = "\0") = 0;

 private:
  mongocxx::client *conn;
};

#endif  // WZUTIL_WZDATAENGINE_H_
