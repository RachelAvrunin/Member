#include "Member.h"

using namespace Member;

int counter = 0;	
	
Member(){	
	counter++;
}

~Member(){
	for(int i=0 ;i<followers.size(); i++){
		followers[i]->unfollow(*this);
	}
	for(int i=0 ;i<following.size(); i++){
		unfollow(*following[i]);
	}
	counter--;
	followers.clear();
	following.clear();
}

 int count(){
	return counter;
}
	
int numFollowers(){
	return this->followers.size();
}

int numFollowing(){
	return following.size();
}
	
void follow(Member& person){
	Member *p = &person; 
	if(this==p)
		return;

	for(int i=0; i<following.size(); i++){
		if(following[i] == p)
			return;
	}	
	following.push_back(p);
	p->followers.push_back(this);	
}
	
void unfollow(Member& person){
	Member *p = &person; 
	int flag = 0;
	for(int i=0; i<following.size(); i++){
		if(following[i] == p){
			following.erase(following.begin() + i);
			flag = 1;
		}
	}

	if(flag == 0) return;
	for(int i=0; i< p->followers.size(); i++){
		if(p->followers[i] == this){
			p->followers.erase(p->followers.begin()+i);
			return;
		}
	}
}