#include "Studente.h"
#include <iostream>
#include <stdexcept>

Studente::Studente() : NumEsami(5) {
    Matricola = "";
    Nome = "";
    for (int i = 0; i < NumEsami; i++) {
        Esami.push_back(Esame());
    }
}

Studente::Studente(std::string nome1, std::string nome2, std::string nome3, std::string nome4, std::string nome5) : NumEsami(5) {
    Matricola = "";
    Nome = "";
    Esami.push_back(Esame(nome1));
    Esami.push_back(Esame(nome2));
    Esami.push_back(Esame(nome3));
    Esami.push_back(Esame(nome4));
    Esami.push_back(Esame(nome5));
}

void Studente::setMatricola(std::string matricola) {
    Matricola = matricola;
}

void Studente::setNome(std::string nome) {
    Nome = nome;
}

std::string Studente::getMatricola() {
    return Matricola;
}

std::string Studente::getNome() {
    return Nome;
}

int Studente::getNumEsami() {
    return NumEsami;
}

void Studente::setEsame(int voto, int i) {
    if (i >= 0 && i < NumEsami) {
        Esami[i].setVoto(voto);
    }
}

int Studente::getVotoEsame(int i) {
    if (i >= 0 && i < NumEsami) {
        return Esami[i].getVoto();
    }
    throw std::out_of_range("Index out of bounds");
}

std::string Studente::getNomeEsame(int i) {
    if (i >= 0 && i < NumEsami) {
        return Esami[i].getEsame();
    }
    throw std::out_of_range("Index out of bounds");
}

bool Studente::getSostenuto(int i) {
    if (i >= 0 && i < NumEsami) {
        return Esami[i].isSostenuto();
    }
    throw std::out_of_range("Index out of bounds");
}

double Studente::getMedia() {
    double media = 0;
    int esamiSostenuti = 0;

    for (int i = 0; i < NumEsami; i++) {
        if (Esami[i].isSostenuto()) {
            media += Esami[i].getVoto();
            esamiSostenuti++;
        }
    }

    if (esamiSostenuti > 0) {
        media /= esamiSostenuti;
    }

    return media;
}

void Studente::printStudente() {
    std::cout << "Matricola: " << Matricola << std::endl;
    std::cout << "Nome: " << Nome << std::endl;

    for (int i = 0; i < NumEsami; i++) {
        std::cout << "Esame " << i + 1 << ": " << Esami[i].getEsame();
        if (Esami[i].isSostenuto()) {
            std::cout << ", Voto: " << Esami[i].getVoto();
        } else {
            std::cout << ", Non sostenuto";
        }
        std::cout << std::endl;
    }

    std::cout << "Media: " << getMedia() << std::endl;
}
