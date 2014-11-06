#!/usr/bin/python

"""Given a string, find the longest substring that contains at most
   2 distinct characters.
   Example: "ababcbcbaaabbdef"
   has a 2-character substring "baaabb" of length 6 (longest)
   and a 2-character substring "bcbcb" of lenght 5 (second longest)"""

def LongestSubstringWithTwoChars(input):
  l = len(input)
  if l < 2:
    return False, ""

  sp1 = 0
  sp2 = 1
  while sp2 < l and input[sp1] == input[sp2]:
    sp2 += 1
  if sp2 == l:
    return False, ""

  ap1 = sp1
  sl = 1
  while sp1 < l:
    c1 = input[sp1]
    c2 = input[sp2]
    sp2 += 1
    while sp2 < l and (input[sp2] == c1 or input[sp2] == c2):
      sp2 += 1
    if (sp2 - sp1) > sl:
      ap1 = sp1
      sl = sp2 - sp1
    if sp2 == l:
      break

    sp1 = sp2 - 1

  result = ""
  for i in range(0, sl):
    result += input[ap1 + i]

  return True, result

def main():
  input = "ababcbcbaaabbdef"
  find, result = LongestSubstringWithTwoChars(input)
  if find:
    print result
  else:
    print "Not found"

if __name__ == "__main__":
  main()
