import os
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
# import numpy as np

files = [open(os.path.join("Assignment_5",file)).read() for file in os.listdir("Assignment_5")]

# print(len(files))
vectorizer = TfidfVectorizer()
vectorize = lambda file: vectorizer.fit_transform(file).toarray()

similarity = lambda fil1, fil2: cosine_similarity([fil1, fil2])
vectors = vectorize(files)
print(vectorizer.get_feature_names())
# print(len(vectors[0]))
# s_vectors = list(zip(files, vectors))
# def check_plagiarism():
#     plagiarism_results = set()
#     global s_vectors
#     for i, j in s_vectors:
#         new_vectors =s_vectors.copy()
#         current_index = new_vectors.index((i, j))
#         del new_vectors[current_index]
#         for a , b in new_vectors:
#             sim_score = similarity(j, b)[0][1]
#             student_pair = sorted((i, a))
#             score = (student_pair[0], student_pair[1],sim_score)
#             plagiarism_results.add(score)
#     return plagiarism_results
# for data in check_plagiarism():
#     print(data)

