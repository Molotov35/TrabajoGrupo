void persona::insert2()
{
    system("cls");
    fstream file;
    cout<<"\n-------------------------------------------------Agregar detalles del nivel de Estudio ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Persona     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Nivel Persona   : ";
	cin>>phone;
	cout<<"\t\t\tIngresa Estudio Persona: ";
	cin>>college;
	cout<<"\t\t\tIngresa Departamento Persona  : ";
	cin>>address;
    file.open("NivelesdeEstudio.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	file.close();
	hora();
	string filename("bitacora.txt");
	ofstream file_out;
	file_out.open("bitacora.txt", std::ios_base::app);
	file_out <<"el ultimo usuario logueado ingreso un nuevo registro con id:  "<< id;

}
void persona::display2()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Niveles de Estudio -------------------------"<<endl;
	file.open("NivelesdeEstudio.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> phone >> college >> address;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Persona: "<<id<<endl;
			cout<<"\t\t\t Nombre Persona: "<<name<<endl;
			cout<<"\t\t\t Nivel Persona: "<<phone<<endl;
			cout<<"\t\t\t Estudio de  Persona: "<<college<<endl;
			cout<<"\t\t\t Departamento Persona: "<<address<<endl;
			file >> id >> name >> phone >> college >> address;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion(por Juna >:V)...";
		}
	}
	file.close();
}
