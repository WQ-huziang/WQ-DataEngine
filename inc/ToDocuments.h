//
//
// Author : huziang
// this is a file include function struct to document

#ifndef WZUTIL_TODOCUMENT_H_
#define WZUTIL_TODOCUMENT_H_

using bsoncxx::builder::stream::document;

void toDocument(const TSMarketDataField*, document *doc) {

}

void toDocument(const vector<TSMarketDataField*> &, document *doc) {

}

void toDocument(const string, const pair<string, string>, const char ID[20], document *doc) {

}


#endif  // WZUTIL_TODOCUMENT_H_
