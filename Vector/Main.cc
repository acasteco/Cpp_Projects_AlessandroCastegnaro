#include <vector>


struct Persona {
	std::string name;
	std::string bdate;
	std::string DNI;
};


void AddVectors(std::vector) {

}


int main() {
	std::vector<int>v1(5);
	std::vector<int>v2(10, 0);
	std::vector<int>v3({ 10,9,8,7,6,5,4,3,2,1 });
	std::vector<std::string>v4({ "Gertrudiz","Pancracia" , "Anacleto","Hipolito","Eustaquio" , "Fulgencia" });
	std::vector<int> v5(v3);
	std::vector<Persona>v6({ {"Gertrudiz", "19/07/1996", "45354534d"}, {"Ger", "26/1/1564", "5435435435843g"} ,{"trudiz", "15/6/1994", "45345334534a"} });
	return 0;
}