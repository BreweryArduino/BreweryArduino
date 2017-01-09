#ifndef DigOut_h
#define DigOut_h

#include <Arduino.h>

class DigOut {
public:
	// Конструктор
	DigOut (const uint8_t pin=13, const bool state=0) {
		pinMode(_pin = pin, OUTPUT);
		(state) ? HI() : LO();
	}
	//	установить уровень
	void DW(const bool state) const {
		digitalWrite(_pin, state);
		/*switch (state){
			case 1:
			switch (_pin) {
	         case 0:
	           PORTD |= (1 << 0);//HI
	          break;
	         case 1:
	           PORTD |= (1 << 1);//HI
	          break;
	         case 2:
	           PORTD |= (1 << 2);//HI
	          break;
	         case 3:
	           PORTD |= (1 << 3);//HI
	          break;
	         case 4:
	           PORTD |= (1 << 4);//HI
	          break;
	         case 5:
	           PORTD |= (1 << 5);//HI
	          break;
	         case 6:
	           PORTD |= (1 << 6);//HI
	          break;
	         case 7:
	           PORTD |= (1 << 7);//HI
	          break;
	         case 8:
	           PORTB |= (1 << 0);//HI
	          break;
	         case 9:
	           PORTB |= (1 << 1);//HI
	          break;
	          case 10:
	           PORTB |= (1 << 2);//HI
	          break;
	         case 11:
	           PORTB |= (1 << 3);//HI
	          break;
	         case 12:
	           PORTB |= (1 << 4);//HI
	          break;
	         case 13:
	           PORTB |= (1 << 5);//HI
	          break;
	         }
			 break;
			 case 0:
              switch (_pin) {
	         case 0:
	           PORTD &= ~((1 << 0));//LO
	          break;
	         case 1:
	           PORTD &= ~((1 << 1));//LO
	          break;
	         case 2:
	           PORTD &= ~((1 << 2));//LO
	          break;
	         case 3:
	           PORTD &= ~((1 << 3));//LO
	          break;
	         case 4:
	           PORTD &= ~((1 << 4));//LO
	          break;
	         case 5:
	           PORTD &= ~((1 << 5));//LO
	          break;
	         case 6:
	           PORTD &= ~((1 << 6));//LO
	          break;
	         case 7:
	           PORTD &= ~((1 << 7));//LO
	          break;
	         case 8:
	           PORTB &= ~((1 << 0));//LO
	          break;
	         case 9:
	           PORTB &= ~((1 << 1));//LO
	          break;
	          case 10:
	           PORTB &= ~((1 << 2));//LO
	          break;
	         case 11:
	           PORTB &= ~((1 << 3));//LO
	          break;
	         case 12:
	           PORTB &= ~((1 << 4));//LO
	          break;
	         case 13:
			   PORTB &= ~((1 << 5));//LO
	          break;
	         }
			 break;
		}*/
	}

	// установить высокий уровень
	void HI(void) const {
		DW(HIGH);
	}

	// установить низкий уровень
	void LO() const {
		DW(LOW);
	}

	// инвертировать выход
	void invert(void) const {
		DW(!state());
	}

	// получить состояние
	bool state(void) const {
		return digitalRead(_pin);
	}

	//импульсы
/*	void blink (unsigned long period,  int impuls)
	{
		  unsigned long cms=millis();
		  bool st = state();
		  if (cms-preMillis>=period){//если интервал прошел
	      preMillis=cms;//сбрасываем
	      }
	      if(cms<impuls+preMillis){//если время высокого уровня не прошло
	        (st==0)?HI():nool();
	      }
	      else//иначе
	      
		  {
	        (st==1)?LO():nool();
	      }
	}*/

		//низкочастотный ШИМ и blink
	void lpwm (unsigned int period,  unsigned int fill, bool pwm=1)
	{
		  unsigned long cms=millis();
		  if (cms-preMillis>=period){//если интервал прошел
	      preMillis=cms;//сбрасываем
	      }
			fill=(pwm==1)?(period/100*fill):fill;
			DW((cms<fill+preMillis)? 1:0);
		/*if(cms<fill+preMillis){//если время высокого уровня не прошло
						HI();
					}
					else//иначе	      
					{
						LO();
					}	*/		  
		/*switch (pwm){//выбор режима
				case 1://режим lpwm
					if(cms<((period/100)*fill)+preMillis){//если время высокого уровня не прошло
						HI();
					}
					else//иначе
					{
						LO();
					}
				break;
				case 0://режим blink
					if(cms<fill+preMillis){//если время высокого уровня не прошло
						HI();
					}
					else//иначе	      
					{
						LO();
					}				
				break;
					}*/
	}
	
	//void nool(){}//заглушка
	
	// Присваивание одного экземпляра другому
	DigOut & operator = (DigOut & original) {
		DW(original.state()); // присвоили состояние
		return *this;	// вернули ссылку
	}

	// Присваивание экземпляру значение типа bool
	bool operator = (const bool newState) {
		DW(newState);
		return newState;
	}

	operator bool(void) {
		return state();	
	}

private:
	uint8_t _pin;	//выходной пин
	unsigned long preMillis;
};
 
#endif
