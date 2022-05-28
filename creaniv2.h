void gamemap::createniv2(){
    ofstream myFile("niv2.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (i == 0 || i == 19)
                {
                    myFile << "1";
                } else
                {
                    if (j == 0 || j == 59)
                    {
                        myFile << "1";
                    } else
                    {
                        myFile << "0";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}