int buzzerPin = 3;  // The pin on the Arduino board connected to the buzzer's data pin.
float wpm = 8.0;  // The Morse Code speed in Words Per Minute.
String string = "Insert";  // The string to play in Morse Code.

int DOT_TIME_UNITS = 1;
int DASH_TIME_UNITS = 3;
int SYMBOL_GAP_TIME_UNITS = 1;
int LETTER_GAP_TIME_UNITS = 3;
int WORD_GAP_TIME_UNITS = 7;

int msPerTimeUnit = 1200.0 / wpm;
int dotTime = DOT_TIME_UNITS * msPerTimeUnit;
int dashTime = DASH_TIME_UNITS * msPerTimeUnit;
int symbolGapTime = SYMBOL_GAP_TIME_UNITS * msPerTimeUnit;
int letterGapTime = LETTER_GAP_TIME_UNITS * msPerTimeUnit;
int wordGapTime = WORD_GAP_TIME_UNITS * msPerTimeUnit;

/**
 * Setup the buzzer control pin and play the string in Morse Code.
 */
void setup() {
    pinMode(buzzerPin, OUTPUT);
    digitalWrite(buzzerPin, LOW);
    
    play_string(string);
}

/**
 * This function must remain for the sketch to compile.
 */
void loop() {

}

void play_string(String s) {
    bool prevCharWasLetter = false;
    for (uint8_t i = 0; i < s.length(); i++) {  // Compiler warning said to use an unsigned integer since s.length() is unsigned.
        if (s[i] != ' ') {
            if (prevCharWasLetter) {
                play_letter_gap();
            }
            
            prevCharWasLetter = true;
            play_character(s[i]);
        } else {
            prevCharWasLetter = false;
            play_word_gap();
        }
    }
}

void play_character(char c) {
    String morseCode = translate_to_morse_code(c);
    bool firstCharacter = true;

    for (char c : morseCode) {
        if (firstCharacter) {
            firstCharacter = false;
        } else {
            play_symbol_gap();
        }
        
        if (c == '.') {
            play_dot();
        } else {
            play_dash();
        }
    }
}

void play_dot() {
    digitalWrite(buzzerPin, HIGH);
    delay(dotTime);
    digitalWrite(buzzerPin, LOW);
}

void play_dash() {
    digitalWrite(buzzerPin, HIGH);
    delay(dashTime);
    digitalWrite(buzzerPin, LOW);
}

void play_symbol_gap() {
    delay(symbolGapTime);
}

void play_letter_gap() {
    delay(letterGapTime);
}

void play_word_gap() {
    delay(wordGapTime);
}

/**
 * Translates a character into Morse Code.
 * 
 * @param c The character to translate into Morse Code. The character can be any uppercase or lwoercase letter, any
 * digit, or one of the following special characters: , . ? " : ' - / ( ). If the character does not match one of these
   characters, this function will return an empty string.
 * 
 * @return A string of fullstops (dots) and hyphens (dashes) representing the Morse Code.
 */
String translate_to_morse_code(char c) {
    if (c == 'A' || c == 'a') {
        return ".-";
    } else if (c == 'B' || c == 'b') {
        return "-...";
    } else if (c == 'C' || c == 'c') {
        return "-.-.";
    } else if (c == 'D' || c == 'd') {
        return "-..";
    } else if (c == 'E' || c == 'e') {
        return ".";
    } else if (c == 'F' || c == 'f') {
        return "..-.";
    } else if (c == 'G' || c == 'g') {
        return "--.";
    } else if (c == 'H' || c == 'h') {
        return "....";
    } else if (c == 'I' || c == 'i') {
        return "..";
    } else if (c == 'J' || c == 'j') {
        return ".---";
    } else if (c == 'K' || c == 'k') {
        return "-.-";
    } else if (c == 'L' || c == 'l') {
        return ".-..";
    } else if (c == 'M' || c == 'm') {
        return "--";
    } else if (c == 'N' || c == 'n') {
        return "-.";
    } else if (c == 'O' || c == 'o') {
        return "---";
    } else if (c == 'P' || c == 'p') {
        return ".--.";
    } else if (c == 'Q' || c == 'q') {
        return "--.-";
    } else if (c == 'R' || c == 'r') {
        return ".-.";
    } else if (c == 'S' || c == 's') {
        return "...";
    } else if (c == 'T' || c == 't') {
        return "-";
    } else if (c == 'U' || c == 'u') {
        return "..-";
    } else if (c == 'V' || c == 'v') {
        return "...-";
    } else if (c == 'W' || c == 'w') {
        return ".--";
    } else if (c == 'X' || c == 'x') {
        return "-..-";
    } else if (c == 'Y' || c == 'y') {
        return "-.--";
    } else if (c == 'Z' || c == 'z') {
        return "--..";
    } else if (c == '0') {
        return "-----";
    } else if (c == '1') {
        return ".----";
    } else if (c == '2') {
        return "..---";
    } else if (c == '3') {
        return "...--";
    } else if (c == '4') {
        return "....-";
    } else if (c == '5') {
        return ".....";
    } else if (c == '6') {
        return "-....";
    } else if (c == '7') {
        return "--...";
    } else if (c == '8') {
        return "---..";
    } else if (c == '9') {
        return "----.";
    } else if (c == ',') {
        return "--..--";
    } else if (c == '.') {
        return ".-.-.-";
    } else if (c == '?') {
        return "..--..";
    } else if (c == '"') {
        return ".-..-.";
    } else if (c == ':') {
        return "---...";
    } else if (c == "'"[0]) {  // Extract an apostrophe in character form.
        return ".----.";
    } else if (c == '-') {
        return "-....-";
    } else if (c == '/') {
        return "-..-.";
    } else if (c == '(') {
        return "-.--.";
    } else if (c == ')') {
        return "-.--.-";
    } else {
        return "";
    }
}
