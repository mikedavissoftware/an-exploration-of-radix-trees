# Radix Trees: An Exploration
### Utilizing radix trees to index and count the frequency of certain words & tokens
by Mike Davis

<hr/>

### Overview

As a student in University of Colorado at Boulder's Computer Science Post-Baccalaureate program, I am required to take CSPB 2270: Data Structures. This class covers a wide variety of data structures, including linked lists, binary search trees, hashes, graphs, and others. During the class, I applied these data structures using C++, which is a mid-level hybrid coding language that combines aspects of high-level and low-level languages. Some aspects of C++ are:

#### Low-Level:

- Compiles directly to machine code, the only middleman for which is the compiler itself
- Can manage memory usage directly, by having direct access to system hardware

#### High-Level:

- Has a standard library of built-in functionalities that aid programming
- Includes elements of object-oriented programming, such as classes & inheritance

Building projects in C++ was great for my understanding of software development as a whole, since it exists closer to where the rubber meets the road. As the final project for CSPB 2270, I am building a radix tree in C++ to index words and their frequencies, as well as other metadata (_see Proposal_). This project is a testament to what I can build using this language after two semesters of working with it.



<hr/>

### Project Prompt

This is a choose-your-own-adventure exploration of a data structure or algorithm of your own choosing. Have fun with this!

The purpose of the project is for you to work on an interesting problem that is related to data structures and algorithms, and dive in as deep as you want. There is no head trip here - there isn't a prescribed format, and the definition of "data structure or algorithm" is pretty broad.

1. Pick a data structure or algorithm that you think is interesting. The only rule is you must avoid the things that we've done for homework assignments. You could augment one of them (e.g. circular linked lists) or choose a related thing (e.g. 3-2 trees, B-Trees are similar to binary trees). Or you could peruse Wikipedia's List O' Data StructuresLinks to an external site. or even find a groovy idea that isn't on that list at all

2. Write a little proposal with an intended audience of your peers. Keep it under 800 words (use a tool like wordcounter.netLinks to an external site. if you need help). It is very important that you write this clearly, without assuming that your reader has full context into your thinking. Give us a good motivation, explain the data structure and/or algorithm you're going to use, and why that's an interesting application. If you see any technical or learning hurdles, you can put those in there too. Your motivation can be as simple as "computer graphics are cool, so I wanted to explore Delaunay triangulation". You'll turn this into Canvas

3. You'll receive two to three randomly assigned proposals from your peers, and you'll give feedback and grade other student work. (Keep this in mind when you write your proposal!)

4. You will be able to take the feedback and incorporate it as you see fit. You have no obligation to heed any advice or even read the feedback, but I bet it will be useful. Remember, your peers are putting effort into writing it.

5. Do your project! You must do your project in C++. Subject your project along with supporting materials. Last semester, many students made informal videos along the lines of a desk demo.

6. The grading rubric is straightforward. It is subjective, and does not involve us running the project locally. There are no unit tests to pass. Instead, we'll read or watch your walkthrough, look at the screenshots of the UI or console session, and poke around in the code.
- For a C: turn something in that shows you made an attempt, and has an identifiable data structure and/or algorithm
- For a B: Same as C, and shows that you went fairly deep into the work and were able to document some of the challenges you encountered.
- For an A-: Same as B, with polish. The walkthrough is easy to understand, the code is well-organized and demonstrates competence at the medium.
- For an A: Same as A-, and you really really impressed us.

#### What to submit:

If your proposal is just text, you can paste it into the text box. If it involves images, make a PDF and upload that.

#### Providing feedback:

You will receive two to three randomly assigned proposals from your peers, and you'll give feedback on these. This will contribute to their grade, so be fair and honest.

Make sure you spend enough time to read your classmates' proposals and answer the assessment questions appropriately.

You must leave a reason for your choices in your review as feedback to your classmate and instructors.

#### Receiving feedback:

When you get feedback from your peers, consider incorporating it into your work.

#### Due Dates:

Project Proposal Due: Nov 11 by 11:59 PM
Peer Feedback Due: Nov 16 by 11:59 PM



<hr/>

### My Proposal

#### Objective

