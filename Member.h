#include <vector>
using namespace std;
#pragma once

class Member{
	private:
	vector<Member*> followers;
	vector<Member*> following;
	static int counter;
	
	public:
	static int count();
	int numFollowers();
	int numFollowing();
	void follow(Member& person);
	void unfollow(Member& person);
	Member();
	~Member();
};