/*
Here each data point can be taken as a user's details and his preferred topics.
For example, if a user has liked articles on topics Sports, Beauty, and Gaming, the data point for that user
would be {1, {1.0, 2.0, 3.0}} and these can be either keys for the topics, or the degree of preference.

So, the k-means algorithm can be used to cluster users based on their preferred topics.

The k-means algorithm works as follows:

1. Initialize k centroids (representative data points) randomly.
2. Assign each data point to the closest centroid.
3. Update the centroids by taking the mean of all data points assigned to each cluster.
4. Repeat steps 2 and 3 until convergence (i.e., when the centroids do not change).

The algorithm is sensitive to the initial placement of centroids and can get stuck in local minima.
To overcome this, the algorithm can be run multiple times with different initial centroids and
the final result is the best possible clustering.

This implementation assumes that the data points are represented as a vector of features
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <limits>

using namespace std;

struct DataPoint
{
    int id;
    vector<double> features;
};

double euclideanDistance(const vector<double> &point1, const vector<double> &point2)
{
    double distance = 0.0;
    for (size_t i = 0; i < point1.size(); ++i)
    {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

vector<vector<DataPoint>> kMeansClustering(vector<DataPoint> &dataPoints, int k, int maxIterations)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, dataPoints.size() - 1);

    // Initialize centroids randomly
    vector<vector<double>> centroids(k, vector<double>(dataPoints[0].features.size()));
    for (size_t i = 0; i < k; ++i)
    {
        int randomIndex = dist(gen);
        centroids[i] = dataPoints[randomIndex].features;
    }

    vector<vector<DataPoint>> clusters(k);
    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        clusters.assign(k, vector<DataPoint>());
        for (auto &point : dataPoints)
        {
            double minDistance = numeric_limits<double>::max();
            int nearestCluster = 0;
            for (size_t i = 0; i < centroids.size(); ++i)
            {
                double distance = euclideanDistance(point.features, centroids[i]);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    nearestCluster = i;
                }
            }
            clusters[nearestCluster].push_back(point);
        }

        for (size_t i = 0; i < k; ++i)
        {
            if (!clusters[i].empty())
            {
                centroids[i] = clusters[i][0].features;
            }
        }
    }
    return clusters;
}

int main()
{
    vector<DataPoint> dataPoints = {
        {1, {1.0, 2.0, 3.0}},
        {2, {2.0, 3.0, 1.0}},
        {3, {3.0, 1.0, 2.0}},
        {4, {1.0, 3.0, 1.0}}};

    int k = 2;
    int maxIterations = 10;

    vector<vector<DataPoint>> clusters = kMeansClustering(dataPoints, k, maxIterations);

    for (size_t i = 0; i < clusters.size(); ++i)
    {
        cout << "Cluster " << i + 1 << ":" << endl;
        for (const auto &point : clusters[i])
        {
            cout << "Data Point " << point.id << " ";
        }
        cout << endl;
    }

    return 0;
}