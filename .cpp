
void setup()
{

// setting the mode of timer
  TCCR1B &= ~(1<<WGM13);
   TCCR1B |= (1<<WGM12);
  TCCR1A &= ~(1<<WGM11);
   TCCR1A |= (1<<WGM10); 
  // FAST PWM FOR 8 BITS

// SET PWM MODE
  TCCR1A |= (1<<COM1B1);
  TCCR1A &= ~(1<<COM1B0); // PWM IN NON INVERTING MODE
// SETTING THE PRESCALAR FOR THE TIMER FOR SETTING PWM FREQ

TCCR1B |= (1<<CS10) | (1<<CS11);
TCCR1B &= ~(1<<CS12);   // SETTING PRESCALAR 64
  //CLOCK=16MHZ, LETS TAKE 250 KHZ=16MHZ/64


// Setting PB2 as output
DDRB |= (1<<DDB2);

// SETTING DUTY CYCLE
OCR1B = 0-1023; // ANY VALUE BETWEEN 0-100%
 
}

void loop()
{
  for(int i=0; i<1024; i++){
    OCR1B = i;  
    delay(10); 
  } 
  delay (2000); 
  
}
