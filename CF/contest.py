import json
import urllib.request
from bs4 import BeautifulSoup
import os
import subprocess

url = input("Enter Contest Id : ")
url = "https://codeforces.com/contest/" + url
if(url.find('https://codeforces.com/contest') == -1):
	print("Invalid Url")
	exit()
else:
	page = urllib.request.urlopen(url, timeout=20)
soup = BeautifulSoup(page, features = "html.parser")

data = []

table = soup.find('table', attrs={'class':'problems'})

rows = table.find_all('tr')
for row in rows:
	cols = row.find_all('td')
	cols = [ele.text.strip() for ele in cols]
	data.append([ele for ele in cols if ele])

problem_tags = []
for i in range(len(data)):
	if(len(data[i])>0):
		problem_tags.append(data[i][0])

print(problem_tags)

contest_id = url[-4] + url[-3] + url[-2] + url[-1]
path = contest_id
parent_dir = os.getcwd()

path = os.path.join(parent_dir,path)
if not os.path.exists(path):
	os.mkdir(path)

x = url + '/submit'
subprocess.run(["firefox", x], stdout=subprocess.DEVNULL)
x = url + '/standings/friends/true'
subprocess.run(["firefox", x], stdout=subprocess.DEVNULL)


for problems in problem_tags:
	problem_path = os.path.join(path,problems)
	print(problem_path)
	with open(problem_path+".cpp", "a") as sec:
		pass
	problem_url = " " + url + "/problem/" + problems + " \"";
	os.system('python automate.py' + problem_url + problem_path + "\"")
	x = url + '/problem/' + problems
	subprocess.run(["firefox", x], stdout=subprocess.DEVNULL)

subprocess.run(["subl", path], stdout=subprocess.DEVNULL)


# for firefox users
# # for linux
# os.system('firefox ' + url + '/submit & disown')
# os.system('firefox ' + url + '/standings/friends/true & disown')
# # for windows : you don't need "& disown"
# # os.system('firefox ' + url + '/submit')
# # os.system('firefox ' + url + '/standings/friends/true')


# for problems in problem_tags:
# 	problem_path = os.path.join(path,problems)
# 	print(problem_path)
# 	with open(problem_path+".cpp", "a") as sec:
# 		pass
# 	problem_url = " " + url + "/problem/" + problems + " \"";
# 	os.system('python automate.py' + problem_url + problem_path + "\"")
# 	# for linux
# 	os.system('firefox ' + url + '/problem/' + problems + ' & disown')
# 	# for windows : you don't need "& disown"
# 	# os.system('firefox ' + url + '/problem/' + problems)

# os.system('subl ' + path)