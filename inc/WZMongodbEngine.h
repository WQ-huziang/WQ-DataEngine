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
  int insert_one(const TSMarketDataField*);
  int insert_many(const vector<TSMarketDataField*> &);
  int update_one(const TSMarketDataField*);
  int update_many(const vector<TSMarketDataField*> &);
  // int find_one(WZStoredFrame &, const map<string, string> &, const char tablename[20]) = 0;
  int find(vector<TSMarketDataField*> &, const string, const pair<string, string>, const char ID[20] = "\0");
  //int delete_one(const WZStoredFrame &, const char tablename[20]) = 0;
  //int delete_many(const vector<WZStoredFrame> &, const char tablename[20]) = 0;

 private:
  mongocxx::client *conn;
};

#endif  // WZUTIL_WZDATAENGINE_H_
