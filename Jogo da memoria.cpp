#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

using namespace std;

int facil();
int medio();
int dificil();

int main()   ///inicio do programa
{
    setlocale(LC_ALL, "portuguese");
    int dificuldade;
    srand(time(NULL));

    cout << "                                    ------------------------------------ \n";
    cout << "                                   |           JOGO DA MEMÓRIA          |\n";
    cout << "                                    ------------------------------------ \n";
    cout << "\n                    Digite qual dificuldade você deseja jogar!! \n\n ";
    cout << "                    1-Fácil \n\n                     2-Médio\n\n                     3-Difícil\n\n";
    cout << "                    Escolha somente o número : ";
    cin >> dificuldade;
    system("cls");
    switch (dificuldade)
    {
        case 1:
            facil();
            break;
        case 2:             /// entrar no modo de dificuldade
            medio();
            break;
        case 3:
            dificil();
            break;
    }
    cout << "\n\nDESENVOLVIDO POR : GABRIEL TOSCANO\n";
    return 0;
}

int facil()
{
    int P[4][4], G[4][4], J[4][4], mode, i, j, ia, ja, jogadas=0, cont, chec, x, y;
    mode = rand()%4;
    bool acerto = false;

    P[0][0] = 3, P[0][1] = 8, P[0][2] = 5, P[0][3] = 4;
    P[1][0] = 1, P[1][1] = 3, P[1][2] = 6, P[1][3] = 7;
    P[2][0] = 7, P[2][1] = 1, P[2][2] = 5, P[2][3] = 6;
    P[3][0] = 2, P[3][1] = 4, P[3][2] = 8, P[3][3] = 2;

    if(mode == 0)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                G[i][j] = P[i][j];
            }
        }
    }
    else if(mode == 1)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                G[i][j] = P[j][i];
            }
        }
    }
    else if(mode == 2)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                G[i][j] = P[3-i][j];
            }
        }
    }
    else if(mode == 3)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                G[i][j] = P[i][3-j];
            }
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            J[i][j]= 0;
        }
    }
    cout << "\n                                              JOGO DA MEMÓRIA [ Fácil ]\n\n                                    ";
    system("pause");
    while(jogadas < 24 && acerto == false)
    {
        system("cls");
        ia=4;
        ja=4;
        for(cont=0; cont<2; cont++)
        {
            cout << "Jogadas Restantes : " << 24-jogadas << "\n";
            cout << "    C0  C1  C2  C3";
            for(y=0; y<4; y++)
            {
                cout << endl;
                cout << "L" << y <<" : ";
                for(x=0; x<4; x++)
                {
                    cout << J[y][x] << "   ";
                }
            }
            cout << "\n\nDigite a linha e a coluna a revelar : ";
            cout << "\nLinha : ";
            cin >> i;
            while(i<0 || i>3)
            {
                cout << "Linha inexistente, digite novamente\nLinha : ";
                cin >> i;
            }
            cout << "Coluna : ";
            cin >> j;
            while(j<0 || j>3)
            {
                cout << "Coluna inexistente, digite novamente\nColuna : ";
                cin >> j;
            }
            if(i==ia && j==ja)
            {
                cout << "\nMesmo local escolhido, favor escolher um diferente.\n";
                cont --;
                Sleep(1500);
                system("cls");
            }
            else if(J[i][j] != 0)
            {
                cout << "\nLocal já descoberto, favor escolher outro.\n";
                cont--;
                Sleep(1500);
                system("cls");
            }
            else
            {
                J[i][j] = G[i][j];
                for(y=0; y<4; y++)
                {
                    cout << endl;
                    for(x=0; x<4; x++)
                    {
                        cout << J[y][x] << "   ";
                    }
                }
                cout << "\n";
                if(cont == 1 && G[ia][ja] == G[i][j])
                {
                    cout << "\nJogada OK";
                }
                else if(cont == 1)
                {
                    cout << "\nJogada NOK";
                    J[i][j] = 0;
                    J[ia][ja] = 0;
                }
                ia=i, ja=j;
                Sleep(1500);
                system("cls");
            }
        }
            chec = 0;
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(J[i][j] == 0)
                    {
                        chec++;
                    }
                }
            }
            if(chec == 0)
            {
                acerto = true;
                cout << "\n\n!!! VOCÊ GANHOU !!! PARABÉNS !!!\n";
            }
            else
            {
                jogadas ++;
                if(jogadas == 24)
                {
                    cout << "\n\n!!! JOGADAS ENCERRADAS !!! VOCÊ PERDEU !!!\n";
                }
            }
    }
}