In this project, I want to explore the utility of radix trees in storing word counts for text documents. Overall the objective is going to be to compare the savings in memory space in creation of the tree, as well as time in the process of searching for word counts, utilizing the fact that a lot of words share certain tokens and suffixes. The radix tree will be compared to a regular prefix tree, to compare the efficiencies with the same inputs. I believe this tool can be expanded to include metadata about certain words if they are in need of definition in a separate glossary.

#### Background

I have become fascinated by indexing of specific words (which are a form of token) since becoming a programmer. Since so much of AI is based on parsing text in efficient ways, I would love to create something that parses a word document and counts the words, storing these word counts in an efficient tree structure, for easy access.

#### Proposed Solution

My project will create two tree structures of nodes and compare them. These nodes will each contain four things:

- A string of the next character(s)
- An integer of the count of the word if it were to end with this character(s)
- A boolean indication whether that word is capitalized
- A map of string-pointer pairs that contains the pointers to the next letters.

The construction of these trees will be accomplished by parsing the word document, taking each word and checking through the tree until the final letter is reached, and incrementing the word counter at that node.

As mentioned above, I will be using a radix tree, which will be a tree with an unrestricted number of children. This data structure will be suitable because it will allow flexibility in tokenizing the remainder of certain words, which will reduce the time in traversal and also memory space.

#### Challenges

The tough part in this project will likely be adjusting the maps each time there is a new breakout for when a letter differs from the previous one, for a string of multiple letters. This will require deleting the key-value pair from the map, and revising that map by creating a split for the different suffixes. This will require adding two nodes to the map to account for the split, and this could potentially be a tricky process in terms of managing memory.

#### Expected Outcomes

I will measure success for this project by looking at the gains in efficiency from the simple prefix tree to the radix tree, as well as the sheer accuracy and functional expandability of the final word indexing. I will be able to parse a document, search a word for its word count, and view other metadata I might choose to loop into these nodes.

#### References

- I plan to come back to Wikipedia for inspiration and review, first and foremost.

- There is also a good breakdown of radix sort by someone on Medium I plan to reference as well: [Unleashing the Potential of Radix Tree](https://ankitpandeycu.medium.com/unleashing-the-potential-of-radix-tree-35e6c5d3b49d)

- And, as always, I will certainly brush up on any weak aspects of my coding by reviewing at W3 Schools, which has been a mainstay for me throughout my programming career.

<hr/>

### Explanation of the Final Product

My overall goal with this project was to gain memory efficiency by eliminating layers of the tree when there is a shared infix (string of characters at any point in a word) that can eliminate individual branches. This goal became more clear as the project went along, as is usually the case when you get into the weeds of code. Essentially, I was building a compressed version of a suffix tree, with the added depth of having a word counter and parent node pointers. My suspicion is that this approach might take more computation than a regular suffix tree (single characters), but less memory space. I could see this being useful in the creation of my own local LLM, where I feed it only the data I would like it to pull from.

I intended to build a test suite that proved this in metrics, but I didn't allot myself enough time to do so before submission. I still built a test suite, however. Beyond exploring the data structure, this project was a great exercise in that, which I have done before in Ruby, but not in C++.

Now to the details:

Since there are only 26 letters in the English alphabet, and my input string will be in English, it follows that there will be a maximum number of 26 child nodes for any given node. These children will be stored in a map, with the keys being that first letter (in the form of a char), and the value being a pointer to the node that contains the next infix & other data.

I started off with pen and paper, parsing an example string word by word. This led me to create a simple radix tree, in which there was an unlimited number of children per string. Each time a word came up that shared a letter or prefix with a child node, another branch was created to keep track of the words. And, once the end of a word was reached, the current node would be incremented by one, thus adding to the count of that particular word.

With regards to the benefits of this approach, this project will reduce the redundancy of having nodes for absolutely every letter, by tokenizing different infixes throughout the tree.

A lot of the challenges I encountered were with conversions between string type and char type, but once I got those figured out, it wasn't too difficult getting to the point of my submission. I found that building my tests piece-by-piece was very helpful in building the functions themselves. It helped break the steps down and think from the big picture of inputs and outputs - sort of turned this thing into a black box, which is the goal in the end.

<hr/>

### To Run

Navigate to /build folder and run:
```cmake ..```
```make```
```./run_tests```