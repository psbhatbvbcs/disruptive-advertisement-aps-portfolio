/*
Here, we are finding similar users based on their preferences, and then recommending items that the target user might like based on those similar users.
The similarity between users is determined by calculating the Euclidean distance between their preference vectors.

A more sophisticated approach might involve using collaborative filtering techniques from machine learning techniques.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct User
{
    int id;
    unordered_map<string, double> preferences;
};

vector<int> findSimilarUsers(const T &target, const vector<T> &items)
{
    vector<pair<double, int>> similarityScores;
    for (const auto &item : items)
    {
        if (item.id != target.id)
        {
            double similarity = 0.0;
            for (const auto &pref : target.preferences)
            {
                if (item.preferences.count(pref.first))
                {
                    similarity += abs(target.preferences[pref.first] - item.preferences[pref.first]);
                }
            }
            similarityScores.push_back(make_pair(similarity, item.id));
        }
    }
    sort(similarityScores.begin(), similarityScores.end());

    vector<int> similarItems;
    for (size_t i = 0; i < similarityScores.size(); ++i)
    {
        similarItems.push_back(similarityScores[i].second);
    }
    return similarItems;
}

vector<string> recommendItems(const T &target, const vector<T> &items, int numRecommendations)
{
    vector<int> similarItems = findSimilarUsers(target, items);
    vector<string> recommendedItems;
    for (size_t i = 0; i < numRecommendations && i < similarItems.size(); ++i)
    {
        int neighborId = similarItems[i];
        for (const auto &item : items[neighborId].preferences)
        {
            if (target.preferences.count(item.first) == 0)
            {
                recommendedItems.push_back(item.first);
                if (recommendedItems.size() == numRecommendations)
                {
                    break;
                }
            }
        }
    }
    return recommendedItems;
}
