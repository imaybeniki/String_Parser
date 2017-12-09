#pragma once
#include <string>
#include <vector>
#include <mutex>
#include "../../datastore/includes/string_data.h"
#include "../../datastore/includes/data_store_file.h"
#include "../includes/string_database.h"



String_Database::String_Database(void) {
}

String_Database::~String_Database(void) {
}

void String_Database::add(std::string& myString) {

	String_Data Value;
	Value= new String_Data(myString);
	for(int i=0;i<myStrings.size();i++){
		if(myStrings[i].operator ==(Value)){
			myStrings[i].increment();
			break;
		}


	}
	myStrings.push_back(Value);


}

int String_Database::getCount(std::string& myString) {
	for(int i=0;i<myStrings.size();i++){
		if(myStrings[i].operator ==(myString)){
			return myStrings[i].getCount();
		}
	}
	return 0;
}

void String_Database::clear() {
	myStrings.clear();
}

bool String_Database::load(DataStore* myDataStore) {
	if(myDataStore==0){
		return false;
	}
	myDataStore->load(myStrings);
	return true;


}

bool String_Database::save(DataStore* myDataStore) {
	if(myDataStore==0){
		return false;
	}
	myDataStore->save(myStrings);

}
