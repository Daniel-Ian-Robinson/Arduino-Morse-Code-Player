int buzzerPin = 11;
int timeScale = 50;
String string = "PARIS ";

int timeUnits = 0;

int dotTime = 1;
int dashTime = 3;
int symbolGap = 1;  // Same as dot time.
int letterGap = 3;
int wordGap = 7;

void setup() {
    Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT);
    digitalWrite(buzzerPin, LOW);

    dotTime *= timeScale;
    dashTime *= timeScale;
    symbolGap *= timeScale;
    letterGap *= timeScale;
    wordGap *= timeScale;

    play_string(string);
    Serial.println(timeUnits);
}

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
    timeUnits += 1;
    delay(dotTime);
    digitalWrite(buzzerPin, LOW);
}

void play_dash() {
    digitalWrite(buzzerPin, HIGH);
    timeUnits += 3;
    delay(dashTime);
    digitalWrite(buzzerPin, LOW);
}

void play_symbol_gap() {
    timeUnits += 1;
    delay(symbolGap);
}

void play_letter_gap() {
    timeUnits += 3;
    delay(letterGap);
}

void play_word_gap() {
    timeUnits += 7;
    delay(wordGap);
}

String translate_to_morse_code(char c) {
    if (c == 'A' || c == 'a') {
        return ".-";
    }
    else if (c == 'B' || c == 'b') {
        return "-...";
    }
    else if (c == 'C' || c == 'c') {
        return "-.-.";
    }
    else if (c == 'D' || c == 'd') {
        return "-..";
    }
    else if (c == 'E' || c == 'e') {
        return ".";
    }
    else if (c == 'F' || c == 'f') {
        return "..-.";
    }
    else if (c == 'G' || c == 'g') {
        return "--.";
    }
    else if (c == 'H' || c == 'h') {
        return "....";
    }
    else if (c == 'I' || c == 'i') {
        return "..";
    }
    else if (c == 'J' || c == 'j') {
        return ".---";
    }
    else if (c == 'K' || c == 'k') {
        return "-.-";
    }
    else if (c == 'L' || c == 'l') {
        return ".-..";
    }
    else if (c == 'M' || c == 'm') {
        return "--";
    }
    else if (c == 'N' || c == 'n') {
        return "-.";
    }
    else if (c == 'O' || c == 'o') {
        return "---";
    }
    else if (c == 'P' || c == 'p') {
        return ".--.";
    }
    else if (c == 'Q' || c == 'q') {
        return "--.-";
    }
    else if (c == 'R' || c == 'r') {
        return ".-.";
    }
    else if (c == 'S' || c == 's') {
        return "...";
    }
    else if (c == 'T' || c == 't') {
        return "-";
    }
    else if (c == 'U' || c == 'u') {
        return "..-";
    }
    else if (c == 'V' || c == 'v') {
        return "...-";
    }
    else if (c == 'W' || c == 'w') {
        return ".--";
    }
    else if (c == 'X' || c == 'x') {
        return "-..-";
    }
    else if (c == 'Y' || c == 'y') {
        return "-.--";
    }
    else if (c == 'Z' || c == 'z') {
        return "--..";
    }
    else if (c == '0') {
        return "-----";
    }
    else if (c == '1') {
        return ".----";
    }
    else if (c == '2') {
        return "..---";
    }
    else if (c == '3') {
        return "...--";
    }
    else if (c == '4') {
        return "....-";
    }
    else if (c == '5') {
        return ".....";
    }
    else if (c == '6') {
        return "-....";
    }
    else if (c == '7') {
        return "--...";
    }
    else if (c == '8') {
        return "---..";
    }
    else if (c == '9') {
        return "----.";
    }
    else if (c == ',') {
        return "--..--";
    }
    else if (c == '.') {
        return ".-.-.-";
    }
    else if (c == '?') {
        return "..--..";
    }
    else if (c == '"') {
        return ".-..-.";
    }
    else if (c == ':') {
        return "---...";
    }
    else if (c == "'"[0]) {  // Gets the apostrophe at index 0 in the string.
        return ".----.";
    }
    else if (c == '-') {
        return "-....-";
    }
    else if (c == '/') {
        return "-..-.";
    }
    else if (c == '(') {
        return "-.--.";
    }
    else if (c == ')') {
        return "-.--.-";
    }
    else {
        return "";
    }
}
