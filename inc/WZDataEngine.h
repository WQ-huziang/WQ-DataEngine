//
//
// Author : huziang
// include class DataEngine and struct

#ifndef WZUTIL_WZDATAENGINE_H_
#define WZUTIL_WZDATAENGINE_H_

#include <cstring>
#include <iostream>
#include "transportstruct.h"
using std::vector;
using std::pair;

class DataEngine {
 public:
  static DataEngine* getInstance() = 0;
  inline void setlibname(const char lib[20]) { strcpy(libname, lib); }
  inline void settablename(const char table[20]) { strcpy(tablename, table); }

  // type TSMarketDataField
  int insert_one(const TSMarketDataField *) = 0;
  int insert_many(const vector<TSMarketDataField*> &) = 0;
  int update_one(const TSMarketDataField *) = 0;
  int update_many(const vector<TSMarketDataField*> &) = 0;
  int find(vector<TSMarketDataField*> &, const string, pair<string, string>, const char ID[20] = "\0") = 0;
  //bool delete_one(const WZStoredFrame &, const char tablename[20]) = 0;
  //bool delete_many(const vector<WZStoredFrame> &, const char tablename[20]) = 0;

 private:
  static DataEngine *instance = NULL;
  const char libname[20];
  const char tablename[20];
};

#endif  // WZUTIL_WZDATAENGINE_H_