#include<iostream>
#include<map>
using namespace std;
template <class T1,class T2>
void printMap(map<T1,T2>&m){
   typename std::map<T1,T2>::iterator it;//由于使用的是gcc编译器，故而需要在前面加typename
    for(it=m.begin();it!=m.end();++it){
        cout<<" key= "<<it->first<<" value= "<<m[it->first];//it->second;
    }
    cout<<endl;
}
void test(){
   	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式，不建议,因为会创建一个新的键(默认值为0），但是可以用于[]访问
	m[4] = 40; 
	printMap(m);//自动类型推导

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//清空
	m.erase(m.begin(),m.end());
	m.clear();
	printMap(m);

}
void test2(){

}
int main(){

    test();
    test2();
    getchar();
    return 0;
}