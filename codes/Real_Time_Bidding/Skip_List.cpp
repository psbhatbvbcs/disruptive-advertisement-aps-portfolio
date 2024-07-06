/*
Implements first price and second price using skip lists. Additional conditions can be set which takes care of hard price flow and soft price flow or other 
conditions to increase the skip list level. Finding max in each level is very quick as it is always sorted.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <unordered_map>

using namespace std;

struct SkipListNode
{
    int advertiserId;
    double amount;
    SkipListNode **forward;
    SkipListNode(int id, double amt, int level) : advertiserId(id), amount(amt)
    {
        forward = new SkipListNode *[level + 1];
        memset(forward, 0, sizeof(SkipListNode *) * (level + 1));
    }
    ~SkipListNode()
    {
        delete[] forward;
    }
};

class SkipList
{
    int maxLevel;
    int level;
    double p;
    SkipListNode *header;

    int randomLevel()
    {
        int lvl = 0;
        while ((double)rand() / RAND_MAX < p && lvl < maxLevel)
        {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList(int maxLevel, double p) : maxLevel(maxLevel), p(p)
    {
        level = 0;
        header = new SkipListNode(-1, -1, maxLevel);
    }

    ~SkipList()
    {
        delete header;
    }

    void insert(int advertiserId, double amount)
    {
        SkipListNode *current = header;
        SkipListNode *update[maxLevel + 1];
        memset(update, 0, sizeof(SkipListNode *) * (maxLevel + 1));

        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->amount < amount)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || current->amount != amount)
        {
            int rlevel = randomLevel();

            if (rlevel > level)
            {
                for (int i = level + 1; i <= rlevel; i++)
                {
                    update[i] = header;
                }
                level = rlevel;
            }

            SkipListNode *newNode = new SkipListNode(advertiserId, amount, rlevel);

            for (int i = 0; i <= rlevel; i++)
            {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    double getMax()
    {
        SkipListNode *current = header->forward[0];
        return (current != nullptr) ? current->amount : 0.0;
    }

    double getSecondMax()
    {
        SkipListNode *current = header->forward[0];
        if (current == nullptr || current->forward[0] == nullptr)
            return 0.0;
        return current->forward[0]->amount;
    }
};

unordered_map<int, double> bidsMap;
SkipList skipList(16, 0.5);

void addBid(int advertiserId, double amount)
{
    if (bidsMap.find(advertiserId) == bidsMap.end() || bidsMap[advertiserId] < amount)
    {
        bidsMap[advertiserId] = amount;
        skipList.insert(advertiserId, amount);
    }
}

double executeFirstPriceAuction()
{
    return skipList.getMax();
}

double executeSecondPriceAuction()
{
    return skipList.getSecondMax() + 0.01;
}

int main()
{
    srand(time(0));

    addBid(1, 4.0);
    addBid(2, 4.5);
    addBid(3, 4.2);

    cout << "First-Price Auction Winning Bid: " << executeFirstPriceAuction() << endl;

    addBid(1, 4.0);
    addBid(2, 4.5);
    addBid(3, 4.2);

    cout << "Second-Price Auction Winning Bid: " << executeSecondPriceAuction() << endl;

    return 0;
}
