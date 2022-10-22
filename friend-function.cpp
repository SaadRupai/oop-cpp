// friend-function
#include <iostream>
#include<string>
#include<list>
using namespace std;

class YouTubeChannel {
	string Name;
	int SubscribersCount;
public:
	YouTubeChannel(string name, int subscribersCount) {
		Name = name;
		SubscribersCount = subscribersCount;
	}
	bool operator==(const YouTubeChannel& channel) const {
		return this->Name == channel.Name;
	}

	friend ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel);
};
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
	COUT << "Name: " << ytChannel.Name << endl;
	COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
	return COUT;
}
class MyCollection {
	list<YouTubeChannel>myChannels;
public:
	void operator+=(YouTubeChannel& channel) {
		this->myChannels.push_back(channel);
	}
	void operator-=(YouTubeChannel& channel) {
		this->myChannels.remove(channel);
	}
	friend ostream& operator<<(ostream& COUT, MyCollection& myCollection);
};
ostream& operator<<(ostream& COUT, MyCollection& myCollection) {
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
	//myCollection -= yt2;

	cout << myCollection;

	cin.get();
}