//oprator overloading

#include <iostream>
#include<string>
#include<list>
using namespace std;

struct YouTubeChannel {
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount) {
        Name = name;
        SubscribersCount = subscribersCount;
    }
    bool operator==(const YouTubeChannel& channel) const{
        return this->Name == channel.Name;
    }
};
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;
}
struct MyCollection {
    list<YouTubeChannel>myChannels;

    void operator+=(YouTubeChannel& channel) {
        // this is declared ina class because first part is of this class which is represented by "this"
        this->myChannels.push_back(channel);
    }
    void operator-=(YouTubeChannel& channel) {
        // for this operator there comes a problem of equal(==) operator which is solved in base class 
        this->myChannels.remove(channel);
    }
};
ostream& operator<<(ostream& COUT, MyCollection& myCollection) {
    // this is declared globally because both params are needed
    for (YouTubeChannel ytChannel : myCollection.myChannels)
        COUT << ytChannel << endl;
    return COUT;
}

int main()
{
    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;

    cout << myCollection;
    
    cin.get();
}