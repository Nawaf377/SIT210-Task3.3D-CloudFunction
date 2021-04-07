int led1= D6; // The Red LED

int led2 = D5;  // The Blue LED



void setup()
{   
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", LightHolder); // sebs will listen to the event 
  
    
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

}

void loop()
{
  
}


void LightHolder(const char *event, const char *data) // when the buddy is publishing an event this function will be called .. data either will be "wave" or "pat"
{
    if (strcmp(data, "wave") == 0) // if detect the wave .. red light will light up 3 times .. 
    {
        for (int i = 0; i < 3; i++ ) 
        {
            digitalWrite(led1,HIGH);
            delay(800);
            digitalWrite(led1,LOW);
            delay(800);
        }
       
        
    }
    else if (strcmp(data, "pat") == 0) // when detect pat .. blue light will light up 4 times but faster than wave  
    {
        
        for (int i = 0; i < 4; i++ ) 
        {
            digitalWrite(led2,HIGH);
            delay(100);
            digitalWrite(led2,LOW);
            delay(100);
        }
       
    }
  
}
