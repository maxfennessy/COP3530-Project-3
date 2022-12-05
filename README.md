Team Name: Group 134
Team Members: Max Fennessy, Sam Glickman
Project Title: WordWiz
Problem: What problem are we trying to solve? [0.25 point]
 We are trying to analyze the amount of similarity between words to be able to provide a list of those with the most similarity when a user prompts the application with a word. More specifically, we want users to be able to add criteria to what the output should have, so the application will return the words with the highest similarity that meets these criteria. The criteria may include factors such as starting letters, ending letters, or length.
Motivation: Why is this a problem? [0.25 point]
In both creative and professional forms of writing, sometimes the writer in question is looking for a word that conveys a certain meaning but also has a specific property (i.e. length, syllable count, beginning letter, etc.). A thesaurus can provide full synonyms for the word, but unless one is seen quickly, the search may take a while or be completely fruitless if there’s no perfect synonym which meets the property. Having an application which gives the first words to do this would greatly reduce the time and effort needed to find the best word to meet this goal. Possible uses both for professional settings and fun include finding a form of some word to make a rhyming pair, keeping a writing more concise with shorter words, finding words beginning with a certain letter to match an acronym, or just using as a thesaurus if no specific criteria is added.
Features: When do we know that we have solved the problem? [0.25 point]
When we have solved the problem, the application will be able to take in an English word in, as well as any of the criteria we set, and return a list of a few of the most similar which match the criteria. Checking that the word matches the given limitations is objective, and so running tests to see that it does such will be easy. It is more subjective to determine if the words returned are truly the most related, but trying the algorithms without any constraints and seeing how it compares to general thesauruses will be a good way to know if similarity is being analyzed accurately.
Data: (Public data set we will be using and the link to the public data set) or (Schema of randomly generated data - i.e. what are the different columns in our dataset and the respective data types) [0.25 point]
English Word Dataset Synonyms and Antonyms - https://www.kaggle.com/datasets/dsk80004/nlp-english-word-dataset-synonyms-and-antonyms
Tools: Programming languages or any tools/frameworks we will be using [0.25 point]
C++
Word2vec (a tool used for analyzing word’s relation for natural language processing) https://www.tensorflow.org/tutorials/text/word2vec
Strategy: Preliminary algorithms or data structures you may want to implement and how would you represent the data [0.25 points]
Graph - Each vertex is a word with edges between similar words and weights based on similarity
Heap - Priority is set to value of relativity
Distribution of Responsibility and Roles: 
Max Fennessy: video, heap
Sam Glickman: graph, report
References 
https://www.kaggle.com/datasets/dsk80004/nlp-english-word-dataset-synonyms-and-antonyms 
	https://www.tensorflow.org/tutorials/text/word2vec
https://towardsdatascience.com/how-to-compute-word-similarity-a-comparative-analysis-e9d9d3cb3080
