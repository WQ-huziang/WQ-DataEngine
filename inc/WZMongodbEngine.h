//
//
// Author : huziang
// this is a mongodb database complete

#ifndef WZUTIL_WZDATAENGINE_H_
#define WZUTIL_WZDATAENGINE_H_

#include <mongocxx/client.hpp>
#include "WZDataEngine.h"

class MongodbEngine : public DataEngine {
 public:
  static DataEngine* getInstance();

  // type TSMarketDataField
  int insert_one(const TSMarketDataField &);
  int insert_many(const vector<TSMarketDataField*> &);
  int update_one(const KeyValue &, const vector<KeyValue> &);
  int update_many(const KeyValue &, const vector<KeyValue> &);
  int find_one(string &json, const vector<KeyValue> &, const char ID[20] = "\0");
  int find_many(vector<string> &jsons, const vector<KeyValue> &, const char ID[20] = "\0");

 private:
  mongocxx::client *conn;
};

#endif  // WZUTIL_WZDATAENGINE_H_
