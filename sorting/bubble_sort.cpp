#include<iostream>
#include<vector>
 using namespace std;

void swap(int *r, int *s)
{
   int temp = *r;
   *r = *s;
   *s = temp;
   return;
} 

void bubble_sort(vector<int>& v){
int i,j,temp;
	for(i=0; i <v.size() -1; i++) {
		for(j=0; j<v.size()-1;j++) {
			if(v[j]>v[j+1]) {
			  swap(v[j],v[j+1]);			
			}

		}
	}

}

void print_vector(vector<int>& vec){
 // use iterator to access the values
 vector<int>::iterator v = vec.begin();
	cout << "values of v = [ ";
  		 while( v != vec.end()) {
    	  cout << *v << " ";
     		 v++;
  		 }
	cout << " ]"<< endl;

}

int main() {
	vector<int> vec;
	int i,size,value;

	//display the orginal size of vector
	cout<< "vector size = " << vec.size()	<<endl;
	cout << "Enter the new size for vector or Array  ";
	cin >>size;


	//push 5 values into the vector
	for(i = 0; i < size; i++){
		cin >>value;
		vec.push_back(value);
	}
	//display the extednded size of vector
	cout<< "extended vectr size = "<< vec.size() << endl;


	print_vector(vec);
  	

	bubble_sort(vec);

	print_vector(vec);
	
  	
 return 0;
}
