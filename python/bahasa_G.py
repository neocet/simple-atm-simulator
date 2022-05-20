## Program python untuk mengubah kalimat ke dalam bahasa G ##


def split_n_cons(sentence, char):
    """ Fungsi untuk memisahkan kalimat berdasarkan huruf 
        vokal lalu menggabungkan kembali kalimat tersebut
        dengan sisipan "<huruf vokal><g><huruf vokal>"
    """

    segment = sentence.split(char)      # Memisahkan kalimat berdasarkan character
    if 65 <= ord(char) <= 90:           # Jika character termasuk huruf kapital
        # Mengabungkan kalimat dengan sisipan "<char><g><char>"
        joined_segment = (char + 'g' + char.lower()).join(segment)  # .lower() untuk mengubah menjadi huruf kecil
        return joined_segment
    
    low = char.lower()                  # Mengubah character menjadi huruf kecil

    # Mengabungkan kalimat dengan sisipan "<char><g><char>"
    joined_segment = (low + 'g' + low).join(segment)
    return joined_segment


# Membuat list yang berisi huruf vokal
vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

# Mengambil input kalimat dari user
sentence = input("Input Kalimat: ")

# Looping ke semua elemen list untuk memisah dan
# menggabungkan kalimat berdasarkan huruf vokal
for vowel in vowels:
    sentence = split_n_cons(sentence, vowel)

# Output bahasa G
print(f"Bahasa G:\n{sentence}")
