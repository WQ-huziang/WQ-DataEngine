//
//
// Author : huziang
// this is a cpp file complete mongodb interface in c++

#include "WZMongodbEngine.h"
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::stream::document;
using bsoncxx::document::value;
using mongocxx::cursor;

DataEngine* MongodbEngine::getInstance() {
  if (instance == NULL) {
    instance = new MongodbEngine();
  }
  return instance;
}

int MongodbEngine::insert_one(const TSMarketDataField *) {

}

int MongodbEngine::insert_many(const vector<TSMarketDataField*> &) {

}

int MongodbEngine::update_one(const TSMarketDataField *) {

}

int MongodbEngine::update_many(const vector<TSMarketDataField*> &) {

}

int MongodbEngine::find(vector<TSMarketDataField*> &, const string, const pair<string, string>, const char ID[20]) {

}

int MongodbEngine::insert(document *doc) {

}

int MongodbEngine::update(document *doc) {

}

int MongodbEngine::find(document *doc) {

}
