import json
import urllib.request
from bs4 import BeautifulSoup
# from pywinauto import Application
import os
import sys 

if(len(sys.argv)<3):
	exit()
else:
	url = sys.argv[1]
	filename = sys.argv[2] + ".cpp__tests"

if( url.find('https://codeforces.com/') == -1):
	with open("solution.cpp__tests", "w") as outfile:
		outfile.write('Please open a problem page')
	exit()
else:
	try:
		page = urllib.request.urlopen(url, timeout=20)
	except:
		print(url)
		exit()
soup = BeautifulSoup(page, features = "html.parser")

x = soup.body.find_all('div', attrs={'class' : 'input'})
y = soup.body.find_all('div', attrs={'class' : 'output'})

res = ""
out = ""

for elements in x:
	t = elements.text
	if t[5] != '\n':
		t = t[:5] + '\n' + t[5:]
	res += t
for elements in y:
	t = elements.text
	if t[6] != '\n':
		t = t[:6] + '\n' + t[6:]
	out += t

# print(res)
# print(out)


res = res.split('Input\n')
out = out.split('Output\n')

# print(res)
# print(out)

res.remove("")
out.remove("")

#res = [elements.strip() for elements in res]
out = [elements.strip() for elements in out]

correct = []
for elements in  out:
	correct.append([elements])

final = []
sz = len(res)

for i in range(sz):
	dic = {
		"correct_answers" : correct[i],
		"test" : res[i]
	}
	final.append(dic) 


with open(filename, "w") as outfile: 
    outfile.write(json.dumps(final)) 