// sorting items from the heaviest to lightest
// by selecting the heaviest item at each time  

#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

ostream& operator<<(ostream& out, vector<int>& v)
{ 	
    for (int i = 0; i < v.size(); ++i) { 
        out << v[i]; 
        if (i != v.size() - 1) 
            out << ", "; 
    } 
  // overload the output operator to display elements of v
  return out;
}


void sort_heaviest(vector<int>& v){
  
  int heaviest= v[0];
	for(int i = 0; i < v.size();++i){
		if (v[i] >= v[i+1]){
			swap(v[i],v[i+1]);
			comparisons++;
		}
	}
	for(int i = 0; i < v.size();++i){
		if (v[i] >= v[i+1]){
			sort_heaviest(v);
			comparisons++;
		}
	}
  // implement the sorting algorithm based on video
 
}

int main()
{
 
  cout << "//////Test 2 for vector v ///////////////////////////////"<< endl;
  vector<int> v{10,9,8,7,6,5,4,3,2,1};

  cout << "initial vector v:\n";
  // use overloaded output operator to display vector's elements
  cout << v;
  // use comma to separate the vector's elements
  cout << endl;
  // call the sorting function for vector v 
  sort_heaviest(v);
  cout << "# of comparisons to sort v: " << comparisons << endl << endl;
  cout << "vector v after sorting:\n";
  cout << v;
  // use overloaded output operator to display elements of sorted vector
  // use comma to separate the vector's elements
  cout << endl;
  
  cout << "//////Test 2 for vector v1 ///////////////////////////////"<< endl;

  vector<int> v1{1,2,3,4,5,6,7,8,9,10};
  cout << "initial vector v1:\n";
  cout << v1;
  // use overloaded output operator to display vector's elements
  // use comma to separate the vector's elements
  cout << endl;
	sort_heaviest(v1);
   // call the sorting function for vector v2 
  cout << "# of comparisons to sort v1: " << comparisons << endl << endl;
  cout << "vector v1 after sorting:\n";
  cout << v1;
  // use overloaded output operator to display elements of sorted vector
  // use comma to separate the vector's elements
  cout << endl;
    
}