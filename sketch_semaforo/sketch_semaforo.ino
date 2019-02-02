int VERDE1 = 12;
int GIALLO1 = 10;
int ROSSO1 = 8;
int VERDE2 = 6;
int GIALLO2 = 4;
int ROSSO2 = 2;
//variabili input
int numLampeggi = 0;
int tempoLampeggi = 0;
int verdeHigh = 0;
int gialloHigh = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (VERDE1, OUTPUT);    //VERDE
  pinMode (GIALLO1, OUTPUT);    //GIALLO
  pinMode (ROSSO1, OUTPUT);     //ROSSO
  
  pinMode (VERDE2, OUTPUT);     //VERDE
  pinMode (GIALLO2, OUTPUT);     //GIALLO
  pinMode (ROSSO2, OUTPUT);     //ROSSO

  Serial.begin(9600);
  
  // input lampeggi verdi
  Serial.println("Quanti lampeggi verdi?");
  while(Serial.available() == 0){};
  numLampeggi = Serial.readString().toInt();

  // input durata lampeggi
  Serial.println("Quanto durano i lampeggi?");
  while(Serial.available() == 0){};
  tempoLampeggi = Serial.readString().toInt();
  
  // input tempo accensione verde
  Serial.println("Quanto resta acceso il verde?");
  while(Serial.available() == 0){};
  verdeHigh = Serial.readString().toInt();
  
  // input tempo accensione giallo
  Serial.println("Quanto resta acceso il giallo?");
  while(Serial.available() == 0){};
  gialloHigh = Serial.readString().toInt();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (VERDE1, HIGH); 
  digitalWrite (ROSSO2, HIGH);   
  delay (verdeHigh);

  lampeggia1();
  digitalWrite (VERDE1, LOW);
  digitalWrite (GIALLO1, HIGH);  
  digitalWrite (GIALLO2, HIGH);   
  delay (gialloHigh);
  digitalWrite (GIALLO1, LOW);      
  digitalWrite (GIALLO2, LOW);   
  digitalWrite (ROSSO2, LOW);
  digitalWrite (ROSSO1, HIGH);   
  digitalWrite (VERDE2, HIGH);
  
  delay (verdeHigh);
  
  lampeggia2();
  digitalWrite (VERDE2, LOW);

  digitalWrite (GIALLO2, HIGH); 
  digitalWrite (GIALLO1, HIGH);
  digitalWrite (ROSSO1, HIGH); 
  delay (gialloHigh);
  
  digitalWrite (GIALLO2, LOW);  
  digitalWrite (GIALLO1, LOW);   
  digitalWrite (ROSSO1, LOW);  
}

void lampeggia1() {  
  for (int i = 0; i <= numLampeggi; i++){
    delay (tempoLampeggi);
    digitalWrite (VERDE1, LOW);
    delay (tempoLampeggi);
    digitalWrite (VERDE1, HIGH);
  }
}

void lampeggia2() {  
  for (int i = 0; i <= numLampeggi; i++){
    delay (tempoLampeggi);
    digitalWrite (VERDE2, LOW);
    delay (tempoLampeggi);
    digitalWrite (VERDE2, HIGH);
  }
}
