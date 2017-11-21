# I want to learn some big words so people think I'm smart

## Problem Description

I opened up a dictionary to a page in the middle and started flipping through, looking for words I
didn't know. I put each word I didn't know at increasing indices in a huge array I created in memory.
When I reached the end of the dictionary, I started from the beginning and did the same thing until
I reached the page I started at.

Now I have an array of words that are mostly alphabetical, except they start somewhere in the
middle of the alphabet, reach the end, and then start from the beginning of the alphabet. In other
words, this is an alphabetically ordered array that has been "rotated."

For Example:

    const char *words[11] = {
        "ptolemaic",
        "retrograde",
        "supplant",
        "undulate",
        "xenoepist",
        "asymptote",  // <-- rotates here!
        "babka",
        "banoffee",
        "engender",
        "karpatka",
        "othellolagkage"
    };

Write a function for finding the index of the "rotation point," which is where I started working from
the beginning of the dictionary. This array is huge (there are lots of words I don't know) so we want
to be efficient here.

## Gotchas

We can get O(lgn) time.

## Breakdown

The array is mostly ordered. I should take advantage of that.

A common algorithm that takes advantage of the fact that an array is sorted to find an item
efficiently is binary search.

I can write an adapted version of binary search for this.

There's a little problem though. In each iteration of my binary search, how do I know if the rotation
point is to the left or to the right? I will try drawing out an example array.


    ["k","v","a","b","c","d","e","g","i"]

If my "current guess" is the middle item, which is 'c' in this case, is the rotation point to the left or to
the right?

I notice that every item to the right of my rotation point is always alphabetically before the first item


in the array.

So the rotation point is to my left if the current item is less than the first item. Else it's to my right.

## Solution

    size_t findRotationPoint(const char **words, size_t length)
    {
        const char *firstWord = words[0];
        size_t floorIndex = 0;
        size_t ceilingIndex = length - 1;

        while (floorIndex < ceilingIndex) {
            // guess a point halfway between floor and ceiling
            size_t guessIndex = floorIndex + ((ceilingIndex - floorIndex) / 2);
            int cmp = strcmp(words[guessIndex], firstWord);

            // if guess comes after first word or is the first word
            if (cmp >= 0) {
                // go right
                floorIndex = guessIndex;
            }
            else {
                // go left
                ceilingIndex = guessIndex;
            }

            // if floor and ceiling have converged
            if (floorIndex + 1 == ceilingIndex) {

                // between floor and ceiling is where we flipped to the beginning
                // so ceiling is alphabetically first
                break;
            }
        }

        return ceilingIndex;
    }

This is a modified version of binary search. At each iteration, I go right if the item I'm looking at is
greater than the first item and I go left if the item I'm looking at is less than the first item.

I keep track of the lower and upper bounds on the rotation point, calling them floorIndex and
ceilingIndex (initially I called them "floor" and "ceiling," but because I didn't imply the type in the
name I got confused and created bugs). When floorIndex and ceilingIndex are directly next to each
other, I know the floor is the last item I added before starting from the beginning of the dictionary,
and the ceiling is the first item I added after.

## Complexity

Each time I go through the while loop, I cut our range of indices in half, just like binary search. So I
have O(lgn) loop iterations.

In each loop iteration, I do some arithmetic and a string comparison. The arithmetic is constant
time, but the string comparison requires looking at characters in both words—every character in
the worst case. Here, I will assume my word lengths are bounded by some constant so I will say the
string comparison takes constant time.

For example, one of the longest words in English is "pseudopseudohypoparathyroidism", which is a
medical term. It's 30 letters long.

Putting everything together, we do O(lgn) iterations, and each iteration is O(1) time. So our time
complexity is O(lgn).

In other words, we could say that the length of a word is "l", each string comparison takes O(l) time,
and the whole algorithm takes O(l*lgn) time.

We use O(1) space to store the first word and the floor and ceiling indices.

## What We Learned

The answer was a modified version of binary search.

This is a great example of the difference between "knowing" something and really knowing
something. We might have seen binary search before, but that doesn't help us much unless we've
learned the lessons of binary search.

### Binary search teaches us that when an array is sorted or mostly sorted:

* The value at a given index tells us a lot about what's to the left and what's to the right.

* We don't have to look at every item in the array. By inspecting the middle item, we can "rule out" half of the array.

* We can use this approach over and over, cutting the problem in half until we have the answer.

This is also known as "divide and conquer".

So whenever we know an array is sorted or almost sorted, we have to think about these lessons from binary search and see if they apply.


