#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isFrequencyExceeded(unordered_map<string, int>& adFrequencies,
                        string userId, string adId, int maxFrequency) {
  string key = userId + adId;

  if (adFrequencies.find(key) == adFrequencies.end()) {
    adFrequencies[key] = 1;
    return false;
  } else {
    int& frequency = adFrequencies[key]; 

    if (frequency >= maxFrequency) {
      return true;
    } else {
      frequency++;
      return false;
    }
  }
}

int main() {
  unordered_map<string, int> adFrequencies; 

  string userId = "user1";
  string adId = "ad1";
  int maxFrequency = 5;
  for (int i = 0; i < 10; ++i) {
    if (isFrequencyExceeded(adFrequencies, userId, adId, maxFrequency)) {
      cout << "Ad frequency limit exceeded!" << endl;
    } else {
      cout << "Ad can be displayed." << endl;
    }
  }

  return 0;
}