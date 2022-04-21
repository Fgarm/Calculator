enum Digit {ZERO, ONE, TWO, THRE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum Operation {ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQUARE_ROOT, PERCENTAGE};
enum Control {CLEAR, RESET, DECIMAL_SEPARATOR, MEMORY_READ_CLEAR, MEMORY_ADDITION, MEMORY_SUBTRACTION, EQUAL};
enum Signal {POSITIVE, NEGATIVE};

<<<<<<< HEAD
class Display{
  public:
    virtual void add(Digit ) = 0;
    virtual void setDecimalSeparator() = 0;
    virtual void setSignal(Signal ) = 0;
    virtual void setError() = 0;
    virtual void clear() = 0;
=======
#define MAX_DIGITS 8

enum Digit
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
};
enum Operation
{
	ADDITION,
	SUBTRACTION,
	DIVISION,
	MULTIPLICATION,
	SQUARE_ROOT,
	PERCENTAGE,
	NONE
};
enum Control
{
	CLEAR,
	RESET,
	DECIMAL_SEPARATOR,
	MEMORY_READ_CLEAR,
	MEMORY_ADDITION,
	MEMORY_SUBTRACTION,
	EQUALS
};
enum Signal
{
	POSITIVE,
	NEGATIVE
>>>>>>> ffde97cc0e039d568d96355c55c5e84da62e6119
};

class Receiver{
  public:
    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;

};
class Cpu: public Receiver{
  Display* display;
  Cpu* cpu;
  Keyboard* keyboard;

  public:
    void setDisplay(Display* );

    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;
};

class Key; // Preset for early reference

class Keyboard: public Receiver{
   Cpu* cpu;
   public:
      void setCpu(Cpu* );

      virtual void addKey(Key* ) = 0;

      virtual void receiveDigit(Digit ) = 0;
      virtual void receiveOperation(Operation ) = 0;
      virtual void receiveControl(Control ) = 0;
};

class Calculator{
  public:
    virtual void setDisplay(Display* ) = 0;
    virtual void setCpu(Cpu* ) = 0;
    virtual void setKeyboard(Keyboard* ) = 0;
};

class Key{
   protected:
     Receiver* receiver;
   public:
      void setReceiver(Receiver* );

      virtual void press() = 0;
};

class KeyDigit: virtual public Key{
     Digit digit;
   public:
      KeyDigit(Digit );
      void press();
};

class KeyOperation: virtual public Key{
     Operation operation;
   public:
      KeyOperation(Operation );
      void press();
};

class KeyControl: virtual public Key{
     Control control;
   public:
      KeyControl(Control );
      void press();
};