# US_Reading_Readability_Check
# Readability

A command-line program written in C (CS50) that estimates the reading grade level of a piece of text using the **Coleman-Liau index**.

## How It Works

The program prompts the user for a passage of text, then counts:

- **Letters**: every alphabetic character (`a`-`z`, `A`-`Z`)
- **Words**: sequences separated by spaces (word count starts at 1 and increases for each blank)
- **Sentences**: occurrences of `.`, `?`, or `!`

It then computes the Coleman-Liau index:

```
index = 0.0588 * L - 0.296 * S - 15.8
```

where:

- `L` = average number of letters per 100 words
- `S` = average number of sentences per 100 words

The result is rounded to the nearest integer and printed as a grade level.

## Output

| Index        | Output            |
|--------------|-------------------|
| Less than 1  | `Before Grade 1`  |
| 1 to 15      | `Grade N`         |
| 16 or higher | `Grade 16+`       |

## Requirements

- A C compiler (e.g., `clang` or `gcc`)
- The [CS50 library](https://github.com/cs50/libcs50) (`cs50.h`)
- The math library (`-lm`)

## Compile

```bash
clang -o readability readability.c -lcs50 -lm
```

Or, in the CS50 environment:

```bash
make readability
```

## Usage

```bash
./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

## Code Structure

| Function                 | Purpose                                              |
|--------------------------|------------------------------------------------------|
| `main`                   | Reads input, computes the index, prints the grade    |
| `count_letters(string)`  | Counts alphabetic characters using `isalpha`         |
| `count_words(string)`    | Counts words by counting blanks via `isblank` (+1)   |
| `count_sentences(string)`| Counts `.`, `?`, and `!` characters                  |

## Notes

- Words are detected by spaces/tabs only, so the text should use single spaces between words.
- Sentence endings are limited to `.`, `?`, and `!`.
- Counters are declared as `float` to keep the division precise; they could also be `int` and cast during the calculation.

## Credits

Based on the CS50 *Readability* problem set.
