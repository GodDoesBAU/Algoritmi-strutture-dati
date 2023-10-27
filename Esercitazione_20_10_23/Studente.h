#ifndef STUDENTE_H
#define STUDENTE_H

#include <string>
#include "Esame.h"
#include <vector>

class Studente {
private:
    std::string Matricola;
    std::string Nome;
    std::vector<Esame> Esami;
    const int NumEsami;

public:
    Studente();
    Studente(std::string nome1, std::string nome2, std::string nome3, std::string nome4, std::string nome5);

    void setMatricola(std::string matricola);
    void setNome(std::string nome);
    std::string getMatricola();
    std::string getNome();
    int getNumEsami();
    void setEsame(int voto, int i);
    int getVotoEsame(int i);
    std::string getNomeEsame(int i);
    bool getSostenuto(int i);
    double getMedia();
    void printStudente();
};

#endif
