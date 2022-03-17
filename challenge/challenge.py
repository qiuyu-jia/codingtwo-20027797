from translate import Translator

Translator = Translator(from_lang="chinese",to_lang="english")
from_file = r'/Users/jiaqiuyu/project/one.txt'
to_file =r'/Users/jiaqiuyu/project/two.txt'
word_list=[]

with open(from_file)as file_object:
    lines=file_object.readlines()
    for line in lines:
        translate_words= Translator.translate(line)
        word_list.append(translated_words)

new_words="\n".join(word_list)

with open(to_file,"w")as myfile:
    myfile.write(new_words)

print("well done")    