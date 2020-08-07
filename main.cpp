#include <iostream>
#include <string>
#include <fstream>
#include "ArgumentManager.h"
#include "PriorityQueue.h"

using namespace std;



int main(int argc, char* argv[]) {

	ArgumentManager am(argc, argv);
	std::string infile = am.get("input");
	std::string outfile = am.get("output");
		
	string data="",command = "", message = "", pri="";
	int num = 0;
	int numberOfMessage = 0;
	PriorityQueue obj(1000);
	


	//string infile= "input44.txt";
	

	ifstream inputFile, outputFile;

	inputFile.open(infile);
	
	


	if (inputFile) {

	 	while (!inputFile.eof()) {

						
		
			if (getline(inputFile, data)) {
				
				if (data.length() != 0) {
					int i = 0;
					while (data.at(i) != ':') {

						command += data.at(i);
						i++;

					}
					i = i + 2;
					if (command == "REPLACE" || command == "ADD" || command == "SWAP") {

						while (data.at(i) != ']') {

							if (data.at(i) != ',') {
								message += data.at(i);
							}
							i++;
						}

					}
					else if (command == "REMOVE" || command == "DECODE") {
						while (data.at(i) != ']') {
							message += data.at(i);
							i++;
						}
						if (command == "DECODE") { numberOfMessage++; }
					}
					while (data.at(i) != ')') {
						if (isdigit(data.at(i))) {
							pri += data.at(i);
						}
						i++;
					}
					num = stoi(pri);
					obj.enqueue(command, num, message);
					obj.numberOfMessage(numberOfMessage);


					data = "";
					command = "";
					message = "";
					pri = "";
				}
			}
			
		}
	}
	
	obj.sort();
	//obj.print();
	obj.startDecoding(outfile);
	

	inputFile.close();
	




//system("pause");
	return 0;

}
