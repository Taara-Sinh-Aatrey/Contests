#include "bits/stdc++.h"
using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		auto get_just_before_value = [&] (int query_key) {
			auto it = m_map.lower_bound(query_key);
			V val_before = it == m_map.begin() ? m_valBegin : prev(it)->second;
			return val_before;
		};
		
		V last_value = (*this)[keyBegin];
		
		// update keyBegin
		V value_before = get_just_before_value(keyBegin);
		if (val != value_before) {
			m_map.insert({keyBegin, val});
		}
		else if (val == value_before && m_map.find(keyBegin) != m_map.end()) {
			m_map.erase(keyBegin);
		}
		
		// delete intervals lying inside [keyBegin, keyEnd)
		auto it = m_map.upper_bound(keyBegin);
		auto jt = it;
		while (jt != m_map.end() && jt->first < keyEnd) {
			last_value = jt->second;
			jt++;
		}
		m_map.erase(it, jt);
		
		// update keyEnd
		if (m_map.find(keyEnd) == m_map.end()) {
			int end_val = m_map.lower_bound(keyEnd) == m_map.end() ? m_valBegin : last_value;
			if (end_val != (*this)[keyBegin]) {
				m_map.insert({keyEnd, end_val});
			}
		}
		if (m_map.find(keyEnd) != m_map.end() && (*this)[keyEnd] == (*this)[keyBegin]) {
			m_map.erase(keyEnd);
		}
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main() {
	interval_map<int, int> mp(0);
	mp.assign(0, 10, 1);
	mp.assign(10, 20, 2);
	mp.assign(20, 30, 3);
	mp.assign(5, 15, 4);
	mp.assign(17, 19, 4);
	mp.assign(19, 20, 5);
	mp.assign(35, 50, 6);
	mp.assign(0, 50, 7);
	mp.assign(0, 50, 0);
}

/*
m_map = [(0, 1), (10, 0)]
m_map = [(0, 1), (10, 2), (20, 0)]
m_map = [(0, 1), (10, 2), (20, 3), (30, 0)]
m_map = [(0, 1), (5, 4), (15, 2), (20, 3), (30, 0)]
m_map = [(0, 1), (5, 4), (15, 2), (17, 4), (19, 2), (20, 3), (30, 0)]
m_map = [(0, 1), (5, 4), (15, 2), (17, 4), (19, 5), (20, 3), (30, 0)]
m_map = [(0, 1), (5, 4), (15, 2), (17, 4), (19, 5), (20, 3), (30, 0), (35, 6), (50, 0)]
m_map = [(0, 7), (50, 0)]
m_map = []
*/