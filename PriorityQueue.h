#include <iostream>

//using namespace std;

class Queue {
private: //private members can only be accessed in the class
	int size;
	bool compact(void);


protected: // protected members can ba accessed in derived classes
	string* messageA;		// pointer to first element of array
	int head;			// used for removing an element of array
	int tail;			  // user for adding an element into queue
	
						// counter could have been global, but using static allows to : 
						// declare it in the class where it's used (readability) & control it's access (encapsulation)
public: // public members can be accessed by all functions
	Queue(void) {		//constructor with no parameters
		head = 0;
		tail = 0;
		size = 10;
		messageA = new string[size];	// create an array in the heap
		
	}
	Queue(int s) {			// overloaded constructor with one parameter
		head = 0;
		tail = 0;
		size = s;
		messageA = new string[size]; // same as above, create heap object of type : array of int
		
	}
	
	void enqueue(string message) { // add element at the end of queue
		if (tail < size) { messageA[tail] = message; tail++; }
		else if (compact()) { messageA[tail] = message; tail++; }
	}
	
	void dequeue(void) { // return and remove 1st element from queue
		if (head < tail) head++;
		
	}
	void print(string outFileName, bool toPrint) {
		ofstream outfile;
		outfile.open(outFileName, ios::app);

		if (!outfile) { return; }

		else {
			if (head < tail && toPrint) {



				outfile<< messageA[head] << endl;

			}
			

		}
		outfile.close();
	}
	string peek() {
		string temp = "";
		if (head < tail) {

			return messageA[head];
		}
		else
			return "";
	}
	string replace(string data) {//replace function

		
		
		string temp = "";
		unsigned int i = 0;
		
			
			temp = peek();
			
			for (unsigned int j = 0; j < temp.length(); j++) {

				if (temp.at(j) == data.at(i)) {
					temp.at(j) = data.at(i + 1); }
			}
			//messageA[i] = temp; 
		
		
		return temp;
	}
	string add(string data) {
		
		string temp; unsigned int i = 0;
		
			temp = peek();;


			for (unsigned int j = 0; j < temp.length(); j++) {

				if (temp.at(j) == data.at(i)) {

					temp.insert(j+1,1,data.at(i + 1)) ;
				}
			}//messageA[i] = temp;
		
		
		return temp;
	}
	string remove(string data) {

		string temp = "", temp2 = ""; unsigned int i = 0; int j =0;

					
			temp = peek();;

	

				while (j <temp.length()) {
					
					if (temp.at(j) != data.at(i)) {
						temp2 += temp.at(j);
					}
					j++;
					
				}
				
			//messageA[i] = temp2; 
		return temp2;
	}

