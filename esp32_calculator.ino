#include <LiquidCrystal.h>
#include <Keypad.h>

// LCD Pins: RS,E,D4,D5,D6,D7
LiquidCrystal lcd(23,22,21,19,18,5);

// Keypad
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS]={13,12,14,27};
byte colPins[COLS]={26,25,33,32};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

String num1="";
String num2="";
char op='\0';
bool secondNumber=false;

void setup()
{
  Serial.begin(115200);

  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Calculator");
  delay(1500);
  lcd.clear();
}

void loop()
{
  char key=keypad.getKey();

  if(key)
  {
    Serial.print("Key : ");
    Serial.println(key);

    // Number
    if(key>='0' && key<='9')
    {
      if(!secondNumber)
      {
        num1+=key;
      }
      else
      {
        num2+=key;
      }
    }

    // Operators
    else if(key=='A')
    {
      op='+';
      secondNumber=true;
    }

    else if(key=='B')
    {
      op='-';
      secondNumber=true;
    }

    else if(key=='C')
    {
      op='*';
      secondNumber=true;
    }

    else if(key=='D')
    {
      op='/';
      secondNumber=true;
    }

    // Equals
    else if(key=='#')
    {
      float a=num1.toFloat();
      float b=num2.toFloat();
      float ans=0;

      switch(op)
      {
        case '+':
          ans=a+b;
          break;

        case '-':
          ans=a-b;
          break;

        case '*':
          ans=a*b;
          break;

        case '/':
          if(b!=0)
            ans=a/b;
          else
          {
            lcd.clear();
            lcd.print("Divide Error");
            delay(2000);
            num1="";
            num2="";
            secondNumber=false;
            op='\0';
            lcd.clear();
            return;
          }
          break;
      }

      lcd.clear();

      lcd.print(a);
      lcd.print(op);
      lcd.print(b);

      lcd.setCursor(0,1);
      lcd.print("=");
      lcd.print(ans);

      Serial.print("Answer = ");
      Serial.println(ans);

      delay(4000);

      num1="";
      num2="";
      secondNumber=false;
      op='\0';
      lcd.clear();
    }

    // Clear
    else if(key=='*')
    {
      num1="";
      num2="";
      secondNumber=false;
      op='\0';

      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
    }

    // Display Input
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);

    lcd.print(num1);

    if(op!='\0')
      lcd.print(op);

    lcd.print(num2);
  }
}