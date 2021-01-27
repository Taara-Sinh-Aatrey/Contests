import json
import urllib.request
from bs4 import BeautifulSoup
# from pywinauto import Application
import webbrowser
import os

url = input()
url = url + "/tasks"
req = urllib.request.Request(url, headers={'User-Agent': 'Mozilla/5.0'})
page = urllib.request.urlopen(req)
soup = BeautifulSoup(page, features = "html.parser")

data = []

table = soup.find('table')

rows = table.find_all('tr')

for row in rows:
	cols = row.find('td')
	if(cols):
		cols = [ele.text.strip() for ele in cols]
		data.append([ele for ele in cols if ele])

problem_tags = []

for i in range(len(data)):
	if(len(data[i])>0):
		problem_tags.append(data[i][0][0])

print(problem_tags)

contest_id = url[-12] + url[-11] + url[-10] + url[-9] + url[-8] + url[-7]
path = contest_id.upper()
parent_dir = os.getcwd()

path = os.path.join(parent_dir,path)
if not os.path.exists(path):
	os.mkdir(path)

for problems in problem_tags:
	problem_path = os.path.join(path,problems)
	print(problem_path)
	with open(problem_path+".cpp", "a") as sec:
		pass
	problem_url = " " + url +  "/" + contest_id + "_" + problems.lower() + " \"";
	os.system('python atcoder_automate.py' + problem_url + problem_path + "\"") 

os.system('subl ' + path)
