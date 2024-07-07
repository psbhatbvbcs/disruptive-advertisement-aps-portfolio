#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

struct Ad {
    string id;
    int weight;
    int positiveScore;
    chrono::system_clock::time_point lastSeen;
};

string selectAd(const vector<Ad>& ads) {
    vector<pair<double, string>> weightedAds;
    for (const auto& ad : ads) {
        auto now = chrono::system_clock::now();
        chrono::duration<double> secondsSinceLastSeen = now - ad.lastSeen;
        double timeWeight = 1.0 - (secondsSinceLastSeen.count() / 3600.0);
        weightedAds.push_back(make_pair((double)ad.weight + ad.positiveScore * timeWeight, ad.id));
    }

    double totalWeight = 0.0;
    for (const auto& [weight, _] : weightedAds) {
        totalWeight += weight;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, totalWeight);
    double randomValue = dist(gen);

    double cumulativeWeight = 0.0;
    for (const auto& [weight, adId] : weightedAds) {
        cumulativeWeight += weight;
        if (randomValue < cumulativeWeight) {
            return adId;
        }
    }
    return "";
}

void updateAdScores(vector<Ad>& ads, const string& adId, bool positiveFeedback) {
    for (auto& ad : ads) {
        if (ad.id == adId) {
            if (positiveFeedback) {
                ad.positiveScore++;
                ad.lastSeen = chrono::system_clock::now();
            }
            break;
        }
    }
}

int main() {
    vector<Ad> ads = {
        {"ad1", 5, 0, chrono::system_clock::now()},
        {"ad2", 3, 0, chrono::system_clock::now()},
        {"ad3", 2, 0, chrono::system_clock::now()}
    };

    updateAdScores(ads, "ad1", true); // Positive reaction to "ad1"
    updateAdScores(ads, "ad2", false); // No reaction to "ad2"

    string selectedAd = selectAd(ads);
    cout << "Selected Ad: " << selectedAd << endl;

    return 0;
}