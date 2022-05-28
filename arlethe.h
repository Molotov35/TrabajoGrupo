void gamemap::drawAgujero()
{
   // system ("cls");
    string line;
    char userInput = ' ';
    ifstream myFile("agujero.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        //stem ("pause");
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}