/**
* \mainpage Módulo de Persistência
*
* \brief Este módulo é responsável por garantir a integridade dos dados e do sistema.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "mp.h"
#include "..\MGD\mgd.h"

#define SERVIDOR_MP

/* Classes */
using namespace std;
//Métodos para Master
//Construtor
Master::Master (const string n, const int mat, const string s)
{
    nome = n;
    matricula = mat;
    senha = s;
}

//Chama a execução do cadastro
void Master::cadastrar ()
{
    Cadastrar usuario (nome, matricula, senha);
}

//Métodos para Professor
//Construtor
Professor::Professor (const string n, const int mat, const string s, const string disci)
{
    nome = n;
    matricula = mat;
    senha = s;
    disciplina = disci;
}

//Chama a execução do cadastro
void Professor::cadastrar ()
{
    Cadastrar usuario (nome, matricula, senha, disciplina);
}

//Métodos para Aluno
//Construtor
Aluno::Aluno (const string n, const int mat, const string s, const char t)
{
    nome = n;
    matricula = mat;
    senha = s;
    turma = t;
}

//Chama a execução do cadastro
void Aluno::cadastrar ()
{
    Cadastrar usuario (nome, matricula, senha, turma);
}

/* Funções */
void checa_estado_sistema ()
{
    ArquivoExiste arquivo ( (char *) &"dados/Master.txt");

    //Ainda não há nenhum usuário Master cadastrado
    if ( !arquivo.getExistencia () )
    {
        InicializarSistema ini;
    }
    //Há algum usuário Master cadastrado
    else
    {
        //Do nothing
    }
}

//Checa os dados de um usuario Master
bool existe_user (const string nome, const int matricula, const string senha, const char *nome_arquivo)
{
    return checar_user (nome, matricula, senha, nome_arquivo);
}

//Checa os dados digitados por um Professor
bool existe_user (const string nome, const int matricula, const string senha, const string disci, const char *nome_arquivo)
{
    return checar_user (nome, matricula, senha, disci, nome_arquivo);
}

//Checa os dados digitados por um Aluno
bool existe_user (const string nome, const int matricula, const string senha, const char t, const char *nome_arquivo)
{
    return checar_user (nome, matricula, senha, t, nome_arquivo);
}

//Checa se um usuario existe e o deleta
bool solicitar_excluir_user (const string nome, const int matricula, const int nivel)
{
    bool sucesso;

    return sucesso = excluir_user (nome, matricula, nivel);
}

//Imprimem os valores no objeto, somente para testes.
void Master::esc ()
{
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Senha: " << senha << endl;
}

void Professor::esc ()
{
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Senha: " << senha << endl;
    cout << "Disciplina: " << disciplina << endl;
}

void Aluno::esc ()
{
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Senha: " << senha << endl;
    cout << "Turma: " << turma << endl;

}
