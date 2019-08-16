#include"uuid/uuid.h"
#include<iostream>
int main(int argc,char** argv){
	cpputils::UUID uuid;
	for(int i=0;i<8;i++)
		std::cout<<cpputils::UUID::generateUUID()<<std::endl;
	return 0;
}
