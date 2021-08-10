import json
import urllib.request
from bs4 import BeautifulSoup
# from pywinauto import Application
import os
import sys 

if(len(sys.argv) < 4):
	exit()
else:
	problem = sys.argv[1]
	url = sys.argv[2]
	filename = sys.argv[3] + ".cpp__tests"

if( url.find('https://codeforces.com/') == -1):
	exit()
else:
	try:
		page = urllib.request.urlopen(url, timeout=20)
	except:
		print("Couldn't parse", problem+".cpp__tests")
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

res = res.split('Input\n')
out = out.split('Output\n')

res.remove("")
out.remove("")

out = [elements.strip() for elements in out]

correct = []
for elements in  out:
	correct.append([elements])

final = []
sz = len(res)

for i in range(sz):
	dic = {
		"test" : res[i],
		"correct_answers" : correct[i]
	}
	final.append(dic) 


with open(filename, "w") as outfile: 
    outfile.write(json.dumps(final)) 

print("Parsed", problem+".cpp__tests")