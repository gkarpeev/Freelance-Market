#include "DatabaseManager.h"
#include <cstdlib>

DatabaseManager::DatabaseManager():
    uri(std::getenv("MONGODB_URI")),
    client(uri),
    DB(client["app"]),
    users_collection(DB["users"]),
    orders_collection(DB["orders"]),
    proposals_collection(DB["proposals"])
    {}

mongocxx::collection DatabaseManager::getUsersCollection() {
    return users_collection;
}

mongocxx::collection DatabaseManager::getOrdersCollection() {
    return orders_collection;
}

mongocxx::collection DatabaseManager::getProposalsCollection() {
    return proposals_collection;
}

std::string DatabaseManager::add(mongocxx::collection collection, Request data, std::unordered_set<std::string> possible_options) {
    auto document = bsoncxx::builder::basic::document{};
    for (auto& option: possible_options) {
        if (data.keyIsSet(option)) {
            document.append(bsoncxx::builder::basic::kvp(option, data.get(option)));
        }
    }

    bsoncxx::document::value doc(document);
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(std::move(doc));
    std::string ID = result->inserted_id().get_oid().value.to_string();
    return ID;
}

Request DatabaseManager::convertDocumentToRequest(bsoncxx::document::view doc) {
    Request request;
    request.set("_id", doc["_id"].get_oid().value.to_string());
    for (auto el : doc) {
        if (el.type() != bsoncxx::type::k_utf8) continue;
        request.set(el.key().to_string(), el.get_utf8().value.to_string());
    }
    return request;
}

Request DatabaseManager::findByID(mongocxx::collection collection, std::string ID) {
    bsoncxx::stdx::optional<bsoncxx::document::value> result = collection.find_one(
        bsoncxx::builder::stream::document{} 
            << "_id" << bsoncxx::oid{bsoncxx::stdx::string_view{ID}}
            << bsoncxx::builder::stream::finalize);
    if (result) {
        return convertDocumentToRequest(*result);
    }
    return Request();
}