	string swap(string data) {

		string temp; unsigned int i = 0;
		
			temp = peek();;


			for (unsigned int j = 0; j < temp.length(); j++) {

				if (temp.at(j) == data.at(i)) {

					temp.at(j) = data.at(i + 1);
				}
				else if (temp.at(j) == data.at(i + 1)) {

					temp.at(j) = data.at(i);
				}
			}//messageA[i] = temp;
		
	
		return temp;
	}
	virtual ~Queue(void) { //destructor
		
		messageA = NULL;
		delete messageA;// must use "delete [] buffer;" if buffer points to an array of objects, (instead of array of int)
		
	}
	
	

};
bool Queue::compact(void) { //compact function implementation, separate from specification ()
	if (head == 0) {
		cout << "Error: Queue overflow" << endl;
		return false;
	}
	else {
		for (int i = 0; i < tail - head; i++)
		{
			messageA[i] = messageA[i + head];
		}
		tail = tail - head;
		head = 0;
		return true;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PriorityQueue
{
private:
	
	int size;
	int numOfmes;
	
protected: // protected members can ba accessed in derived classes
	int* prioA;
	string* commandA;// pointer to first element of array
	string* messageA;

	int head;			// used for removing an element of array
	int tail;			  // user for adding an element into queue
	static int counter;
public:
	PriorityQueue(void) {		//constructor with no parameters
		head = 0;
		tail = 0;
		numOfmes = 0;
		size = 10;
		prioA = new int[size];	// create an array in the heap
		commandA = new string[size];	// create an array in the heap
		messageA = new string[size];	// create an array in the heap
			
	}
	PriorityQueue(int n) {			// overloaded constructor with one parameter
		head = 0;
		tail = 0;
		numOfmes = 0;
		size = n;
		prioA = new int[size];
		commandA = new string[size];        // same as above, create heap object of type : array of int
		messageA = new string[size];        // same as above, create heap object of type : array of int
		
	}
	virtual ~PriorityQueue(void) { //destructor
		prioA = NULL;
		commandA = NULL;
		messageA = NULL;
		delete commandA;
		delete prioA;	// must use "delete [] buffer;" if buffer points to an array of objects, (instead of array of int)
		delete messageA;	// must use "delete [] buffer;" if buffer points to an array of objects, (instead of array of int)
				
	}
	
	void enqueue(string com, int pri, string mes) {                                       // add element at the end of queue
		int temp = tail;
		
		if (temp < size) {
			
			commandA[temp++] = com;
			temp = tail;
			prioA[temp++] = pri; 

			temp = tail;
			messageA[temp++] = mes;
			
			tail++;
		}
		else if (compact()) {

			commandA[temp++] = com;
			temp = tail;
			prioA[tail++] = pri;
			temp = tail;
			messageA[temp++] = mes;
			tail++;
		}
		
	}


	void dequeue(void) {       // remove 1st element from queue
		if (head < tail) {

			prioA[head++];
			commandA[head++];
			messageA[head++];

		}
		
	}

	void sort() {    //bubble sort to sort the command array
		int i, j, flag;

		for (i = 0; i < tail - 1; i++) {
			flag = 0;
			for (j = 0; j < tail - i - 1; j++) {
				if (prioA[j] > prioA[j + 1] ) {
					swap(&prioA[j], &prioA[j + 1]);
					swap(&commandA[j],&commandA[j+1]);
					swap(&messageA[j],&messageA[j+1]);
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}

	}

	template <typename T> 

	void swap(T* x, T* y) {
		T temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}
	void startDecoding(string outFileName) {

		Queue obj(numOfmes);
		bool ready = false, toPrint =false;
		string temp = "";
		
		for (int i = 0; i < tail; i++) {
			
			
			if (commandA[i] == "DECODE") {
				temp = messageA[i];
				obj.enqueue(temp);
				
				ready = true;
			}
			
			else if (commandA[i] == "REPLACE") {
				if (ready) {
					temp = obj.replace(messageA[i]);
					obj.dequeue();	obj.enqueue(temp);
				}
			}
			else if (commandA[i] == "ADD") {
				if (ready) {
					temp = obj.add(messageA[i]); obj.dequeue(); obj.enqueue(temp);
				}
			}
			else if (commandA[i] == "REMOVE") {
				if (ready) {
					temp = obj.remove(messageA[i]);
					obj.dequeue();
					obj.enqueue(temp);
				}
			}
			else if (commandA[i] == "SWAP") {
				if (ready) {
					temp = obj.swap(messageA[i]); obj.dequeue(); obj.enqueue(temp);
				}
			}
			else if (commandA[i] == "PRINT") {
				toPrint = true; obj.print(outFileName, toPrint); obj.dequeue();
				temp = obj.peek(); 
				if (temp.length() == 0) 
				{ ready = false; }
			}
			
			
		}
		if(!toPrint){obj.print(outFileName, toPrint); }

	}
	int numberOfMessage(int num) { numOfmes = num; return numOfmes; };
	
	void print() {
		if (tail == 0) { cout << " queue is empty \n"; }

		else {

			int temp = head;
			while (temp != tail) {
				cout << prioA[temp] << " "<< commandA[temp]<< " " <<messageA[temp]<< endl;
				temp++;

			}
		}
		cout << endl;
	}
	
private:
	bool compact(void);

};
bool PriorityQueue::compact(void) { //compact function implementation, separate from specification ()
	if (head == 0) {
		cout << "Error: Queue overflow" << endl;
		return false;
	}
	else {
		for (int i = 0; i < tail - head; i++)
		{
			prioA[i] = prioA[i + head];
			commandA[i] = commandA[i + head];
		}
		tail = tail - head;
		head = 0;
		return true;
	}
}
