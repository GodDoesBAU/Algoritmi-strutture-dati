#ifndef _MULTSTACK_
#define _MULTSTACK_
#define StackMAX 10


template<class T>
class MultipleStack;

template <class tipoelem>
class Coda {
    friend class MultipleStack<tipoelem>;
public:
  Coda(int n) {
    maxlung = n;
    creaCoda();
  }

  ~Coda() {
    delete[] elementi;
  }

  void creaCoda() {
    elementi = new tipoelem[maxlung];
    testa = 0;
    lung = 0;
  }

  Coda<tipoelem> clone() const {
    Coda<tipoelem> clonedCoda(maxlung);
    for (int i = 0; i < lung; ++i) {
      clonedCoda.inCoda(elementi[(testa + i) % maxlung]);
    }
    return clonedCoda;
  }

  Coda<int> rimuovi_Negativi() const {
    Coda<int> positiveQueue(maxlung);
    for (int i = 0; i < lung; ++i) {
      if (elementi[(testa + i) % maxlung] > 0) {
        positiveQueue.inCoda(elementi[(testa + i) % maxlung]);
      }
    }
    return positiveQueue;
  }

  bool codaVuota() const {
    return (lung == 0);
  }

  tipoelem leggiCoda() const {
    if (!codaVuota())
      return (elementi[testa]);
  }

  void fuoriCoda() {
    if (!codaVuota()) {
      testa = (testa + 1) % maxlung;
      lung--;
    }
  }

  void inCoda(tipoelem a) {
    if (lung != maxlung) {
      elementi[(testa + lung) % maxlung] = a;
      lung++;
    }
  }

private:
  tipoelem *elementi;
  int testa, lung, maxlung;


};

template < class T >
class MultipleStack
{
    public:
        MultipleStack (unsigned int stack_len){
            this->StackNumber = stack_len;
            this->stack_array = new Coda<T>[stack_len];
            for(int i=0; i < stack_len; i++){
                this->stack_array[i] = Coda<T>(StackMAX);
            }
        }

        void Push (T element, unsigned int stack_index){
            if (stack_index > this->StackNumber)
            {
              throw std::invalid_argument("Index out of bound");
            }

            Coda<T> scelta = this->stack_array[stack_index];
            scelta.inCoda(element);
        }

        T Pop (unsigned int stack_index){
            if (stack_index > this->StackNumber)
            {
              throw std::invalid_argument("Index out of bound");
            }
            
            Coda<T> scelta = this->stack_array[stack_index];
            scelta.fuoriCoda();
        }

        void leggi_tutti(){
          for(int i=0;i<StackNumber; i++){
            Coda<T> stack = this->stack_array[i];
            stack.leggiCoda();
          }
        }

    private:
        unsigned int StackNumber;
        Coda<T>* stack_array;

};

#endif