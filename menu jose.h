void gamemap::menuinicial()
{
    char userInput = ' ';
    bool x=0;
    while (x==0){
         cin >> userInput;
        switch(userInput){
        case '1':
                x=1;
                break;
        case '2':
                x=0;
                drawInstrucc();
                break;
        case '3':
                x=0;
                historia();
                break;
        case '4':
                x=0;
                drawCreditos();
                break;
        case '5':
                exit(0);
        default:
            cout << "\n\n\n\n ingrese un valor porfavor \n\n\n";
            x=0;
        }
        break;
    }
    if (x==0){
            drawPortada();
    }
}