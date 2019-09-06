#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int paging(int cacheSize, string cities[], int citiesSize) {
	int result = 0;
	vector <string> ::iterator iter;
	vector <string> cache;
	bool find;

	for (int i = 0; i < citiesSize; i++) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
		if (cacheSize > (int)cache.size()) {
			cache.push_back(cities[i]);
			result += 5;
		}
		else if (cacheSize == cache.size()) {
			if (cacheSize == 0) {
				result += 5;
			}
			else {
				find = false;
				for (iter = cache.begin(); iter != cache.end(); iter++) {
					if (*iter == cities[i]) {
						find = true;
						break;
					}
				}

				if (find) {
					result += 1;
				}
				else {
					iter = cache.begin();
					result += 5;
				}

				cache.erase(iter);
				cache.push_back(cities[i]);
			}
		}
	}

	return result;
}


//int main() {
//	int cacheSize = 3;
//	string cities[]{ "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
//
//	int cacheSize = 3;
//	string cities[] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
//
//	int cacheSize = 2;
//	string cities[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
//
//	int cacheSize = 5;
//	string cities[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
//
//	int cacheSize = 2;
//	string cities[] = { "Jeju", "Pangyo", "NewYork", "newyork" };
//
//	int cacheSize = 0;
//	string cities[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
//	int result;
//	
//	result = paging(cacheSize, cities, sizeof(cities)/sizeof(string));
//
//	cout << "실행시간" << endl;
//	cout << result << endl;
//
//}

