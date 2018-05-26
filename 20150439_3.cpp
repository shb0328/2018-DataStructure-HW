// Program 4.6:Template definition of chains
// ===============================================
// template <class T> class Chain; // forward declaration

// template <class T>
// class ChainNode {
// friend class Chain<T>;
// private:
//   T data;
//   ChainNode<T> *link;
// };

// template <class T>
// class Chain {
// public:
//   Chain() {first = 0;}; // constructor initializing first to 0
//   // Chain manipulation operations
//    .
//    .
// private:
//   ChainNode<T> *first;
// };
// ===============================================


// Program 4.10:A forward iterator for chain
// ===============================================
// class ChainIterator {
// public:
//   // typedefs required by C++ for a forward iterator omitted
  
//   // constructor
//   ChainIterator(ChainNode<T>* startNode = 0)
//     {current = startNode;}
  
//   // dereferencing operators
//   T& operator*() const {return current->data;}
//   T* operator->() const {return &current->data;}
  
//   // increment
//   ChainIterator& operator++()   // preincrement
//     {current = current->link; return *this;}
//   ChainIterator operator++(int) // postincrement
//     {
//       ChainIterator old = *this;
//       current = current->link;
//       return old;
//     }
  
//   // equality testing
//   bool operator!=(const ChainIterator right) const
//     {return current != right.current;}
//   bool operator==(const ChainIterator right) const
//     {return current == right.current;}
//   private:
//     ChainNode<T>* current;
// };
// ===============================================



#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T> class Chain;

template <class T>
class ChainNode {
friend class Chain<T>;
public:
	ChainNode(T data) {
		this->data = data;
	}
	T getData() {return data;}
	
private:
	T data;
	ChainNode<T> *link = 0;
};

template <class T>
class Chain {
public:
	Chain() {				//1
		first = 0;	
	}
	//TODO
	~Chain() { 				//2
		if(first){
			for(ChainNode<T> *ptr = first; ptr->link !=0;){
				ChainNode<T> *tmp = ptr->link;
				delete ptr;
				ptr = tmp;
			} 
		}
	}
	void prePush(ChainNode<T>* newNode){		//3
		if(first){
			ChainNode<T> *tmp = first;
			first = newNode;
			newNode->link = tmp;
		}
		else{
			first = newNode;
		}
	}
	void postPush(ChainNode<T>* newNode){		//4
		if(first){
			Back()->link = newNode;
		}
		else{
			first = newNode;
		}
	}
	ChainNode<T> * Front() {		//5
		if(first = 0)
			cout<<"빈 체인 입니다."<<endl;

		return first;
	}
	ChainNode<T> * Back() {			//6
		if(first){
			ChainNode<T> *ptr;
			for(ptr = first;ptr->link !=0;ptr = ptr->link);
			return ptr;
		}
		else {
			cout<<"빈 체인 입니다."<<endl;
			return first;
		}	
	}
	ChainNode<T> * Get(int i) {		//7
		ChainNode<T> *ptr;
		int cnt=0;
		for(ptr = first;cnt<i;cnt++)
				ptr = ptr->link;

		return ptr;
	}
	void prePop() {					//8
		if(first){
			ChainNode<T> *tmp = first->link;
			delete first;
			first = tmp;
		}
	}	
	void postPop() {				//9
		if(first){
			ChainNode<T> *tmp = Back()--;
			delete tmp->link;
			tmp->link = 0;
		}
	}
	void iPush(int i,ChainNode<T> *newNode) {				//10
		ChainNode<T> *tmp = Get(i)->link;
		Get(i)->link = newNode;
		newNode->link = tmp;
	}
	void iPop(int i) {				//11
		ChainNode<T> *tmp = Get(i)->link;
		delete Get(i-1)->link;
		Get(i-1)->link = tmp;
	}


private:
	ChainNode<T> *first;


		class ChainIterator { 			//12
		public:
			ChainIterator(ChainNode<T>* startNode = 0){
				current = startNode;
			}
			
			T& operator*() const {return current->data;}
			T* operator->() const {return &current->data;}

			ChainIterator& operator++() { 
				current = current->link; return *this;
			}
			ChainIterator operator++(int) {
				ChainIterator old = *this;
				current = current->link;
				return old;
			}
			ChainIterator& operator--() {
				for(ChainNode<T> * ptr = first;ptr = this;ptr = ptr->link)
					current = ptr;
				
				return *this;
			}
			ChainIterator operator--(int) {
				ChainIterator old = *this;
				for(ChainNode<T> * ptr = first;ptr = this;ptr = ptr->link)
					current = ptr;
				
				return old;
			}

			bool operator!=(const ChainIterator right) const {
				return current != right.current;
			}
		  	bool operator==(const ChainIterator right) const {
		  		return current == right.current;
		  	}
	 	private:
		    ChainNode<T>* current;
		};

};


//=================================================================
int main(void) {
	Chain<int> myChain;
	//1
	ChainNode<int>* c[9];
	int length = sizeof(c)/sizeof(c[0]);
	for(int i =0; i<length; ++i)
		c[i] = new ChainNode<int>(i+1);
	for(int i = 0;i<length;++i)
		myChain.postPush(c[i]);
	//2
	for(int i = 0;i<length;++i)
		cout<<myChain.Get(i)->getData()<<" ";
	//3
	myChain.prePush(0);
	//4
	//5
	//6
	//7
	//8
	//9
	//10
	//11
	//12
	//13
	//14
	//15
	//16
	//17
	return 0;
}