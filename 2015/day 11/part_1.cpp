#include <iostream>
#include <string>

std::string get_next_pw (std::string);
bool is_valid_pw (std::string);
int custom_alphabet (char);

int main () {
    std::string pw = "hxbxxyzz";
    while (true) {
      pw = get_next_pw(pw);
      if (is_valid_pw(pw)) {
          std::cout << "the next valid pw is: " << pw << "\n";
          break;
      }
      std::cout << "failed pw: " << pw << "\n";
    }
    return 0;
}

std::string get_next_pw (std::string old_pw) {
  std::string new_pw = "";
  bool keep_going = true;

  for (std::string::reverse_iterator it=old_pw.rbegin(); it != old_pw.rend(); ++it) {
    // std::cout << *it << "\n";
    if (keep_going && *it != 'z') {
      new_pw = ((char) (*it + 1)) + new_pw;
      keep_going = false;
    } else if (keep_going) {
      new_pw = 'a' + new_pw;
    } else {
      new_pw = *it + new_pw;
    }
  }
  return new_pw;
}

bool is_valid_pw (std::string pw) {
  bool atleast_1_lex_progression = false;
  int atleast_2_nonoverlapping_pairs = 0;
  char last_char_for_pair = '\0';

  if (pw.length() != 8) {
    //std::cout << "failed becasue of length" << "\n";
    return false;
  }

  int pos = 0;
  for (std::string::iterator it=pw.begin(); it != pw.end(); ++it) {
    if (*it == 'i' || *it == 'o' || *it == 'l') { // check for illegal chars
      //std::cout << "failed becasue of illegal chars" << "\n";
      return false;
    }

    if (pos != 0) { // check for non-overlapping pairs
      if (pw[pos - 1] == pw[pos] && pw[pos] != last_char_for_pair) {
        atleast_2_nonoverlapping_pairs++;
        last_char_for_pair = pw[pos];
        // std::cout << "pair found: " << pw[pos -1] << pw[pos] << "\n";
        // std::cout << "pairs found so far: " << atleast_2_nonoverlapping_pairs << "\n";
      }
    }

    if (pos >= 2) { // check for lexicographic progression with a window of size 3
      if (custom_alphabet(pw[pos]) - custom_alphabet(pw[pos - 1]) == 1 && custom_alphabet(pw[pos - 1]) - custom_alphabet(pw[pos - 2]) == 1) {
        atleast_1_lex_progression = true;
      }
    }

    pos++;
  }

  if (!atleast_1_lex_progression) {
    // std::cout << "failed becasue of no progression" << "\n";
  }

  if (atleast_2_nonoverlapping_pairs < 2) {
    // std::cout << "failed becasue of no pairs, pairs found: " << atleast_2_nonoverlapping_pairs << "\n";
  }

  return atleast_1_lex_progression && (atleast_2_nonoverlapping_pairs >= 2);
}

int custom_alphabet (char c) {
  if (c > 'i') {
    return (int) c - 1;
  } else if (c > 'o') {
    return (int) c - 2;
  } else if (c > 'l') {
    return (int) c - 3;
  }

  return (int) c;
}
