#pragma once

#include "Request.h"
#include <vector>
#include <string>
#include <unordered_set>

// Database Manager with MongoDB

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/client_session.hpp>

class DatabaseManager {
private:
    mongocxx::instance     instance{};
    mongocxx::uri          uri;
    mongocxx::client       client;
    mongocxx::database     DB;
    mongocxx::collection   users_collection;
    mongocxx::collection   orders_collection;
    mongocxx::collection   proposals_collection;

public:
    DatabaseManager();

    mongocxx::collection getUsersCollection();
    mongocxx::collection getOrdersCollection();
    mongocxx::collection getProposalsCollection();
    
    bsoncxx::document::value createDocument() {
        return bsoncxx::document::value(bsoncxx::builder::stream::document{}
            << bsoncxx::builder::stream::finalize);
    }

    template<typename T, typename U, typename... Args>
    bsoncxx::document::value createDocument(const T& key, const U& value, const Args&... args) {
        return bsoncxx::builder::stream::document{}
            << key << value
            << bsoncxx::builder::concatenate(createDocument(args...))
            << bsoncxx::builder::stream::finalize;
    }
    
    std::string add(mongocxx::collection collection, Request data, std::unordered_set<std::string> possible_options);
    Request convertDocumentToRequest(bsoncxx::document::view doc);
    Request findByID(mongocxx::collection collection, std::string ID);
    
    template<typename... Args>
    std::vector<Request> findManyByMultipleParameters(mongocxx::collection collection, const Args&... args) {
        mongocxx::cursor cursor = collection.find(createDocument(args...));
        std::vector<Request> result;
        for (auto doc : cursor) {
            result.push_back(convertDocumentToRequest(doc));
        }
        return result;
    }

    template<typename... Args>
    void updateByID(mongocxx::collection collection, std::string ID, const Args&... args) {
        collection.update_one(bsoncxx::builder::stream::document{} 
                            << "_id" << bsoncxx::oid{bsoncxx::stdx::string_view{ID}}
                            << bsoncxx::builder::stream::finalize,

                            bsoncxx::builder::stream::document{}
                            << "$set"
                            << createDocument(args...)
                            << bsoncxx::builder::stream::finalize);
    }
};