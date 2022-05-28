void gamemap :: siguientenivel(){
    string line;
    char userInput = ' ';
    ifstream myFile("siguienteniv.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
    getchar();
    getchar();
    loadniv2();
//    segundomapa();
    cout<<" SIGUE TU PUEDES!!!"<< endl;
    draw();

}
