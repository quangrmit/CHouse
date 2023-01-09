#include "Database.h"
#include "CLI.h"
#include "utils.h"

// testing only 
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

using namespace std;
//
int main() {
    // main code
    Database * data = Database::getInstance();
    CLI* session = new CLI();
    data->updateFile();
    delete data, session;
    
  
}


