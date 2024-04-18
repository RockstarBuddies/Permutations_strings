word = input("Enter a word: ")

L = [(word, '')]

while L:
    current_word, current_permutation = L.pop()

    if len(current_word) == 0:
        print(current_permutation)
    else:
        used_chars = set()
        for i in range(len(current_word)):
            if current_word[i] not in used_chars:
                used_chars.add(current_word[i])
                new_word = current_word[:i] + current_word[i+1:]
                new_permutation = current_permutation + current_word[i]
                L.append((new_word, new_permutation))
