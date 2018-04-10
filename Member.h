#include <iostream>
#include <vector>
#pragma once

using namespace std;

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