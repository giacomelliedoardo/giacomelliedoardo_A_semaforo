int VERDE1 = 12;
int GIALLO1 = 10;
int ROSSO1 = 8;
int VERDE2 = 4;
int GIALLO2 = 2;
int ROSSO2 = 0;
//String numLampeggi = "";
//int richiesta = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (VERDE1, OUTPUT);    //VERDE
  pinMode (GIALLO1, OUTPUT);    //GIALLO
  pinMode (ROSSO1, OUTPUT);     //ROSSO
  
  pinMode (VERDE2, OUTPUT);     //VERDE
  pinMode (GIALLO2, OUTPUT);     //GIALLO
  pinMode (ROSSO2, OUTPUT);     //ROSSO
  
  Serial.print("Quanti lampeggi verdi?");
  while(Serial.available == 0){};
  numLampeggi = Serial.readString().toInt();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (VERDE1, HIGH);  //accendo il verde
  digitalWrite (ROSSO2, HIGH);   //accendo il rosso
  delay (5000);
  lampeggia (VERDE1, 500, 4);
  /*if(richiesta == 0)
  {
    richiestaLampeggi();
    lampeggia();
  }*/
  digitalWrite (VERDE1, LOW);   //spengo il verde
  digitalWrite (GIALLO1, HIGH);  //accendo il giallo
  digitalWrite (GIALLO2, HIGH);   //accendo il giallo
  delay (2000);
  digitalWrite (GIALLO1, LOW);   //spengo il giallo
  digitalWrite (ROSSO2, LOW);    //spengo il rosso
  digitalWrite (GIALLO2, LOW);    //spengo il giallo
  delay (0);
  digitalWrite (ROSSO1, HIGH);   //accendo il rosso
  digitalWrite (VERDE2, HIGH);   //accendo il verde
  delay (5000);
  lampeggia (VERDE2, 500, 4);
  /*if(richiesta == 0)
  {
    richiestaLampeggi();
    lampeggia();
  }*/
  digitalWrite (VERDE2, LOW);    //spengo il verde
  digitalWrite (GIALLO2, HIGH);   //accendo il giallo
  digitalWrite (GIALLO1, HIGH);  //accendo il giallo
  delay (2000);
  digitalWrite (GIALLO2, LOW);    //spengo il giallo
  digitalWrite (GIALLO1, LOW);   //spengo il giallo
  digitalWrite (ROSSO1, LOW);    //spengo il rosso
}

void lampeggia(int led, int rit, int a) {  
  for (int i = 0; i <= a; i++){
    delay (rit);
    digitalWrite (led, LOW);
    delay (rit);
    digitalWrite (led, HIGH);
  }

/*void richiestaLampeggi(){
  Serial.print("Quanti lampeggi verdi?");
  while(Serial.available == 0){};
  numLampeggi = Serial.readString().toInt();
}*/

}
