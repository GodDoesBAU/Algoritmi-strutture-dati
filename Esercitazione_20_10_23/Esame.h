#ifndef ESAME_H
#define ESAME_H

#include <string>

class Esame {
private:
    std::string NomeEsame;
    bool Sostenuto;
    int VotoEsame;

public:
    Esame();
    Esame(std::string nome);
    Esame(std::string nome, int voto);

    std::string getEsame();
    void setEsame(std::string nome);
    int getVoto();
    void setVoto(int voto);
    bool isSostenuto();
};

#endif