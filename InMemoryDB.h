#include <unordered_map>
#include <string>
#include <stdexcept>

using namespace std;

class InMemoryDB {

private:
	unordered_map<string, int> db;
	unordered_map<string, int> transaction_db;
	bool in_transaction = false;

public:
	InMemoryDB();
	int get(const string& key);
	void put(const string& key, int val);
	void begin_transaction();
	void commit();
	void rollback();
};

