
// Cifra de Vigenere em C++
#include<bits/stdc++.h>
using namespace std;
 
//esta função faz com que a chave se repita até ser do mesmo tamanho que o texto
//a ser criptografado
string ajustarChave(string texto, string chave)
{
    int x = texto.size();
 
    for (int i = 0; i<x ; i++) // irá se repetir até que chave.size() == str.size()
    {
        if (chave.size() == texto.size())
		{
            break;
        }
        //cout << chave[i];
        chave.push_back(chave[i]);
        //cout << chave;
    }
    return chave;
}
 
//função que criptografa o texto passado pelo usuário.
string criptografar(string texto, string chave, int opmecanismo)
{
    string textoCriptografado;
 
    for (int i = 0; i < texto.size(); i++)
    {
        char x;
		
        //Utilizei a tabela ascii
		
        if (texto[i] >= 'A' && texto[i] <= 'Z') 
		{
			if (opmecanismo==1){ //Foi utilizado o método de mecanismo ROT.
				x = (texto[i] + chave[i]) %26;
				x += 'A';
			}else
			{
				x = ((texto[i] + chave[i]) %26)+1;
				x += 'A';
			}	
            
        }
		else if (texto[i] >= 'a' && texto[i] <= 'z')
		{
            if (opmecanismo==1)
            {
                x = (texto[i] + chave[i])-97;
                
                if((texto[i] + chave[i])-97 > 122)
                {
                    x -= 26;
                }  
            }
			else
            {
                x = ((texto[i] + chave[i])-97)+1;
                if((texto[i] + chave[i])-97 > 122)
                {
                    x -= 26;
                } 
            } 
        }
 
        textoCriptografado.push_back(x);
    }
    return textoCriptografado;
}
 
//função que descriptografa o texto criptografado passado pelo usuário, se 
//tornando legível de entendimento
//nessa função foi utilizado os mesmos métodos de tabela ascii e ROT do que a função anterior
string descriptografar(string textoCriptografado, string chave, int opmecanismo)
{
    string textoDescriptografado;
	char x;
    for (int i = 0 ; i < textoCriptografado.size(); i++)
    {
        if (opmecanismo == 1)
		{
			 x = (textoCriptografado[i] - chave[i] + 26) %26;
		}else
		{
			 x = ((textoCriptografado[i] - chave[i] + 26) %26)-1;
			
		}	
        if (textoCriptografado[i] >= 'A' && textoCriptografado[i] <= 'Z')
		{
            x += 'A';
        }else if (textoCriptografado[i] >= 'a' && textoCriptografado[i] <= 'z')
		{
             x += 'a';
         }
		 
        textoDescriptografado.push_back(x);
    }
    return textoDescriptografado;
}
 
int main()
{
    string textoInserido;
    string ChaveInserido;
    int mecanismo;
	
    while(true) 
	{
		unsigned op;
		
		cout << "\t*******Menu:*************\n"
		<< "\t* 1 - Codificar texto.***\n"
		<< "\t* 2 - Decodificar texto.*\n"
		<< "\t* 3 - Sair.**************\n" 
		<< "\t*************************\n" << endl
		<< "Digite a opção desejada:";
		cin >> op;
	
		if(op == 3)
		{
			break;
		}
		if(op > 3) 
		{
			cout << "error: Opção inválida.\n" << endl;
			continue;
		}
		
		if(op == 1)
		{
			cout << "\t Digite uma opção de mecanismo para criptografar/descriptografar:\n"; //foi utilizado esse método, pois se utilizar somente 
																							//a letra a como chave, ela não criptografa
			<< "\t 1 - Para usar ROT0 ('a' transforma-se em 'a') \n ";
			<< "\t 2 - para usar ROT1 ('a' transforma-se em 'b') \n";
            cin >> mecanismo;
            if (mecanismo == 1 or mecanismo == 2)
            {
				cout << "Digite o texto a ser criptografado \n";
				cin >> textoInserido;
			
				cout << "Digite a chave a ser usada nessa criptografia \n";
				cin >> ChaveInserido;
			
				string chave = ajustarChave(textoInserido, ChaveInserido);
				string textoCriptografado = criptografar(textoInserido, chave, mecanismo);
				cout << "Texto Criptografado : "
				<< textoCriptografado << "\n";
			}
			else 
            {
               cout << "Opção inválida \n";
            }
        }else
		{
			cout << "Digite 1 para usar ROT0 ('a' transforma-se em 'a') ou 2 - para usar ROT1 ('a' transforma-se em 'b') para criptografar? \n";
            cin >> mecanismo;
			if (mecanismo == 1 or mecanismo == 2)
            {
				cout << "Digite o texto a ser descriptografado \n";
				cin >> textoInserido;
				cout << "Digite a chave a ser usada nessa descriptografia \n";
				cin >> ChaveInserido;
				string chave = ajustarChave(textoInserido, ChaveInserido);
				string original_Text = descriptografar(textoInserido, chave, mecanismo);
				cout << "Texto Descriptografado : "
				<< original_Text << "\n"; 
			}
			else
			{
				cout << "Opção inválida \n";
			}	
             
		}
    }
    
    return 0;
}