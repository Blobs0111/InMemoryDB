#include <unordered_map>
#include <string>
#include <stdexcept>
#include "InMemoryDB.h"

using namespace std;

InMemoryDB::InMemoryDB() {
    db = unordered_map<string, int>();
    transaction_db = unordered_map<string, int>();
    in_transaction = false;
}


int InMemoryDB::get(const std::string& key) {
    if (in_transaction && transaction_db.find(key) != transaction_db.end()) {
        return transaction_db[key];
    } else if (db.find(key) != db.end()) {
        return db[key];
    }
    return -1;
}

void InMemoryDB::put(const std::string& key, int val) {
    if (!in_transaction) {
        throw runtime_error("No transaction in progress!");
    }
    transaction_db[key] = val;
}

void InMemoryDB::begin_transaction() {
    if (in_transaction) {
        throw runtime_error("Transaction already in progress!");
    }
    in_transaction = true;
    transaction_db.clear();
}

void InMemoryDB::commit() {
    if (!in_transaction) {
        throw runtime_error("No transaction in progress!");
    }
    for (const auto& transaction : transaction_db) {
        db[transaction.first] = transaction.second;
    }
    in_transaction = false;
    transaction_db.clear();
}

void InMemoryDB::rollback() {
    if (!in_transaction) {
        throw runtime_error("No transaction in progress!");
    }
    in_transaction = false;
    transaction_db.clear();
}

