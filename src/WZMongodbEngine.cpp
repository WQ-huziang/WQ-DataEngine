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

int MongodbEngine::insert_one(const map<string, string> &md) {
  // get document
  document doc {};
  toDocument(md, &doc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto result = coll.insert_one(*doc);
  return result.inserted_count();
}

int MongodbEngine::insert_many(const vector<map<string, string>> &mds) {
  // get document
  vector<document> docs;
  toDocument(mds, &docs);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  auto result = coll.insert_many(docs);
  return result.inserted_count();
}

int MongodbEngine::update_one(const TSMarketDataField *md) {
  // get document
  document doc {};
  toDocument(md, &doc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  return update(&doc);
}

int MongodbEngine::update_many(const vector<TSMarketDataField*> &mds) {
  // get document
  document doc {};
  toDocument(mds, &doc);

  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  return update(&doc);
}

int MongodbEngine::find(vector<map<string, string>> &mds, vector<KeyValue> &condition, const char ID[20] ID) {
  // get document
  document doc {};
  toDocument(condition, ID, &doc);
  return find(mds, &doc);
}

int MongodbEngine::insert(document *doc) {
  // get collection
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  coll.insert_one(*doc);
}

int MongodbEngine::update(document *doc) {

}

int MongodbEngine::find(vector<map<string, string>> &mds, document *doc) {
  mongocxx::database db = conn->database(libname);
  mongocxx::collection coll = db[tablename];
  mongocxx::cursor cursor = coll.find(*doc);
  if(!cursor){
    return -1;
  }
  for(auto cur : cursor){
    
  }
}
