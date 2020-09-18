# Longest_Compound_Word

## Problem Statement
Write a program that:
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file
   1 .longest compounded word
    2. second longest compounded word
    3. time taken to process the input file
  ### Solution
  Here I am using the tries data structure.
  ![alt text](https://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Text/FIGS/Trie/trie02.gif)
  
  ##### source http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Text/trie01.html
  
  #### 1. Creating a tries class and inserting words.
    Used a hash table for alphabletic words of size 26. Also using wordend to show that word has been ended.
    For every letter in a word we are creating a new tries if not already created. Every letter is expressed in tries as (tries->hash[word[index]-97]).
    
    The time complexity for insertion is O(|W|*N). As the length of words is small as compared to number of words the time can be approximated to O(N)
    
#### 2. Creating a function for finding the largest compound word
      Created a function which will return True if the given word is a compound word. What makes it give largest compound word is that I sorted the  words
      in accordance to length of words in decreasing order. 
      So the first word which returns true will be the largest compound word. 
      The function works as when a word is given it will try to find a prefix. If no prefix found it will return false. Otherwise, if a prefix is found the 
      other part of the word is checked whether it is a valid word or a compound word or not a valid word.
      The functions try all possible prefixes to check if it is compound word. 
      The time complexity of this function is most difficult to find.  The worst case according to me will be O((2^k)*N)
#### 3. Sorting the words according to length
      The words are sorted and stored according to their length. The time cmplexity is O(N).
 After sorting run a for lop from the largest to smallest word and applying longest cmpund word function. When it returns two strings then break the function.
      
    
    
