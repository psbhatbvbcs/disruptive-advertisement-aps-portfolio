# Disruptive Advertisement Portfolio

<dl>
<dt>Course Name</dt>
<dd>Algorithmic Problem Solving</dd>
<dt>Course Code</dt>
<dd>23ECSE309</dd>
<dt>Name</dt>
<dd>Pranav Bhat</dd>
<dt>University</dt>
<dd>KLE Technological University, Hubballi-31</dd>
</dl>

---

> A step towards intelligent Advertisements
>
> PB

#### Note:

This page hosts:

1. [Introduction](#introduction)
2. [Why Portfolio](#why-portfolio)
3. [Objectives](#objectives)
4. [Design](#design)
   - [High-Level Design of Targeted Advertising](#high-level-design)
5. [Challenges](#challenges)
6. [To-Do](#to-do)
7. [Analysis and Code Examples](#analysis-and-code-examples)

---

### Prerequisites

- loren ipsum

---

## Introduction <a name="introduction"></a>

Disruptive advertisements, driven by sophisticated algorithms and big data analytics, reshape marketing by delivering personalized ad experiences. Tailored to individual preferences, they enhance user engagement and brand satisfaction. Companies benefit from optimized targeting, yielding higher conversion rates and ROI. These ads offer valuable insights into consumer behavior, refining marketing strategies and boosting competitiveness. Ultimately, disruptive advertisements signify a paradigm shift, aligning user satisfaction with business success, and standing as a cornerstone of modern digital marketing strategies.

[Back to Top](#disruptive-advertisement-portfolio)

## Why Portfolio <a name="why-portfolio"></a>

Creating a portfolio project for my Algorithmic Problem Solving course, focusing on implementing or simulating an ad suggestion mechanism, offers several advantages:

1. **Application of DSA Concepts**
2. **Problem-Solving Practice**
3. **Algorithm Optimization**
4. **Data Handling Skills**
5. **Interdisciplinary Application**
6. **Step to becoming a better engineer and a problem solver**
7. **Portfolio Enhancement**

[Back to Top](#disruptive-advertisement-portfolio)

## Objectives <a name="objectives"></a>

By the end of this portfolio project, I aim to achieve the following objectives:

1. **Learn New Algorithms**: Explore and implement new algorithms relevant to ad suggestion and targeting to enhance my algorithmic problem-solving skills.

2. **Learn about the process of the Ad Suggestion Process**: Understand the ad suggestion process to understand the underlying algorithms and mechanisms involved.

3. **Build of corpus of algorithms and data structures that can be used for the same**: Build a repositories of codes for numerous algorithms and structures which can be used in building an application for the same.

4. **Implement Advertiser Bidding System**: Create an application where advertisers can bid for advertisement placements, simulating a real-world bidding system.

These objectives will enable me to apply my knowledge of Algorithmic Problem Solving to develop a comprehensive ad suggestion mechanism, while also gaining practical experience in building efficient database systems and optimizing system performance.

[Back to Top](#disruptive-advertisement-portfolio)

## Design <a name="design"></a>

### High-Level Design of Targeted Advertising <a name="high-level-design"></a>

![targetted_advert_image1](https://github.com/psbhatbvbcs/disruptive-advertisement.github.io/assets/96832303/d3fb79bd-9c39-4c22-ac86-c821c9283b24)

Here's a high-level overview of the targeted advertising process, incorporating key players and technologies:

1. **Publishers:** Websites or apps that display advertisements (e.g., news sites, social media platforms).

2. **Advertisers:** Businesses that create and pay for advertisements to reach their target audience.

3. **Supply-Side Platform (SSP):** A platform that helps publishers manage and sell their ad inventory.

4. **Demand-Side Platform (DSP):** A platform that helps advertisers manage and buy ad inventory.

5. **Ad Exchange:** A marketplace where publishers and advertisers connect through SSPs and DSPs to buy and sell ad impressions in real-time.

6. **Real-Time Bidding (RTB):** An automated auction system where advertisers bid on the opportunity to show their ads to users in real-time.

**Process:**

- **Advertisers** create campaigns, targeting specific demographics, interests, and behaviors.
- **Publishers** integrate with **SSPs** to manage their ad inventory and make it available for bidding.
- **DSPs** connect with **Ad Exchanges** and receive user data and ad inventory information.
- **When a user visits a publisher's website, an RTB auction is triggered.**
- **DSPs bid on the impression based on user profile data and campaign targeting criteria.**
- **The highest bidder wins the impression and their ad is served to the user.**

**Algorithms and Data Structures:**

- **User Profiling:** Clustering (K-Means), collaborative filtering, content-based filtering (keyword matching)
- **Campaign Management:** Search algorithms, sorting algorithms, data validation
- **Bidding and Auction:** Auction algorithms (first-price, second-price), machine learning for bid optimization
- **Ad Serving and Tracking:** Hash tables, queueing algorithms, data logging
- **Performance Analysis and Optimization:** Machine learning, A/B testing

[Back to Top](#disruptive-advertisement-portfolio)

## Challenges <a name="challenges"></a>

This project will present some interesting challenges:

- **Data Scalability:** Handling large volumes of user data and ad inventory efficiently.
- **Real-time Processing:** Processing bids and serving ads in real-time while maintaining low latency.
- **Privacy and Security:** Ensuring user data privacy and protection from fraudulent activity.
- **Algorithm Optimization:** Finding the most efficient algorithms for user profiling, ad targeting, and bidding.
- **User Experience:** Balancing personalized advertising with user privacy and a positive experience.

[Back to Top](#disruptive-advertisement-portfolio)

## To-Do <a name="to-do"></a>

Here's a list of tasks I plan to tackle for this portfolio project:

- **Research and Choose Algorithms:** Explore different algorithms from the course syllabus (and beyond) to implement key functionalities.
- **Research Data Structures:** Research appropriate data structures to efficiently store user profiles, campaigns, ads, bids, and performance data.
- **Evaluate and Analyze Results:** Measure the performance of the system using various metrics, identify areas for improvement, and reflect on the algorithms and design choices.

[Back to Top](#disruptive-advertisement-portfolio)

## Analysis and Code Examples <a name="analysis-and-code-examples"></a>

### _IMPORTANT:_ Please visit each folder linked below, to check on the analysis for each usecase and functionality. Explained in detail in readme files for each folder.

### Analysis and Preface

- With the advent of new type of databases and generative AI recently, a paradigm shift can be seen.
- New algorithms, data structures and techniques have developed to aid in analysis and prediction in various types of usecases.
- A shift from Machine learning algorithms to analyse and predict may see a shift to use AI based models for better results. 
- Databases like Vector databases have gained popularity. These help in storing vector embeddings and fast retrieval of it.
- These databases can be used to store details about a user's preference, ad details like their price, their metadata and other details.
- Vector databases are designed in such a way that filtering similar objects to a particular query is quicker than traditional databases.
- Algorithms like random projection, local-sensitive hashing, etc. are used for creation and updation of vectors. Filtering using similarity techniques (co-sine similarity, euclidean distance) are used.
- More complex user interaction patterns can be deduced through Generative AI through techniques like reinforcement learning. Each successful conversion is a +, and each fail is a -. 
- One important thing which can be observed in recent times is, storage is of a very low concern in large industries. The profit made from the techniques and methods used outweighs the limitations and price of storage available.
  
*Vector_Database*
| ![vector_db](https://github.com/psbhatbvbcs/disruptive-advertisement.github.io/assets/96832303/6973b388-07b3-4b21-b87d-70a5fe16e475) | 
|:--:| 
| *Vector Database* |

## 1. User Interest Clustering

   - Divide users into segments/groups based on their preference. Preference gathered to their activity on platforms like search engines, social media apps, and 3rd party softwares.
   - **Algorithm:**  K-Means Clustering
   - **Data Structure:**  Hash Tables (for efficient user lookups)
   - **Time Complexity:**
     - Clustering: O(n*k*m*i) - n = number of data points, k = number of clusters, m = number of features, i = number of iterations
     - Finding Nearest Cluster: O(k*m)
   - **Space Complexity:** O(n*m + k*m) - n = number of data points, k = number of clusters, m = number of features
   - [Link to code](codes/User_Interest_Clustering)

## 2. Collaborative Filtering with User based recommendations

   - Now that we have divided users based on different preferences, demographics, geography from above, still the users may have different likings of products in the same category. We bring in collaborative filtering which helps find similar users to a targetted user. This idea was taken from this video:
   - Resources:
      1. [Targetted Ads: ](https://youtu.be/yVwKQqbMw-c?t=192)
      1. [Collaborative Filtering](https://developers.google.com/machine-learning/recommendation/collaborative/basics)
   - **Algorithm:** User-Based Collaborative Filtering
   - **Data Structure:** Hash Table or Sparse Matrix (for storing user ratings efficiently)
   - **Time Complexity:**
     - Calculating Similarity: O(m) - m = number of common items rated
     - Recommending: O(n*m) - n = number of users, m = number of items
   - **Space Complexity:** O(n*m) - n = number of users, m = number of items
   - [Link to code](codes/Collaborative_Filtering)

## 3. Content based filtering with keyword matching

   - Now that we know users similar to one another based on another likings, it's time to start recommending ads. When a user profile is created, usually his preferences and interests are stored as keywords. The ads created by agencies also have few keywords attached to it. Now to suggest an ad for the user, similarity search between these keywords becomes essential.
   - Resources:
      1. Popular methods include using a Trie, Aho–Corasick algorithm, etc
      2. [Thread on StackOverflow](https://stackoverflow.com/questions/21126878/algorithm-to-search-for-a-list-of-words-in-a-text/21128777#21128777)
      3. [Google Ads](https://support.google.com/google-ads/answer/7478529?hl=en#zippy=%2Cphrase-match%2Cbroad-match)
   - **Algorithm:** Aho–Corasick or Jaccard Similarity
   - **Data Structure:**  Set or Hash Table (for efficient keyword lookups)
   - **Time Complexity:**
     - Keyword Extraction: O(n) - n = length of text
     - Matching: O(m) - m = length of the shorter keyword set
   - **Space Complexity:**  O(m) - m = number of distinct keywords
   - [Link to code](codes/Keyword_Matching)

## 4. Real time bidding of numerous ads

   - When the bidding of ads takes place in real time, there are two approaches followed commonly, i.e: First price auction and Second price auction. When an ad space becomes clear, a real time bidding starts. The advertisers go through catalog of adverts provided by publishers. The publishers also mention some conditions like the ad spend budget, maximum bid amount, and ad details. The advertiser then calculates bid amounts for each by predicting how likely it is that the user will click on it.
   - Resources:
      1. Data structures, algorithms used are priority queues, BST's or skip lists. I would like to go with Skip lists, as finding highest bid amount, lowest bid amount is quicker.
      2. Also conditions in the code can be set, to increase the bid amount level in skip lists after a certain threshold, such the ad categories can be divided.
      3. [First Price auction vs Second Price auction](https://clearcode.cc/blog/first-price-second-price-auction/)
   - **Algorithm:**  First-Price or Second-Price Auction (using Skip Lists)
   - **Data Structure:**  Skip Lists (for efficient bid retrieval and sorting)
   - **Time Complexity:**
     - Insertion/Deletion: O(log n) - n = number of bids
     - Finding Highest Bid: O(1)
     - Search for Specific Bid: O(log n)
   - **Space Complexity:** O(n) - n = number of bids
   - [Link to code](codes/Real_Time_Bidding)

## 5. Campaign Performance tracking and analysis

   - Once ads are release and the user starts interacting with it, important statistics can be calculated such as [Clicks, Impressions](https://www.klipfolio.com/resources/kpi-examples/digital-marketing/ad-clicks-vs-ad-impressions), [Conversion Rate](https://support.google.com/google-ads/answer/2684489?hl=en#:~:text=Conversion%20rates%20are%20calculated%20by,50%20%C3%B7%201%2C000%20%3D%205%25.). Once these are tracked, they can be stored either based on the advert or the user. 
   - Segment trees can be used for retrieval of important analytics summary over a given condition, eg: time. Retrieval of cumulative performance becomes easier.   
   - **Algorithm:**  Data Aggregation and Calculation
   - **Data Structure:**  Databases (Relational or NoSQL) or Time-Series Databases
   - **Time Complexity:**  
     - Aggregation: Depends on the query and database implementation, can be anywhere from O(n) to O(log n)
     - Retrieval: Similar to aggregation
   - **Space Complexity:** Depends on the size of the data stored in the database
   - [Link to code](codes/Campaign_Performance)

## 6. Ad Frequency Capping

   - **Scenario:**  To ensure a good user experience, ads should not be displayed too frequently to the same user. We need to track how many times an ad has been displayed to a user. This functionality can be extended to other features too. In the hash map, the key used can be a userId + adId combination. Average retrieval rate of ads when a user opens an app is 400ms, inclusive of bidding, fetching and displaying the ad. Hence fast statistics loop is very necessary.
   - **Algorithm:**  Hash Table for Tracking, Time-Based Expiration
   - **Data Structure:** Hash Table (for storing ad frequencies)
   - **Time Complexity:**
      - Insertion: O(1) (average)
      - Deletion: O(1) (average)
      - Lookup: O(1) (average)
   - **Space Complexity:** O(n) - n = number of ad-user combinations tracked
   - [Link to code](codes/Ad_Frequency_Capping)

## 7. Ad Display

   - **Scenario:** Once we have a list of all the ads that we would like to display to the user, to increase the conversion rate of the ad, we can track the interactivity of the user in real time. The interactivity can be categorized as a positive or negative interaction. Based on this, algorithms like weighted random selection can be used to select ads in these specific categories. 
   - Eg: If a user is currently scrolling through content on the Instagram app, if he likes a video about shoes, and his ad suggestions also have ads related to shoes, it maybe a good time to display those
   - **Algorithm:**  Weighted random selection
   - **Data Structure:** Maps, Vectors
   - **Time Complexity:**
      - Lookup: O(n)
   - **Space Complexity:** O(n) - n = number of weighted ads (suggested) for each user.
   - [Link to code](codes/Ad_Display)
   


