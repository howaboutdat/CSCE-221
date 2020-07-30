#ifndef Collection_H
#define Collection_H

#include <iostream>
using namespace std;
//F1 size, F2 color
enum class Sort_choice { bubble_sort, insertion_sort, selection_sort};

template <typename Obj, typename F1, typename F2>
class Collection {
	public:
	// default constructor
	Collection(){
		size, capacity = 0;
		array = nullptr;
	} 
	
	// parameterized constructor
	Collection(int cap){
		capacity = cap;
		size = 0;
		array = new Obj[capacity];
	}
	
	// Copy constructor
	Collection(const Collection &C2){
		// set properties of current collection to C2
		size = C2.size;
		capacity = C2.capacity;
		array = new Obj[capacity];
		for(int i = 0; i < size; i++){
			array[i] = C2.array[i];
		}
	}

	// Copy assignment
	Collection& operator=(const Collection& C2){
		// set properties of current collection to C2 and return current collection
		if(this != &C2){
            if(array != nullptr)
                delete []array;
            size = C2.size;
            capacity = C2.capacity;
            array = new Obj[capacity];
            for(int i = 0; i < size; i++){
                array[i] = C2.array[i];
               }
           }
           return *this;
	}
	
	// Destructor
	~Collection(){
		// call make_empty function to clear collection
		make_empty();
	}

	// move constructor
	Collection(Collection&& C2):array(C2.array){
		// set current collection to c2's properties and clear c2
		size = C2.size;
		capacity = C2.capacity;
		array = C2.array;
		C2.size = 0;
		C2.capacity = 0;
		C2.array = nullptr;
	} 
	// move assignment
	Collection& operator=(Collection&& C2){
		// set current collection to c2's properties and clear c2
		if(this != &C2){
		if(array != nullptr)
			delete []array;
			size = C2.size;
			capacity = C2.capacity;
			array = C2.array;
			C2.size = 0;
			C2.capacity = 0;
			C2.array = 0;
		}
		return *this;
	}  
	
	// insert item function
	void insert_item(const Obj& ob){
		// add stress ball to current array, resize if reached capacity
			if(size == capacity){resize();}
			array[size] = ob;
			size++;
	}
	
	// contains function
	bool contains(const Obj& ob) const{
		//check if an objective exists in a collection
		bool exist;
		for (int i = 0; i < size;i++){
			if(array[i]== ob)
				exist = true;
		}
		return exist;
	}
	
	// remove_any_item function
	Obj remove_any_item(){
		// generate random index within array's range and remove it
		// throw exception if size =0 
		if(size == 0){throw exception();}
		int position= rand() % (size-1);
		for (int i = position; i < size-1;i++){
			array[i] = array[i+1];
		}
		// reduce size of Objective array
		size--;
	}
	
	// remove_this_item function
	void remove_this_item(const Obj& ob){
		// remove desired objective// throw exception if size = 0
		if(size == 0){throw exception();}
		for (int i = 0; i < size;i++){
			if(array[i] == ob){
			array[i] = array[i+1];
			size--;
			} 
		}
	}

	// make empty function
	void make_empty(){
		// empty array and set it to nullptr, set size and capacity to 0
		delete []array;
		size = 0;
		capacity = 0;
		array = nullptr;
	}
	
	//  is empty function
	bool is_empty() const{
		// return true if size is 0
		if (size == 0){ 
			return true;
		}
		else
			return false;
	}
	
	// total_items function
	int total_items() const{
		return size;
		// return size of array
	}
	
	// total_items size function
	int total_items(F1 s) const{
		// loop through array and count how many items of the same size
		int total=0;
		for(int i = 0; i < size; i++){
			if(array[i].get_size() == s){
				total++;
			}
		}
		return total;
	}
	
	//total_items color function
	int total_items(F2 t) const{
		// loop through array and count how many items of the same color
		int total=0;
		for(int i = 0; i < size; i++){
			if(array[i].get_color() == t){
				total++;
			}
		}
		return total;
	}
	
	// print items function
	void print_items() const{
		// loop and cout items of array
		for(int i = 0; i < size;i++){
			cout << array[i] << endl;
		}
		
	}
	
	// [] operator
	Obj& operator[](int i){
		return array[i];
	}
	
	// [] operator to access const stress ball
	const Obj& operator[](int i) const{
		return array[i];
	}
	
	private:
	Obj *array; //pointer to dynamically allocated memory
	int size; //logical size of array - the number of elements in use
	int capacity; //physical size of array
	// resize function
	void resize(){
		// set capacity to 1 if it's empty
		   if(capacity == 0){capacity = 1;}
		   capacity = 2*capacity; // double size if capacity is reached
           Obj *temp = new Obj[capacity];
           for(int i = 0; i < size; i++)
               temp[i] = array[i];
           delete []array;
           array = temp;
	}
};	
// input operator


template<typename Obj, typename F1, typename F2>
//output stream
ostream& operator <<(ostream& os, const Collection<Obj,F1,F2> &c){
	// output stress ball array
	 for(int i = 0; i < c.total_items();i++){
		 os << i << ". ";
		 os << c[i] << endl;
	 }
}

template<typename Obj, typename F1, typename F2>
// make union union function
Collection<Obj,F1,F2> make_union(const Collection<Obj,F1,F2> &c1, const Collection<Obj,F1,F2> &c2){
	// call copy constructor to copy c1 to c3
	Collection<Obj,F1,F2> c3(c1);
	// use for loop to insert elements from c2 to c3
	for(int i = 0; i < c2.total_items();i++){
		c3.insert_item(c2[i]);
	}
	return c3;
}

// swap function
template<typename Obj, typename F1, typename F2>
void swap(const Collection<Obj,F1,F2> &c1, const Collection<Obj,F1,F2> &c2){
	// move c1 to temp collection, c2 to c1, and temp to c2 and make empty temp collection
	Collection <Obj,F1,F2> temp= move(c1);
	c1 = move(c2);
	c2 = move(temp);
	temp.make_empty();
}

// sort by size function
template<typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj,F1,F2> &c, Sort_choice sort){
	// sort cases
	switch(sort){
		// bubble sort
		case Sort_choice::bubble_sort:
		{ 	// swapping biggest stress ball's size till the end
			for (int i = 0; i < c.total_items()-1; i++)   {   
			for (int j = 0; j < c.total_items()-i-1; j++)  {
				if (c[j].get_size() > c[j+1].get_size())  
				swap(c[j], c[j+1]);
		}
		} 
		break;
		}
		// insertion sort
		case Sort_choice::insertion_sort:
		{ 	// set a temporary stress ball, shifting it to the front of sorted subarray.
			Obj temp; 
			int j;
			for (int i = 1; i < c.total_items(); i++) 
				{  
					temp = c[i];  
					j = i - 1;  
  
				while (j >= 0 && c[j].get_size() > temp.get_size()) 
				{  
					c[j + 1] = c[j];  
					j = j - 1;  
				}  
				c[j + 1] = temp;  
			}
		break;
		}
		
		// selection sort
		case Sort_choice::selection_sort:
		{	  int i, j, min_idx;  
  
		for (i = 0; i < c.total_items()-1; i++)  
		{  
        // find min element in array, swap the found minimum element with the first element
			min_idx = i;  
			for (j = i+1; j < c.total_items(); j++)  
				if (c[j].get_size() < c[min_idx].get_size())  
					min_idx = j;  
			swap(c[min_idx], c[i]);  
		}
		break;
		}
	}
}



#endif