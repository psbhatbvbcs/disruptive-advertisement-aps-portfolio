Here each data point can be taken as a user's details and his preferred topics.

For example, if a user has liked articles on topics Sports, Beauty, and Gaming, the data point for that user
would be {1, {1.0, 2.0, 3.0}} and these can be either keys for the topics, or the *degree of preference*.

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

Here instead of the normal euclidean distance, squared euclidean distance is used.