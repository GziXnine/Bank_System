/*
 * ============================================================================
 * Validation.cpp — Implementation skeleton for Validation utility
 * ============================================================================
 *
 * HINT: For isAlphabetic, you can use std::isalpha() from <cctype>
 * to check each character. Remember to handle spaces — a name like
 * "Ahmed Ali" has a space, which is technically not alphabetic.
 * Decide: Allow spaces in names or not? The requirements say
 * "alphabetic chars" — clarify with your instructor.
 *
 * ============================================================================
 */

#include "Validation.h"
#include <cctype>

using namespace std;

bool Validation::isValidName(const string &name)
{
  if (name.length() < 5 || name.length() > 20)
    return false;

  return isAlphabetic(name);
}

bool Validation::isValidPassword(const string &password)
{
  return (password.length() >= 8 && password.length() <= 20);
}

bool Validation::isValidBalance(double balance)
{
  return balance >= 1500.0;
}

bool Validation::isValidSalary(double salary)
{
  return salary >= 5000.0;
}

bool Validation::isValidAmount(double amount)
{
  return amount > 0.0;
}

bool Validation::isAlphabetic(const string &str)
{
  if (str.empty())
    return false;

  bool hasAlpha = false;
  for (unsigned char c : str)
  {
    if (!std::isalpha(c) && c != ' ')
      return false;

    if (std::isalpha(c))
      hasAlpha = true;
  }

  return hasAlpha;
}
