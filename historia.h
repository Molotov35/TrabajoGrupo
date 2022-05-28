void gamemap :: historia (){
    string line;
    char userInput = ' ';
    ifstream myFile("CAP1.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
            getchar();
            getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
//    string line;
    //char userInput = ' ';
    ifstream File("CAP2.txt");
    if(File.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(File, line))
        {
            cout << line << endl;
        }
        File.close();
            getchar();
            getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
  //  string line;
    //char userInput = ' ';
    ifstream my("CAP3.txt");
    if(my.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(my, line))
        {
            cout << line << endl;
        }
        my.close();
            getchar();
            getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}