## Testing
I have not set up any automated testing since this is a small project. However, the following testing is very comprehensive and should suffice.

#### Character Encoding Correctness
Test each acceptable character using the following string:

`"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789 , . ? \" : ' - / ( )"`.

For the above string, please note that `\"` means `"` but the escape character is required in a C++ string.

Confirm that the buzzer and LED encode each character correctly. Refer to the following from [Merriam-Webster](https://www.merriam-webster.com/dictionary/Morse%20code):

![Morse Code](Images/Morse-Code-Cheat-Sheet.jpg)

#### WPM Accuracy
1. `"PARIS PARIS PARIS "` at 3WPM should take one minute.
2. `"PARIS PARIS PARIS PARIS PARIS PARIS PARIS "` at 7WPM should take one minute.
3. `"PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS "` at 12WPM should take one minute.
4. `"PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS PARIS "` at 21WPM should take one minute.
5. Run the above tests at a faster speed and adjust the expected time accordingly to complete the tests in less time. For example, "PARIS PARIS PARIS " at 9WPM should take 20 seconds. This is because we can multiply the speed by three and divide the expected time by three.

These WPM tests also ensure the program uses the correct timing for rests between dots and dashes, letters, and words.
