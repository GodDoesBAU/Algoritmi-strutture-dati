#include "Esame.h"

// Costruttore di default
Esame::Esame() : NomeEsame(""), Sostenuto(false), VotoEsame(0) {}

// Costruttore con nome dell'esame
Esame::Esame(std::string nome) : NomeEsame(nome), Sostenuto(false), VotoEsame(0) {}

// Costruttore con nome e voto
Esame::Esame(std::string nome, int voto) : NomeEsame(nome), Sostenuto(true), VotoEsame(voto) {}

// Metodo per ottenere il nome dell'esame
std::string Esame::getEsame() {
    return NomeEsame;
}

// Metodo per impostare il nome dell'esame
void Esame::setEsame(std::string nome) {
    NomeEsame = nome;
}

// Metodo per ottenere il voto dell'esame
int Esame::getVoto() {
    return VotoEsame;
}

// Metodo per impostare il voto dell'esame
void Esame::setVoto(int voto) {
    VotoEsame = voto;
    Sostenuto = true;
}

// Metodo per verificare se l'esame è stato sostenuto
bool Esame::isSostenuto() {
    return Sostenuto;
}
