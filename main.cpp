#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

#define art 0
#define plan 1
#define research 2
class staff{
public:
	string mName;
	int mSalary;//10000~19999
} ;    

//创建员工
void createStaff(vector<staff>& cStaff)
{
	string nameSet="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		staff staffO;
		staffO.mName="员工"+nameSet[i];
		staffO.mName+nameSet[i];
		staffO.mSalary=rand()%10000+10000;
		//将员工放到容器中
		cStaff.push_back(staffO);
	}
}
//random allocation
void setGroup(vector<staff>& cStaff,multimap<int,staff> &m){
	for(vector<staff>::iterator it=cStaff.begin();it!=cStaff.end();it++){
		
		int set=rand()%3;
		m.insert(make_pair(set,*it));
	}
}
void showGroup(multimap<int,staff> &m){
	cout << "策划部门: " << endl;
	multimap<int,staff>::iterator pos=m.find(plan);
	int count=m.count(plan);
	int index=0;
	for(;pos!=m.end()&&index<count;pos++,index++){
		cout<<" name:"<<pos->second.mName<<" salary:"<<pos->second.mSalary<<endl;
	}
	

	cout << "----------------------" << endl;
	cout << "美术部门： " << endl;
	 pos=m.find(art);
	 count=m.count(art);
	 index=0;
	for(;pos!=m.end()&&index<count;pos++,index++){
		cout<<" name: "<<pos->second.mName<<" salary: "<<pos->second.mSalary<<endl;
	}

	cout << "----------------------" << endl;
	cout << "研发部门： " << endl;
	 pos=m.find(research);
	 count=m.count(research);
	 index=0;
	for(;pos!=m.end()&&index<count;pos++,index++){
		cout<<" name: "<<pos->second.mName<<" salary: "<<pos->second.mSalary<<endl;
	} 
}

int main(){

	srand((unsigned int)time(NULL));
	//create
	vector<staff>vStaff;
	createStaff(vStaff);

	//allocation
	multimap<int,staff>mStaff;
	setGroup(vStaff,mStaff);

	showGroup(mStaff);
	
    //getchar();
    return 0;
}