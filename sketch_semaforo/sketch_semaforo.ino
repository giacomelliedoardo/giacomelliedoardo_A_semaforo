void setup() {
  // put your setup code here, to run once:
  pinMode (12, OUTPUT);    //VERDE
  pinMode (10, OUTPUT);    //GIALLO
  pinMode (8, OUTPUT);     //ROSSO
  pinMode (4, OUTPUT);     //VERDE
  pinMode (2, OUTPUT);     //GIALLO
  pinMode (0, OUTPUT);     //ROSSO
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (12, HIGH);  //accendo il verde
  digitalWrite (0, HIGH);   //accendo il rosso
  delay (5000);
  lampeggia(12, 500, 4);    //faccio lampeggiare il verde 4 volte per 0,5 sec
  digitalWrite (12, LOW);   //spengo il verde
  digitalWrite (10, HIGH);  //accendo il giallo
  digitalWrite (2, HIGH);   //accendo il giallo
  delay (2000);
  digitalWrite (10, LOW);   //spengo il giallo
  digitalWrite (0, LOW);    //spengo il rosso
  digitalWrite (2, LOW);    //spengo il giallo
  delay (0);
  digitalWrite (8, HIGH);   //accendo il rosso
  digitalWrite (4, HIGH);   //accendo il verde
  delay (5000);
  lampeggia(4, 500, 4);     //faccio lampeggiare il verde 4 volte per 0,5 sec
  digitalWrite (4, LOW);    //spengo il verde
  digitalWrite (2, HIGH);   //accendo il giallo
  digitalWrite (10, HIGH);  //accendo il giallo
  delay (2000);
  digitalWrite (2, LOW);    //spengo il giallo
  digitalWrite (10, LOW);   //spengo il giallo
  digitalWrite (8, LOW);    //spengo il rosso
}

void lampeggia(int led, int rit, int a) {  
  for (int i = 0; i <= a; i++){
    delay (rit);
    digitalWrite (led, LOW);
    delay (rit);
    digitalWrite (led, HIGH);
  }
}
