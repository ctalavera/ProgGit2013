/*Programa que implementa arreglos paralelos un conjunto de empleados
  donde a a cada empleado le es calculado el salario
  */
#include<iostream>
#include<iomanip>
using namespace::std;
const int ROW= 50;
const int COL = 50;
void getData(char name[ROW][COL],char Id[ROW][COL],int hours[ROW], double payRate[ROW],double wages[ROW], int size);
void displayData(char name[ROW][COL],char Id[ROW][COL],int hours[ROW], double payRate[ROW],double wages[ROW], int size);
void calWages(int hours[ROW], double payRate[ROW], double wages[ROW],int size);

int main(){
int size;
char name[COL][ROW];
char Id[COL][ROW];
int hours[ROW];
double payRate[ROW];
double wages[ROW];

	cout<<"Entre el numero de empleados:";
	cin>>size;
	getData(name,Id, hours, payRate,wages, size);
    displayData(name,Id, hours, payRate, wages, size);
     system("pause");
	return 0;

}//end main

//Calcula los salarios de cada empleado
void calWages(int hours[ROW], double payRate[ROW], double wages[ROW],int size){
int i;
	for(i=0;i<size;i++){
		wages[i] = hours[i] * payRate[i];
	}//end for
}//end calWages

//Pide el nombre, su numero de identificacion, las horas trabajadas
//El pago por hora
void getData(char name[ROW][COL],char Id[ROW][COL],int hours[ROW],double  payRate[ROW],double wages[ROW], int size){
int i=0;

for(i=0;i<size;i++){
	cin.ignore();
	cout<<"Entre su nombre:";
	cin.getline(name[i],ROW,'\n');
	cin.ignore();
	cout<<"Entre su Id:";
	cin.getline(Id[i],ROW,'\n');
   
	do{
		cout<<"Entre las horas:";
		cin>>hours[i];
		if(hours[i] < 0 ){
			cout<<"\nError, pago por horas trabajads debe ser positivas\n";
		}
	}while(hours[i] < 0);
	do{
		cout<<"Entre el pago por hora:";
		cin>>payRate[i];
		if(payRate[i] < 7.25){
			cout<<"\nError, pago por horas debe ser >=$7.25\n";
		}
	}while(payRate[i] < 7.25);
	
}//end for
calWages(hours, payRate, wages,size);
}//end getData

//Imprime la informacion en forma tabular
void displayData(char name[ROW][COL],char Id[ROW][COL],int hours[ROW], double payRate[ROW],double wages[ROW], int size){
	int i;
	cout<<fixed;
	cout<<"\nName          ID         Hours        Pay Rate    Wages\n";
	for(i=0;i<size;i++){
		cout<<name[i]<<setw(10)<<Id[i]<<setw(5)<<hours[i]<<setprecision(3)<<setw(8)<<payRate[i]<<setprecision(3)<<setw(15)<<wages[i]<<endl;
	}//end for

}//end displayData

