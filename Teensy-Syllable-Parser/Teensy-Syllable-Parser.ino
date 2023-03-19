// This program syllabifies words based on the Sonority Sequencing Principle (SSP)
// Originally created at UC Berkeley 2015
// Original Authors: Christopher Hench & Alex Estes © 2016
// Ported from https://github.com/finguist/syllabipy
// to work on a Teensy 4.0 Arduino by Walter Dunckel
// Example word entry justification - jus-ti-fi-ca-tion - j0u5s2t0i5f2i5c0a5t0i5o5n3


String word_entry = "justification";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  String vowels = "aeiouy";
  String nasals = "lmnrw";
  String fricatives = "zvsf";
  String affricates = "";
  String stops = "bcdgtkpqxhj";
  String approximates = "";
  String syllable = "";
  int syllableCount = 0;
  int vowelCount = 0; //
  String final_sylset = "";
  char letter;
  int i = 0;
  String sylset = "";  //to collect letters and corresponding values

  // assign numerical values to phonemes (characters)
  for (i = 0; i<(word_entry.length()); i++)  {
    letter = word_entry.charAt(i);
    if (vowels.indexOf(letter) != -1) {
      sylset.concat(letter);
      sylset.concat(5);
      vowelCount++;
    } else if (approximates.indexOf(letter) != -1) {
        sylset.concat(letter);
        sylset.concat(4);
    } else if (nasals.indexOf(letter) != -1) {
        sylset.concat(letter);
        sylset.concat(3);     
    } else if (fricatives.indexOf(letter) != -1) {
        sylset.concat(letter);
        sylset.concat(2);     
    } else if (affricates.indexOf(letter) != -1) {
        sylset.concat(letter);
        sylset.concat(1);
    } else {
        sylset.concat(letter);
        sylset.concat(0);  
    }
  }

  // SSP syllabification follows
  if (vowelCount == 1)  { //finalize word immediately if monosyllabic
    final_sylset.concat(word_entry);
    syllableCount = 1;
  }
  if (vowelCount != 1)  {
    syllable = "";    //prepare empty sylable to build upon
    for (i = 0; i<(sylset.length()); i=i+2)  {
      letter = sylset.charAt(i);
      if (i == 0) {   //if its the first letter, append (concat) immediately
        syllable.concat(letter);
        syllableCount++;
      } else {
        //add whatever is remaining at end of word, last letter 
        if (i == sylset.length() -1)  {
          syllable.concat(letter);
          final_sylset.concat(syllable);

        //MAIN ALGORITHM BELOW

        //these cases DO NOT trigger syllable breaks
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) < sylset.charAt(i+3)) && (sylset.charAt(i+1) > sylset.charAt(i-1))) {
            syllable.concat(letter);
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) > sylset.charAt(i+3)) && (sylset.charAt(i+1) < sylset.charAt(i-1))) {
            syllable.concat(letter);
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) > sylset.charAt(i+3)) && (sylset.charAt(i+1) > sylset.charAt(i-1))) {
            syllable.concat(letter);    
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) > sylset.charAt(i+3)) && (sylset.charAt(i+1) == sylset.charAt(i-1))) {
            syllable.concat(letter);   
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) == sylset.charAt(i+3)) && (sylset.charAt(i+1) > sylset.charAt(i-1))) {
            syllable.concat(letter);  
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) < sylset.charAt(i+3)) && (sylset.charAt(i+1) == sylset.charAt(i-1))) {
            syllable.concat(letter);    

        // These cases DO trigger a syllable break
        // if phoneme value is equal to the value of the preceeding AND following phoneme
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) == sylset.charAt(i+3)) && (sylset.charAt(i+1) == sylset.charAt(i-1))) {
            //append and break syllable BEFORE appending letter at index in new syllable
            syllable.concat(letter);   
            final_sylset.concat(syllable);
            syllable = "-"; //
            syllableCount++;
        // if phoneme value is less than preceeding value and following value
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) < sylset.charAt(i+3)) && (sylset.charAt(i+1) < sylset.charAt(i-1))) {
            // append and break syllable BEFORE appending letter at index in new syllable
            final_sylset.concat(syllable);
            syllable = "-"; //
            syllable.concat(letter);
            syllableCount++;
        // if phoneme value is less than preceeding value and equal to following value
        } else if ((i < sylset.length() -1) && (sylset.charAt(i+1) == sylset.charAt(i+3)) && (sylset.charAt(i+1) < sylset.charAt(i-1))) {
            //append and break syllable BEFORE appending letter at index in new syllable
            syllable.concat(letter);   
            final_sylset.concat(syllable);
            syllable = "-"; //    
            syllableCount++;
        }
      }
    }
  }
  final_sylset.concat(syllable);
  Serial.println(final_sylset); 
  Serial.println(sylset); //Shows letters and values assigned to each
  Serial.println(syllableCount); 
  
}  //end of setup

void loop() {
  delay(2000);
}




