#pragma once

enum Digit {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum Operation {ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQUARE_ROOT, PERCENTAGE, NONE};
enum Control {CLEAR, RESET, DECIMAL_SEPARATOR, MEMORY_READ_CLEAR, MEMORY_ADDITION, MEMORY_SUBTRACTION, EQUAL};
enum Signal {POSITIVE, NEGATIVE};

class Display{
  public:
    virtual void add(Digit ) = 0;
    virtual void setDecimalSeparator() = 0;
    virtual void setSignal(Signal ) = 0;
    virtual void setError() = 0;
    virtual void clear() = 0;
};

class Receiver{
  public:
    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;

};
class Cpu: public Receiver{
  protected:
    Display* display;

  public:
    void setDisplay(Display* );

    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;
};


class Key{
   protected:
     Receiver* receiver;
   public:
      void setReceiver(Receiver* );

      virtual void press() = 0;
};

class KeyDigit: public Key{
  protected:
     Digit digit;
  public:
      KeyDigit(Digit );
      void press();
};

class KeyOperation: public Key{
  protected:
     Operation operation;
   public:
      KeyOperation(Operation );
      void press();
};

class KeyControl: public Key{
  protected:
     Control control;
   public:
      KeyControl(Control );
      void press();
};

class Keyboard: public Receiver{
  protected:
   Cpu* cpu;
  public:
    void setCpu(Cpu* );

    virtual bool addKey(Key* ) = 0;
    virtual bool removeKey(Key* ) = 0;
    virtual KeyDigit* queryKeyDigit(Digit ) = 0;
 
    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;
};

class Calculator{
  public:
    virtual void setDisplay(Display* ) = 0;
    virtual Display* getDisplay() = 0;

    virtual void setCpu(Cpu* ) = 0;
    virtual Cpu* getCpu() = 0;
    
    virtual void setKeyboard(Keyboard* ) = 0;
    virtual Keyboard* setKeyboard() = 0;
};
