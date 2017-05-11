/*
int x,x2;		x[01...10...1]
float y;	y[1....1(mantisa) 1....1...0(exp)]

x=x+x2;	//el compilador verifica si puede hacer la operacion '+' para los tipos int y si se puede no da errores de compilacion
x=x+y;	//hace la conversion implicita de int a float (operacion widening) para la 'x' y suma "x+y", pero al assignarlo a x que es un entero hace una conversion Narrowing donde va a perder datos al truncar el resultado de "x+y"
y=x+y;

conversiones explicitas(cast)

static_cast
	double d=1.21355;
	int i = d;					//warning
	int j = stitc_cast<int>(d);	//NO Warning

	enum class Weapon{
		FIST,
		GUN,
		SHOTGUN,
		MAX
	};
	int m;
	m = Weapon::FISTS; //error
	m = static_cast<int> (Weapon::FISTS); //correcto

dynamic_cast
	?????????????
const_cast
	hace o quita el const de una variable
	ej:
	void Func(double& d){
	//..
	}
	const double pi = 3.14;
	Func(pi);						//error
	Func(const_cast<double&>(pi));	//OK
reinterpret_cast
	int *p;
	int i4;
	i4 = p;							//error
	i4 = static_cast<int>(p);		//error
	i4 = reinterpret_cast<int>(p);	//OK
	







|	|	|	|	TEMPLATE	|	|	|	|


template < typename T> void printList(std::list<T> l){
	for(auto x : l){
		std::cout << x << '-';
	}
	std::cout << std::endl;
}
std::list<std::string> l1({"hola", "hello"});
printList(l1);

std::list<int> l2({10,20,30});
printList(l2);
*/