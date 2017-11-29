//  Project 3:  Keyboard Koding

#include <iostream>
#include <string>

using namespace std;

char encodeNote(int octave, char noteLetter, char accidentalSign);

const char END_OF_BEAT = '/';
const int DEFAULT_OCTAVE = 4;

//*************************************
//  hasCorrectSyntax
//*************************************

bool hasCorrectSyntax(string song)
{
      // An empty song is well-formed.

    if (song.size() == 0)
        return true;

      // A non-empty song must end with an end-of-beat marker.

    if (song[song.size()-1] != END_OF_BEAT)
        return false;

      // At this point, we know the song ends properly, so in the following
      // loop, we do not have to worry about, say, there not being a character
      // following a digit.

      // Each iteration of the loop recognizes one beat.

    int k = 0;
    while (k != song.size())
    {
          // Each iteration of the loop recognizes one note

        while (song[k] != END_OF_BEAT)
        {
              // Verify note letter

            char note = song[k];
            if (note != 'A' && note != 'B' && note != 'C' && note != 'D' &&
                               note != 'E' && note != 'F' && note != 'G')
                return false;
            k++;

              // Verify possible accidental

            if (song[k] == '#'  ||  song[k] == 'b')
                k++;

              // Verify possible octave

            if (isdigit(song[k]))
                k++;
        }

          // Advance past end of beat.

        k++;
    }

      // We get here if we got through the song without a problem.

    return true;
}

//*************************************
//  encodeSong
//*************************************

int encodeSong(string song, string& instructions, int& badBeat)
{
      // Define return values

    const int RET_OK              = 0;
    const int RET_NOT_WELL_FORMED = 1;
    const int RET_UNPLAYABLE_NOTE = 2;

      // A song that is not well-formed is not encodable.

    if (!hasCorrectSyntax(song))
        return RET_NOT_WELL_FORMED;

      // We will build the encoding in the string named result, and
      // modify the instructions parameter only if the entire encoding
      // succeeds.

    string result;

      // Each iteration of the loop encodes one beat.

    int k = 0;
    for (int beatNumber = 1; k != song.size(); beatNumber++)
    {
          // A beat with no note is encoded as a space

        if (song[k] == END_OF_BEAT)
        {
            result += ' ';
            k++;
            continue;
        }

          // The beat has at least one note if we get here.  Each iteration
          // of the loop processes one note

        int noteCount = 0;
        
        while (song[k] != END_OF_BEAT)
        {
            noteCount++;

              // Record note letter

            char noteLetter = song[k];
            k++;

              // Record accidental sign, if any

            char accidentalSign = ' ';
            if (song[k] == '#'  ||  song[k] == 'b')
            {
                accidentalSign = song[k];
                k++;
            }

              // Record octave number, if any

            int octave = DEFAULT_OCTAVE;
            if (isdigit(song[k]))
            {
                octave = song[k] - '0';
                k++;
            }

              // Attempt to encode the note

            char encodedNote = encodeNote(octave, noteLetter, accidentalSign);

              // An unplayable note makes the song unplayable

            if (encodedNote == ' ')
            {
                badBeat = beatNumber;
                return RET_UNPLAYABLE_NOTE;
            }

                // If there's another note in this beat, it's a chord

            if (song[k] != END_OF_BEAT  &&  noteCount == 1)
                result += '[';

            result += encodedNote;
        }

            // If beat had a chord, close it off

        if (noteCount > 1)
            result += ']';

            // Advance past end of beat marker

        k++;
    }

      // We've successfully encoded the entire song, so set instructions.

    instructions = result;

    return RET_OK;
}

//*************************************
//  encodeNote
//*************************************

// Given an octave number, a note letter, and an accidental sign, return
// the character that the indicated note is encoded as if it is playable.
// Return a space character if it is not playable.
//
// First parameter:   the octave number (the integer 4 is the number of the
//                    octave that starts with middle C, for example).
// Second parameter:  an upper case note letter, 'A' through 'G'
// Third parameter:   '#', 'b', or ' ' (meaning no accidental sign)
//
// Examples:  encodeNote(4, 'A', ' ') returns 'Q'
//            encodeNote(4, 'A', '#') returns '%'
//            encodeNote(4, 'H', ' ') returns ' '

char encodeNote(int octave, char noteLetter, char accidentalSign)
{
      // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** encodeNote was called with first argument = "
             << octave << endl;
    }

      // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
      //      to -1, 0,   1,   2,   3, ...,  11, 12

    int note;
    switch (noteLetter)
    {
      case 'C':  note =  0; break;
      case 'D':  note =  2; break;
      case 'E':  note =  4; break;
      case 'F':  note =  5; break;
      case 'G':  note =  7; break;
      case 'A':  note =  9; break;
      case 'B':  note = 11; break;
      default:   return ' ';
    }
    switch (accidentalSign)
    {
      case '#':  note++; break;
      case 'b':  note--; break;
      case ' ':  break;
      default:   return ' ';
    }

      // Convert ..., A#1, B1, C2, C#2, D2, ... to
      //         ..., -2,  -1, 0,   1,  2, ...

    int sequenceNumber = 12 * (octave - 2) + note;

    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}
