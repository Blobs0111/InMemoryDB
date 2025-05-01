#include <iostream>
#include "InMemoryDB.h"

using namespace std;

int main() {
	InMemoryDB inmemoryDB;

	try {
		// should return -1, because A doesn’t exist in the DB yet
		cout << inmemoryDB.get("A") << endl;

		// should throw an error because a transaction is not in progress
		inmemoryDB.put("A", 5);

	} catch (const exception& e) {
		cerr << e.what() << endl;
    	}

	inmemoryDB.begin_transaction();
    	inmemoryDB.put("A", 5);
    
	// should return -1, because updates to A are not committed yet
    	cout << inmemoryDB.get("A") << endl;

	inmemoryDB.put("A", 6);
    	inmemoryDB.commit();

    	// should return 6, that was the last value of A to be committed
	cout << inmemoryDB.get("A") << endl;

    	try {
        	// throws an error, because there is no open transaction
    		inmemoryDB.commit();

	} catch (const exception& e) {
        	cerr << e.what() << endl;
    	}

    	try {
        	// throws an error because there is no ongoing transaction
		inmemoryDB.rollback();

    	} catch (const exception& e) {
        	cerr << e.what() << endl;
    	}

	// should return -1 because B does not exist in the database
    	cout << inmemoryDB.get("B") << endl;
    	
	inmemoryDB.begin_transaction();
    	inmemoryDB.put("B", 10);
    	inmemoryDB.rollback();

	// should return -1 because changes to B were rolled back
    	cout << inmemoryDB.get("B") << endl;

   	return 0;
}

