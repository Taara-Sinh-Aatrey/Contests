import json
import urllib.request
from bs4 import BeautifulSoup
from pywinauto import Application
import os
import sys 

if(len(sys.argv)<=2):
	exit()
else:
	url = sys.argv[1]
	filename = sys.argv[2] + ".cpp__tests"

try:
	page = urllib.request.urlopen(url)
except:
	print(url)
	exit()
soup = BeautifulSoup(page, features = "html.parser")
soup = soup.body.find('span', attrs={'class' : 'lang-en'})
soup = soup.find_all('div', attrs={'class' : 'part'})

res = []
out = []
for cont in soup:
	ele = cont.find('h3')
	if(ele):
		ele = ele.text
		idx = ele.find('Sample Input')
		idy = ele.find('Sample Output')
		if(idx != -1):
			z = cont.find('pre').text.replace("\r", "")
			res.append(z)
		elif(idy != -1):
			z = cont.find('pre').text.replace("\r", "")
			out.append(z)

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
