#include <vector>
#include "Studente.h"


#define N_OF_STUDENTS 3

//USEFULL FOR TESTING 
std::string generaNomeEsame() {
    // Array di parole casuali
    std::string parole1[] = { "Matematica", "Fisica", "Chimica", "Ingegneria", "Storia", "Biologia", "Arte" };
    std::string parole2[] = { "Avanzata", "Teorica", "Applicata", "Moderna", "Antica", "Organica", "Contemporanea" };

    // Calcola la lunghezza degli array
    int lunghezza1 = sizeof(parole1) / sizeof(parole1[0]);
    int lunghezza2 = sizeof(parole2) / sizeof(parole2[0]);

    // Genera due indici casuali
    int indice1 = rand() % lunghezza1;
    int indice2 = rand() % lunghezza2;

    // Combina le due parole casuali per creare il nome dell'esame
    std::string nomeEsame = parole1[indice1] + " " + parole2[indice2];

    return nomeEsame;
}

int generaVoto() {
    // Genera un voto casuale tra 18 e 30
    int voto = 18 + std::rand() % 13;

    return voto;
}

std::string generaNomeStudente() {
    // Array di nomi e cognomi casuali
    std::string nomi[] = { "Mario", "Luigi", "Sofia", "Maria", "Giovanni", "Francesca", "Luca" };
    std::string cognomi[] = { "Rossi", "Bianchi", "Verdi", "Russo", "Ferrari", "Esposito", "Mancini" };

    // Calcola la lunghezza degli array
    int lunghezzaNomi = sizeof(nomi) / sizeof(nomi[0]);
    int lunghezzaCognomi = sizeof(cognomi) / sizeof(cognomi[0]);

    // Genera due indici casuali
    int indiceNome = std::rand() % lunghezzaNomi;
    int indiceCognome = std::rand() % lunghezzaCognomi;

    // Combina il nome e il cognome casuali per creare il nome dello studente
    std::string nomeStudente = nomi[indiceNome] + " " + cognomi[indiceCognome];

    return nomeStudente;
}

Studente generaStudente_no_exam(){
    // Crea uno studente con il costruttore di default
    Studente studente;

    // Imposta il nome dello studente
    std::string nomeStudente = generaNomeStudente();
    studente.setNome(nomeStudente);

    // Genera voti casuali per ciascun esame
    for (int i = 0; i < studente.getNumEsami(); i++) {
        int voto = generaVoto(); // Genera un voto casuale
        studente.setEsame(voto, i);
    }

    return studente;
}

Studente generaStudente_withExam(){
    // Crea uno studente con il costruttore di default
    Studente studente = Studente(generaNomeEsame(),generaNomeEsame(),generaNomeEsame(),generaNomeEsame(),generaNomeEsame());

    std::string nomeStudente = generaNomeStudente();
    studente.setNome(nomeStudente);

    for (int i = 0; i < studente.getNumEsami(); i++) {
        int voto = generaVoto();
        studente.setEsame(voto, i);
    }

    return studente;
}

std::vector<Studente> generaStudenti(int to_create){
    std::vector<Studente> new_students;
    for (int i = 0; i < to_create; i++)
        if (i%2 == 0)
            new_students.push_back(generaStudente_no_exam());
        else
            new_students.push_back(generaStudente_withExam());
        
    return new_students;
}


/*                              MAIN                               */

int main()
{
    std::vector<Studente> test_set = generaStudenti(N_OF_STUDENTS);
    for (Studente test : test_set){
        test.printStudente();
    }
    return 0;
}