
#include "pitches.h"
#include "melodies.h"


char message[20] = "";
char* instructions[3];
int inc = 0, val = 0, rainVal = 0, lightVal = 0, buzzer = 8, ldr = A0;

void setup() {
  pinMode(ldr, INPUT);
  Serial1.begin(9600);
}

void loop() {
  //------ GET THE MESSAGE -----//
  if (Serial1.available()) {
    char x = Serial1.read();
    // ADD TO MESSAGE INCRIMENTALLY UNTIL HIT THE END
    if (x != '~') {
      message[inc] = x;
      inc ++;
    }
    else {
      Serial.println("MESSAGE:");
      Serial.println(message);
      Serial.println("PARSED");

      char * token = strtok(message, " ");
      // loop through the string to extract all other tokens
      while ( token != NULL ) {
        int val2;
        sscanf(token, "%d", &val2);
        switch (val)
        {
          case 0:
            rainVal = map(val2, 0, 1050, 100, 0);
            break;
          case 2:
            lightVal = map(val2, 0, 50, 0, 100);
            break;
          default:
            break;
        }
        token = strtok(NULL, " ");
        val ++;
      }

      Serial.print("Rain: ");
      Serial.print(rainVal);
      Serial.print(" Light: ");
      Serial.println(lightVal);
      val = 0;
      memset(message, 0, sizeof(message));
      inc = 0;
      //------ START MELODY --------//

      Serial.print("CONDITION: ");
      //------DECIDE CONDITION

      //LIGHT LOW + NO RAIN
      if (lightVal < 50 && rainVal < 30) {
        Serial.println("CLOUDY");
        playMelody(1, 140); // zelda theme
      }
      //LIGHT LOW + SOME RAIN
      else if (lightVal < 50 && rainVal < 60) {
        Serial.println("DRIZZLE");
        playMelody(0, 88); // zeldas lullaby
      }
      //LIGHT LOW + LOTS OF RAIN
      else if (lightVal < 50 && rainVal >= 60) {
        Serial.println("HEAVY RAIN");
        playMelody(4, 85); // jigglypuff song
      }
      //LIGHT HIGH + NO RAIN
      else if (lightVal > 50 && rainVal < 30) {
        Serial.println("SUNNY");
        playMelody(3, 140); // take on me
      }
      //LIGHT HIGH + SOME RAIN
      else if (lightVal > 50 && rainVal < 60) {
        Serial.println("SUMMER SHOWER");
        playMelody(2, 140); // layton theme
      }
      //light high + lots of rain not included as it is very unlikely to occur
      else {
        Serial.println("ERROR");
      }

      serialFlush();
    }
  }
}

void serialFlush() {
  while (Serial1.available() > 0) {
    char t = Serial1.read();
  }
}

void playMelody( int index, int tempo) {
  int brightness = analogRead(ldr);
  Serial.println(brightness);
  if (brightness > 1) {
    int notes = sizes[index] / sizeof(melodies[index][0]) / 2;
    // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
    int wholenote = (60000 * 4) / tempo;

    int divider = 0, noteDuration = 0;

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

      // calculates the duration of each note
      divider = melodies[index][thisNote + 1];
      if (divider > 0) {
        // regular note, just proceed
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        // dotted notes are represented with negative durations!!
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; // increases the duration in half for dotted notes
      }
      Serial.println(melodies[index][thisNote]);
      // we only play the note for 90% of the duration, leaving 10% as a pause
      tone(buzzer, melodies[index][thisNote], noteDuration * 0.9);

      // Wait for the specief duration before playing the next note.
      delay(noteDuration);

      // stop the waveform generation before the next note.
      noTone(buzzer);
    }
  }

  Serial.println("end");
}
