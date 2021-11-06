# Plagiarism
Core Logic

A K-gram based model for computing code similarity matrix capable of auto detecting keywords and base file snippets. Specialized for C++, the model is generalized for any language. As the logical part (example arithematic/logical operations) of code contributes the most towards score, the model is able to make accurate computations invariant of base file code and various plagiarism tactics.
The Algorithm

    Keyword detection: The programme traverses through a number of file in the batch and computes the document frequency of each frequency of each word it traverses. Then selects the top 25 words with highest doc-frequency as keywords.
    Preprocessing: This involves
        Removing Comments
        Removing Keywords
        Tokenising variable/function names
    K-gram modelling: The preprocessed string is then used to compute the set containing all k-grams of the string, which is the representative of a code
    Score: For a pair of File, the number of matching K-grams multiplied by a normalizing factor gives the similarity score.
Features

    Invariant to nomenclature of variables/functions
    Robust against keyword swapping (Eg int to long; for to while)
    Autodetects Basefile
    Autodetects Keywords from test Data using Document Frequency scores
    Robust against code shuffling

