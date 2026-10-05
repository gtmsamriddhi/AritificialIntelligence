import nltk

# Download required NLTK data
nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('stopwords')
nltk.download('wordnet')
nltk.download('averaged_perceptron_tagger')
nltk.download('averaged_perceptron_tagger_eng')

from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer

text = "Natural Language Processing is interesting. It helps computers understand human language."

# 1. Sentence Tokenization
sentences = sent_tokenize(text)
print("Sentence Tokenization:")
print(sentences)

# 2. Word Tokenization
words = word_tokenize(text)
print("\nWord Tokenization:")
print(words)

# 3. Stop Word Filtering
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in words if word.lower() not in stop_words]

print("\nAfter Stop Word Removal:")
print(filtered_words)

# 4. Word Stemming
stemmer = PorterStemmer()
stemmed_words = [stemmer.stem(word) for word in filtered_words]

print("\nWord Stemming:")
print(stemmed_words)

# 5. POS Tagging
pos_tags = nltk.pos_tag(words)

print("\nPOS Tagging:")
print(pos_tags)
print("Samriddh Gautam: BIT28: LabIV5")