//
//
// Author : huziang
// include class DataEngine and struct

#ifndef WZUTIL_WZDATAENGINE_H_
#define WZUTIL_WZDATAENGINE_H_

#include <cstring>
#include <iostream>
#include <map>
#include "transportstruct.h"
using std::vector;
using std::string;
using std::map;

struct KeyValue {
  string key;
  string minvalue;
  string maxvalue;
};

class DataEngine {
 public:
  inline void setLibname(const char lib[20]) { strcpy(libname, lib); }
  inline void setTablename(const char table[20]) { strcpy(tablename, table); }

  // using map and vector<map> to translate all kinds of struct
  virtual int insert_one(const map<string, string> &) = 0;
  virtual int insert_many(const vector<std::map<string, string>> &) = 0;
  virtual int update_one(const KeyValue &, const vector<KeyValue> &) = 0;
  virtual int update_many(const KeyValue &, const vector<KeyValue> &) = 0;
  virtual int find_one(map<string, string> &, const vector<KeyValue> &, const char ID[20] = "\0") = 0;
  virtual int find_many(vector<map<string, string>> &, const vector<KeyValue> &, const char ID[20] = "\0") = 0;

 protected:
  DataEngine() {}
  static DataEngine *instance;
  char libname[20];
  char tablename[20];
};

DataEngine *DataEngine::instance = NULL;

#endif  // WZUTIL_WZDATAENGINE_H_