//
//
// Author : huziang
// this is a cpp file complete mongodb interface in c++

#include "WZMongodbEngine.h"
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/instance.hpp>
#include "ToDocuments.h"

using bsoncxx::document::value;
using mongocxx::cursor;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

DataEngine* MongodbEngine::getInstance() {
  if (instance == NULL) {
    instance = new MongodbEngine();
    instance->conn = new client(mongocxx::uri{});
  }
  return instance;
}

int MongodbEngine::insert_one(const TSMarketDataField &md) {
  // get document
  document doc {};
  toDocument(md, doc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto result = coll.insert_one(*doc);
  return result.inserted_count();
}

int MongodbEngine::insert_many(const vector<TSMarketDataField*> &mds) {
  // get document
  vector<document> docs;
  toDocument(mds, docs);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto result = coll.insert_many(docs);
  return result.inserted_count();
}

int MongodbEngine::update_one(const KeyValue &filter, const vector<KeyValue> &update) {
  // get document
  document filterdoc {};
  ducument updatedoc {};
  toDocument(filter, update, filterdoc, updatedoc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto result = coll.update_one(filterdoc, updatedoc);
  return result.modified_count();
}

int MongodbEngine::update_many(const KeyValue &filter, const vector<KeyValue> &update) {
  // get document
  document filterdoc {};
  ducument updatedoc {};
  toDocument(filter, update, filterdoc, updatedoc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto result = coll.update_many(filterdoc, updatedoc);
  return result.modified_count();
}

int MongodbEngine::find_one(string &json, const vector<KeyValue> &, const char ID[20]) {
  // get document
  document doc {};
  toDocument(find, doc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto value = coll.find(doc).begin();
  json = bsoncxx::to_json(*value);
  return 1;
}

int MongodbEngine::find_many(vector<string> &jsons, const vector<KeyValue> &, const char ID[20]) {
  // get document
  document doc {};
  toDocument(find, doc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto cursor = coll.find(doc);
  int num = 0;
  for (auto docu : cursor) {
    num++;
    jsons.push_back(bsoncxx::to_json(docu));
  }
  return num;
}
