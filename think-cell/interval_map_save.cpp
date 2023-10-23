#include "bits/stdc++.h"
using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int inf = 1000;
map<int, int> test_map;

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
	{
		for (int i = -inf; i <= inf; i++) {
			test_map[i] = val;
		}
	}

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
		
		auto prev_m_map = m_map;
		V last_value = (*this)[keyBegin];
		V value_before = get_just_before_value(keyBegin);
		if (val != value_before) {
			m_map[keyBegin] = val;
		}
		else if (val == value_before && m_map.find(keyBegin) != m_map.end()) {
			m_map.erase(keyBegin);
		}
		
		auto it = m_map.upper_bound(keyBegin);
		auto jt = it;
		while (jt != m_map.end() && jt->first < keyEnd) {
			last_value = jt->second;
			jt++;
		}
		m_map.erase(it, jt);
		
		if (m_map.find(keyEnd) == m_map.end()) {
			int end_val = m_map.lower_bound(keyEnd) == m_map.end() ? m_valBegin : last_value;
			if (end_val != (*this)[keyBegin]) {
				m_map[keyEnd] = end_val;
			}
		}
		
		if (m_map.find(keyEnd) != m_map.end() && (*this)[keyEnd] == (*this)[keyBegin]) {
			m_map.erase(keyEnd);
		}
		
		// V val_before = get_just_before_value(keyBegin);
		// if (val_before == val && m_map.find(keyBegin) != m_map.end()) {
		// 	m_map.erase(keyBegin);
		// }
		// last_value = (*this)[keyBegin - 1];
		// it = m_map.lower_bound(keyBegin);
		// jt = it;
		// if (jt != m_map.end() && last_value == jt->second) {
		// 	jt++;
		// }
		// m_map.erase(it, jt);
		for (int i = keyBegin; i < keyEnd; i++) {
			test_map[i] = val;
		}
		bool ok = true;
		for (int i = -inf; i <= inf; i++) {
			ok &= test_map[i] == (*this)[i];
		}
		last_value = m_valBegin;
		for (auto &p : m_map) {
			ok &= last_value != p.second;
			if (last_value == p.second) {
				dbg("same_value");
			}
			last_value = p.second;
		}
		if (!m_map.empty()) {
			ok &= m_map.rbegin()->second == m_valBegin;
			if (m_map.rbegin()->second != m_valBegin) {
				dbg("wrong value at end");
			}
		}
		if (!ok) {
			dbg(prev_m_map);
			dbg(keyBegin, keyEnd, val, m_map);
			for (int i = -inf; i <= inf; i++) {
				if (test_map[i] != (*this)[i]) {
					cout << i << " " << test_map[i] << " " << (*this)[i] << endl;
				}
			}
			exit(0);
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

int main() {
	interval_map<int, int> mp(0);
	// mp.assign(0, 10, 1);
	// mp.assign(10, 20, 2);
	// mp.assign(20, 30, 3);
	// mp.assign(5, 15, 4);
	// mp.assign(17, 19, 4);
	// mp.assign(19, 20, 5);
	// mp.assign(35, 50, 6);
	// mp.assign(0, 50, 7);
	// mp.assign(0, 50, 0);
	int iterations = 1e6;
	for (int _ = 1; _ <= iterations; _++) {
		// dbg(_);
		if (_ % (iterations / 10) == 0) {
			dbg(_);
		}
		// dbg(_);
		int x = rand(-inf, inf - 1);
		int y = rand(x + 1, inf);
		int val = rand(-inf, inf);
		mp.assign(x, y, val);
	}
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
m_map = [(0, 0)]
*/