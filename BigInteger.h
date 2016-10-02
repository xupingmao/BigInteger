#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>

#ifndef XPM_BIG_INTEGER_H
#define XPM_BIG_INTEGER_H

using namespace std;

// <array> can do the job
template<typename T>
class Array {
	private:
		T* values;
		int size;
		
	public:
		Array(int size) {
			this->size = size;
			this->values = new T[size];
			// initialize values to be 0. 
			for (int i = 0; i < size; i++) {
				values[i] = 0;
			}
		}
		
		~Array () {
			delete [] values;
		}
		
		T& operator[](int index) {
			return values[index];
		}
		
		string to_string() {
			string result;
		    for (int i = size-1; i >= 0; --i) {
		    	// skip 0 at first
		    	if (values[i] == 0 && result.length() == 0) {
		    		continue;
				}
				result += values[i] + '0';
			}
			return result;
		}
};

class BigInteger {
	
	private:
		string value;
		
		string SimpleMul(string& value, int factor);
		void LeftShift(string& value, int step);
		int GuessQuotient(string& left, string& right); 
		 
	public:
		string Add(string& value1, string& value2);
		string Sub(string& value1, string& value2);
		string Mul(string& value1, string& value2);
		string Div(string& value1, string& value2);
		int Compare(string& value1, string& value2);
		
		
		string GetValue() {
			return value;
		}
		
		BigInteger(string value) {
			this->value = value;
		}
		
		BigInteger operator+ (BigInteger& v) {
			string result = Add(value, v.value);
			return BigInteger(result);
		}
		
		BigInteger operator- (BigInteger& v) {
			string result = Sub(value, v.value);
			return BigInteger(result);
		}
		
		BigInteger operator* (BigInteger& v) {
			string result = Mul(value, v.value);
			return BigInteger(result);
		}
		
		BigInteger operator/ (BigInteger& v) {
			string result = Div(value, v.value);
			return BigInteger(result);
		}
		
		bool operator> (BigInteger& v) {
			return Compare(value, v.value) > 0;
		}
		
		bool operator>= (BigInteger& v) {
			return Compare(value, v.value) >= 0;
		}
		
		bool operator< (BigInteger& v) {
			return Compare(value, v.value) < 0; 
		}
		
		bool operator<= (BigInteger& v) {
			return Compare(value, v.value) <= 0; 
		}
		
		bool operator== (BigInteger& v) {
			return Compare(value, v.value) == 0; 
		}
};

#endif