int medio()
{
    int P[4][6], G[4][6], J[4][6], mode, i, j, ia, ja, jogadas=0, cont, chec, x, y;
    bool acerto = false;
    mode = rand()%3;

    P[0][0] = 9, P[0][1] = 2, P[0][2] = 12, P[0][3] = 6, P[0][4] = 10, P[0][5] = 3;
    P[1][0] = 4, P[1][1] = 7, P[1][2] = 5, P[1][3] = 11, P[1][4] = 1, P[1][5] = 4;
    P[2][0] = 1, P[2][1] = 11, P[2][2] = 10, P[2][3] = 8, P[2][4] = 12, P[2][5] = 8;
    P[3][0] = 7, P[3][1] = 3, P[3][2] = 6, P[3][3] = 2, P[3][4] = 9, P[3][5] = 5;


    if(mode == 0)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[i][j];
            }
        }
    }
    else if(mode == 1)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[3-i][j];
            }
        }
    }
    else if(mode == 2)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[i][5-j];
            }
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<6; j++)
        {
            J[i][j]= 0;
        }
    }
    cout << "\n                                             JOGO DA MEMÓRIA [ Médio ]\n\n                                   ";
    system("pause");
    while(jogadas < 36 && acerto == false)
    {
        system("cls");
        ia=5;
        ja=7;
        for(cont=0; cont<2; cont++)
        {
            cout << "Jogadas Restantes : " << 24-jogadas << "\n";
            cout << "    C0   C1   C2   C3   C4   C5";
            for(y=0; y<4; y++)
                {
                    cout << endl;

                    cout << "L" << y <<" : ";
                    for(x=0; x<6; x++)
                    {
                        cout << J[y][x];
                        if(J[y][x] < 10)
                        {
                            cout << "    ";
                        }
                        else
                        {
                            cout << "   ";
                        }
                    }
                }
            cout << "\n\nDigite a linha e a coluna a revelar : ";
            cout << "\nLinha : ";
            cin >> i;
            while(i<0 || i>3)
            {
                cout << "Linha inexistente, digite novamente\nLinha : ";
                cin >> i;
            }
            cout << "Coluna : ";
            cin >> j;
            while(j<0 || j>5)
            {
                cout << "Coluna inexistente, digite novamente\nColuna : ";
                cin >> j;
            }
            if(i==ia && j==ja)
            {
                cout << "\nMesmo local escolhido, favor escolher um diferente.\n";
                cont --;
                Sleep(1500);
                system("cls");
            }
            else if(J[i][j] != 0)
            {
                cout << "\nLocal já descoberto, favor escolher outro.\n";
                cont--;
                Sleep(1500);
                system("cls");
            }
            else
            {
                J[i][j] = G[i][j];
                for(y=0; y<4; y++)
                {
                    cout << endl;
                    for(x=0; x<6; x++)
                    {
                        cout << J[y][x];
                        if(J[y][x] < 10)
                        {
                            cout << "    ";
                        }
                        else
                        {
                            cout << "   ";
                        }
                    }
                }
                cout << "\n";
                if(cont == 1 && G[ia][ja] == G[i][j])
                {
                    cout << "\nJogada OK";
                }
                else if(cont == 1)
                {
                    cout << "\nJogada NOK";
                    J[i][j] = 0;
                    J[ia][ja] = 0;
                }
                ia=i, ja=j;
                Sleep(1500);
                system("cls");
            }
        }
            chec = 0;
            for(i=0; i<4; i++)
            {
                for(j=0; j<6; j++)
                {
                    if(J[i][j] == 0)
                    {
                        chec++;
                    }
                }
            }
            if(chec == 0)
            {
                acerto = true;
                cout << "\n\n!!! VOCÊ GANHOU !!! PARABÉNS !!!\n";
            }
            else
            {
                jogadas ++;
                if(jogadas == 36)
                {
                    cout << "\n\n!!! JOGADAS ENCERRADAS !!! VOCÊ PERDEU !!!\n";
                }
            }
    }
}

