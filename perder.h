void gamemap :: losemonst(){
  //  int flag;
    string line;
    char userInput = ' ';
    ifstream myFile("lose.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
  //      getchar();
    //    getchar();
        //system ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}