int dificil()
{
    int P[6][6], G[6][6], J[6][6], mode, i, j, ia, ja, jogadas=0, cont, chec, x, y;
    bool acerto = false;
    mode = rand()%4;

    P[0][0] = 6, P[0][1] = 14, P[0][2] = 3, P[0][3] = 7, P[0][4] = 9, P[0][5] = 17;
    P[1][0] = 12, P[1][1] = 6, P[1][2] = 5, P[1][3] = 17, P[1][4] = 10, P[1][5] = 2;
    P[2][0] = 1, P[2][1] = 8, P[2][2] = 11, P[2][3] = 15, P[2][4] = 14, P[2][5] = 18;
    P[3][0] = 13, P[3][1] = 4, P[3][2] = 16, P[3][3] = 16, P[3][4] = 1, P[3][5] = 8;
    P[4][0] = 10, P[4][1] = 13, P[4][2] = 9, P[4][3] = 18, P[4][4] = 12, P[4][5] = 7;
    P[5][0] = 3, P[5][1] = 2, P[5][2] = 15, P[5][3] = 5, P[5][4] = 11, P[5][5] = 4;

    srand(time(NULL));

    if(mode == 0)
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[i][j];
            }
        }
    }
    else if(mode == 1)
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[j][i];
            }
        }
    }
    else if(mode == 2)
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[5-i][j];
            }
        }
    }
    else if(mode == 3)
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                G[i][j] = P[i][5-j];
            }
        }
    }
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            J[i][j]= 0;
        }
    }
    cout << "\n                                              JOGO DA MEMÓRIA [ Difícil ]\n\n                                     ";
    system("pause");
    while(jogadas < 54 && acerto == false)
    {
        system("cls");
        ia=6;
        ja=6;
        for(cont=0; cont<2; cont++)
        {
            cout << "Jogadas Restantes : " << 54-jogadas << "\n";
            cout << "    C0   C1   C2   C3   C4   C5";
            for(y=0; y<6; y++)
                {
                    cout << endl;

                    cout << "L" << y <<" : ";
                    for(x=0; x<6; x++)
                    {
                        cout << J[y][x];
                        if(J[y][x] < 10)
                        {
                            cout << "    ";
                        }
                        else
                        {
                            cout << "   ";
                        }
                    }
                }
            cout << "\n\nDigite a linha e a coluna a revelar : ";
            cout << "\nLinha : ";
            cin >> i;
            while(i<0 || i>5)
            {
                cout << "Linha inexistente, digite novamente\nLinha : ";
                cin >> i;
            }
            cout << "Coluna : ";
            cin >> j;
            while(j<0 || j>5)
            {
                cout << "Coluna inexistente, digite novamente\nColuna : ";
                cin >> j;
            }
            if(i==ia && j==ja)
            {
                cout << "\nMesmo local escolhido, favor escolher um diferente.\n";
                cont --;
                Sleep(1500);
                system("cls");
            }
            else if(J[i][j] != 0)
            {
                cout << "\nLocal já descoberto, favor escolher outro.\n";
                cont--;
                Sleep(1500);
                system("cls");
            }
            else
            {
                J[i][j] = G[i][j];
                for(y=0; y<6; y++)
                {
                    cout << endl;
                    for(x=0; x<6; x++)
                    {
                        cout << J[y][x];
                        if(J[y][x] < 10)
                        {
                            cout << "    ";
                        }
                        else
                        {
                            cout << "   ";
                        }
                    }
                }
                cout << "\n";
                if(cont == 1 && G[ia][ja] == G[i][j])
                {
                    cout << "\nJogada OK";
                }
                else if(cont == 1)
                {
                    cout << "\nJogada NOK";
                    J[i][j] = 0;
                    J[ia][ja] = 0;
                }
                ia=i, ja=j;
                Sleep(1500);
                system("cls");
            }
        }
            chec = 0;
            for(i=0; i<6; i++)
            {
                for(j=0; j<6; j++)
                {
                    if(J[i][j] == 0)
                    {
                        chec++;
                    }
                }
            }
            if(chec == 0)
            {
                acerto = true;
                cout << "\n\n!!! VOCÊ GANHOU !!! PARABÉNS !!!\n";
            }
            else
            {
                jogadas ++;
                if(jogadas == 54)
                {
                    cout << "\n\n!!! JOGADAS ENCERRADAS !!! VOCÊ PERDEU !!!\n";
                }
            }
    }
}
